/*
 * Copyright (c) 2015, George Oikonomou - <george@contiki-os.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/**
 * \file
 *    Project specific configuration defines for the Ubidots demo
 *
 * \author
 *    George Oikonomou - <george@contiki-os.org>,
 */
/*---------------------------------------------------------------------------*/
#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_
/*---------------------------------------------------------------------------*/
/* User configuration */
#define POST_PERIOD                      (CLOCK_SECOND * 30)
#define VARIABLE_BUF_LEN                 16
#define UBIDOTS_CONF_AUTH_TOKEN          "oB6WLGfVlVFq6Vgig1kTuqNhQ5psXH"
#define VARKEY_TEMPERATURE               "56fe8bc07625421d106f5d9f"
#define VARKEY_HUMIDITY                  "570274ec76254271ba937188"
#define VARKEY_ACCEL_X                   "56fe8bd57625421d302181da"
#define VARKEY_ACCEL_Y                   "56fe8bec7625421d4e18f81a"
#define VARKEY_ACCEL_Z                   "56fe8bf47625421e8694cb0e"
#define UBIDOTS_CONF_IN_BUFFER_SIZE      64
/*---------------------------------------------------------------------------*/
#define UBIDOTS_CONF_REMOTE_HOST         "2607:f0d0:2101:39::2"
/*---------------------------------------------------------------------------*/
#undef  NETSTACK_CONF_RADIO
#define NETSTACK_CONF_RADIO              cc2538_rf_driver
#define ANTENNA_SW_SELECT_DEF_CONF       ANTENNA_SW_SELECT_2_4GHZ
#define NETSTACK_CONF_RDC                nullrdc_driver
/*---------------------------------------------------------------------------*/
#define RESOLV_CONF_SUPPORTS_MDNS        0
#define UIP_CONF_MAX_ROUTES              3
#define NBR_TABLE_CONF_MAX_NEIGHBORS     3
/*---------------------------------------------------------------------------*/
#endif /* PROJECT_CONF_H_ */
/*---------------------------------------------------------------------------*/
