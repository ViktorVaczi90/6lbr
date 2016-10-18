/*
 * true2air_prot.c
 *
 *  Created on: Oct 11, 2016
 *      Author: v
 */
#include "true2air_prot.h"
#include <stdio.h>
#include <stdint.h>
#include <stdint.h>
#include "net/ip/uip.h"

#define DEBUG DEBUG_PRINT
#include "net/ip/uip-debug.h"
uint8_t node_initialized = 0;
void root_pkt_reply(rfnode_pkt* pkt_in, rfnode_pkt* pkt_out)
{
	{
		switch(pkt_in->msg){
		case SET_IPADDR:
			pkt_out->msg = SET_IPADDR;
			printf("Received SET_IPADDR!\n");
			break;
		default:
			pkt_out->msg = ERROR_PKT_MSG;
			break;
		}
	}
}
void node_pkt_reply(rfnode_pkt* pkt_in, rfnode_pkt* pkt_out)
{
	if(node_initialized){
		switch(pkt_in->msg){
		case ERROR_PKT_MSG:
			pkt_out->msg = ERROR_PKT_MSG;
			break;
		case SET_IPADDR:
			printf("Node already  initialized!\n");
			pkt_out->msg = ERROR_PKT_MSG;
			break;
		case GET_SENSACT_LIST:
			break;
		case SENSACT_LIST_ACK:
			break;
		case SENSACT_LIST_ITEM:
			break;
		case GET_SENSACT:
			break;
		case SET_SENSACT:
			break;
		case SENSACT_ACK:
			break;
		default:
			pkt_out->msg = ERROR_PKT_MSG;
			break;
		}
	}
	else{ //Node uninitialized
		switch(pkt_in->msg){
		case SET_IPADDR:
			pkt_out->msg = ERROR_PKT_MSG;// Don't answer
			printf("Node initialized!\n");
			node_initialized = 1;
			break;
		default:
			pkt_out->msg = ERROR_PKT_MSG;
			break;
		}
	}
}
int node_is_initialized(){
	return node_initialized;
}
void node_init_pkt(rfnode_pkt* pkt_out){
	pkt_out->msg = SET_IPADDR;
}
void print_pkt_bin(rfnode_pkt* pkt,uip_ip6addr_t* addr){
	int i = 0;
	printf("NEW PACKET!:\n");
	/*for(i = 0; i < sizeof(pkt_msg);i++)	putchar(((char*)&pkt->msg)[i]);
	for(i = 0; i < sizeof(uint8_t);i++)	putchar(((char*)&pkt->cnt)[i]);
	for(i = 0; i < sizeof(uint32_t);i++)putchar(((char*)&pkt->data)[i]);
	for(i = 0; i < 20;i++)				putchar(((char*)pkt->name)[i]);
	for(i = 0; i < sizeof(uint8_t);i++)	putchar(((char*)&pkt->new_device)[i]);*/
	for(i = 0; i<sizeof(rfnode_pkt);i++) putchar(((char*)pkt)[i]);
	for(i = 0; i < sizeof(uip_ip6addr_t);i++) putchar((char*)addr->u8[i]);
	printf("\nEND OF PACKET!\n");
}
void print_pkt(rfnode_pkt* pkt,uip_ip6addr_t* addr){
	printf("NEW PKT!:\npkt->msg:%d\npkt->cnt:%d\n(int)pkt->data:%d\npkt->name:%s\npkt->new_device:%d\n"
			,pkt->msg,pkt->cnt,(int)pkt->data,pkt->name,pkt->new_device);
	PRINT6ADDR(addr);
	printf("\n");
}

