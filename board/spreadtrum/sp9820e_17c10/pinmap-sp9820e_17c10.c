/*This file is created by PINMAP tool
 *Device: SharkLE_SC9820E
 *Version: SC9820_1_IRD_E_SCH_V1.0.0_Pinmap_V1.1_eMMC
 *Creat Time: 2017/7/20 14:09:02
 *Author: 
 */

/*
 * Copyright (C) 2012 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */



#include <asm/io.h>
#include <asm/arch/pinmap.h>
#include <power/sprd_pmic/sprd_2721_pinmap.h>

#define BIT_PIN_SLP_ALL     (BIT_PIN_SLP_AP|BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP|BIT_PIN_SLP_WCN|BIT_PIN_SLP_CM4)
#define BIT_PIN_SLP_ALL_CP  (BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP|BIT_PIN_SLP_WCN|BIT_PIN_SLP_CM4)
#define BIT_PIN_SLP_ALL_NO_CM4  (BIT_PIN_SLP_AP|BIT_PIN_SLP_PUBCP|BIT_PIN_SLP_WTLCP|BIT_PIN_SLP_WCN)


static pinmap_t pinmap[]={
{REG_PIN_CTRL0,0x00000000},
{REG_PIN_CTRL1,0x00000000},
{REG_PIN_CTRL2,0x60400090},//uart1->Digital IO; SPI0->Normal Mode; SPI2->Normal Mode; sim2->AP SIM0; sim1->PUBCP SIM1; sim0->PUBCP SIM0; wci2->inside; aud_iis2->AUD IF; wcn_iis_sys->default value; uart2->TGDSP'UART0; uart1->AP'UART1; uart0->PUBCP'UART0;
{REG_PIN_CTRL3,0x00000000},
{REG_PIN_CTRL4,0x00000000},
{REG_PIN_CTRL5,0x00000000},

{REG_PIN_IIS1DI,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_IIS1DI,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_IIS1DO,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_IIS1DO,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_IIS1CLK,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_IIS1CLK,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_IIS1LRCK,                      BITS_PIN_AF(3)},
{REG_MISC_PIN_IIS1LRCK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SCL2,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SCL2,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C2_SCLI2C??????????
{REG_PIN_SDA2,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SDA2,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C2_SDAI2C??????????
{REG_PIN_CLK_AUX0,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_CLK_AUX0,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NC
{REG_PIN_T_DIG,                         BITS_PIN_AF(3)},
{REG_MISC_PIN_T_DIG,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_GNSS_LNA_EN,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_GNSS_LNA_EN,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_OE},//GPS_LNA_EN??GPSLNA?????
{REG_PIN_EXTINT0,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_EXTINT0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN10????
{REG_PIN_EXTINT1,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_EXTINT1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//FLAG_OUT?USB????????????
{REG_PIN_SCL3,                          BITS_PIN_AF(3)},
{REG_MISC_PIN_SCL3,                     BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN11????
{REG_PIN_SDA3,                          BITS_PIN_AF(3)},
{REG_MISC_PIN_SDA3,                     BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN12????
{REG_PIN_SCL0,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SCL0,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C0_SCLI2C0????,??2M?????Dbgmode0??
{REG_PIN_SDA0,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SDA0,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C0_SDAI2C0????,??2M?????Dbgmode0??
{REG_PIN_SCL1,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SCL1,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C1_SCLI2C1????,??CSItoLVDSLOG??
{REG_PIN_SDA1,                          BITS_PIN_AF(0)},
{REG_MISC_PIN_SDA1,                     BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//I2C1_SDAI2C1????,??CSItoLVDSLOG??
{REG_PIN_CMPD2,                         BITS_PIN_AF(3)},
{REG_MISC_PIN_CMPD2,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CAM_PWDN2?CSItoLVDSLOG???Dbgmode0??
{REG_PIN_CMRST2,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_CMRST2,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_OE},//CAM_RST2?CSItoLVDSLOG???Dbgmode0??
{REG_PIN_CMMCLK0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_CMMCLK0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CAM_MCLK0?2M???
{REG_PIN_CMRST0,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_CMRST0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_OE},//CAM_RST0?2M????Dbgmode0??
{REG_PIN_CMPD0,                         BITS_PIN_AF(3)},
{REG_MISC_PIN_CMPD0,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CAM_PWDN0?2M????Dbgmode0??
{REG_PIN_CMMCLK1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_CMMCLK1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CAM_MCLK1?CSItoLVDSLOG??
{REG_PIN_CMRST1,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_CMRST1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_OE},//CAM_RST1?2M????Dbgmode0??
{REG_PIN_CMPD1,                         BITS_PIN_AF(3)},
{REG_MISC_PIN_CMPD1,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CAM_PWDN1?2M????Dbgmode0??
{REG_PIN_U0TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//BB_U0TXD?Dbgmode0??
{REG_PIN_U0RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BB_U0RXD接Dbgmode0接口
{REG_PIN_U0CTS,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0CTS,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BB_U0CTS接Dbgmode0接口
{REG_PIN_U0RTS,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U0RTS,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_Z},//NFC_WKUP / BB_U0RTS接Dbgmode0接口
{REG_PIN_U1TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U1TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//BB_U1TXD?Test???MicroUSB?ID????TestPoint
{REG_PIN_U1RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U1RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BB_U1RXD?Test???TestPoint
{REG_PIN_U2TXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U2TXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//BB_U2TXD?Dbgmode0?Test??
{REG_PIN_U2RXD,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_U2RXD,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BB_U2RXD?Dbgmode0?Test??
{REG_PIN_EXTINT9,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_EXTINT9,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_EXTINT10,                      BITS_PIN_AF(3)},
{REG_MISC_PIN_EXTINT10,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BUA_BAT_DET??PMU??,??????????????
{REG_PIN_EMMC_D2,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D2,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NFD06_EMMCD2?LPDDR2eMMMC???
{REG_PIN_EMMC_D5,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D5,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NFD04_EMMCD5?LPDDR2eMMMC???
{REG_PIN_EMMC_D1,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D1,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//EMMC_D1?LPDDR2eMMMC???
{REG_PIN_EMMC_D4,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D4,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NFD05_EMMCD4?LPDDR2eMMMC???
{REG_PIN_EMMC_DUMMY,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_EMMC_DUMMY,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//???Ball
{REG_PIN_EMMC_DS,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_DS,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NFD03_EMMCRCLK?LPDDR2eMMMC???
{REG_PIN_EMMC_CLK,                      BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_CLK,                 BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NFREN_EMMCCLK?LPDDR2eMMMC???
{REG_PIN_EMMC_D6,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D6,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NFCLF_EMMCD6?LPDDR2eMMMC???
{REG_PIN_EMMC_D3,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D3,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NFD07_EMMCD3?LPDDR2eMMMC???
{REG_PIN_EMMC_D0,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D0,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NFWPN_EMMCD0?LPDDR2eMMMC???
{REG_PIN_EMMC_CMD,                      BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_CMD,                 BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//NFRB_EMMCCMD?LPDDR2eMMMC???
{REG_PIN_EMMC_D7,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_D7,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NFALE_EMMCD7?LPDDR2eMMMC???
{REG_PIN_EMMC_RST,                      BITS_PIN_AF(1)},
{REG_MISC_PIN_EMMC_RST,                 BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//EMMC_RST?LPDDR2eMMMC???
{REG_PIN_NF_DATA_2,                     BITS_PIN_AF(1)},
{REG_MISC_PIN_NF_DATA_2,                BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NF_D02???NAND???,???NC??
{REG_PIN_NF_DATA_0,                     BITS_PIN_AF(1)},
{REG_MISC_PIN_NF_DATA_0,                BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NF_D00???NAND???,???NC??
{REG_PIN_NF_DATA_1,                     BITS_PIN_AF(1)},
{REG_MISC_PIN_NF_DATA_1,                BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_Z},//NF_D01???NAND???,???NC??
{REG_PIN_NF_WEN,                        BITS_PIN_AF(1)},
{REG_MISC_PIN_NF_WEN,                   BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NF_WEN???NAND???,???NC??
{REG_PIN_NF_CEN0,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_NF_CEN0,                  BITS_PIN_DS(3)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NF_CEN0???NAND???,???NC??
{REG_PIN_LCM_RSTN,                      BITS_PIN_AF(3)},
{REG_MISC_PIN_LCM_RSTN,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LCM_RSTN?2.8??LCM,?LCD??????????
{REG_PIN_LCM_FMARK,                     BITS_PIN_AF(3)},
{REG_MISC_PIN_LCM_FMARK,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_IE},//LCM_FMARKLCD?????BB???????
{REG_PIN_CHIP_SLEEP,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_CHIP_SLEEP,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CHIP_SLEEP?PMU???????
{REG_PIN_PTEST,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_PTEST,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_ALL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//GND
{REG_PIN_EXT_RST_B,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_EXT_RST_B,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//EXT_RST_B??PMU?RST??
{REG_PIN_XTL_BUF_EN1,                   BITS_PIN_AF(0)},
{REG_MISC_PIN_XTL_BUF_EN1,              BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//XTL_BUF_EN1?PMU??XTL_BUF????
{REG_PIN_CLK_32K,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_CLK_32K,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//CLK_32K?PMU??32K????
{REG_PIN_AUD_SCLK,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_SCLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_SCLKBBAudio?PMU???,????ADDA??
{REG_PIN_AUD_ADD0,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_ADD0,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//AUD_ADD0BB?PMUAudio??AD????????
{REG_PIN_DCDCARM_EN,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_DCDCARM_EN,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//VDDARM_EN?PMU???ARMDCDC????
{REG_PIN_ANA_INT,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_ANA_INT,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//ANA_INT??PMU???
{REG_PIN_AUD_ADSYNC,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_ADSYNC,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//AUD_ADSYNCPMU?BBAudio???AD????
{REG_PIN_ADI_SCLK,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_ADI_SCLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//ADI_SCLKBB?PMU?ADI????
{REG_PIN_AUD_DAD1,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_DAD1,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_DAD1BB?AudioDAC????1?
{REG_PIN_AUD_DAD0,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_DAD0,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_DAD0BB?AudioDAC????0?
{REG_PIN_AUD_DASYNC,                    BITS_PIN_AF(0)},
{REG_MISC_PIN_AUD_DASYNC,               BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//AUD_DASYNCBB?Audio?DAC????
{REG_PIN_ADI_SYNC,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_ADI_SYNC,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_ALL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//???Ball
{REG_PIN_ADI_D,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_ADI_D,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//ADI_DBB?PMU???ADI??
{REG_PIN_SD0_D3,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D3,                   BITS_PIN_DS(4)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D3TF_SD?????3?
{REG_PIN_SD0_D2,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D2,                   BITS_PIN_DS(4)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D2TF_SD?????2?
{REG_PIN_SD0_CMD,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_CMD,                  BITS_PIN_DS(4)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_CMDTF_SD????PIN?
{REG_PIN_SD0_D0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D0,                   BITS_PIN_DS(4)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D0TF_SD?????0?
{REG_PIN_SD0_D1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_D1,                   BITS_PIN_DS(4)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//TF_SD0_D1TF_SD?????1?
{REG_PIN_SD0_CLK,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_CLK,                  BITS_PIN_DS(7)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//TF_SD0_CLKBBTF_SD????????
{REG_PIN_SD0_DUMMY,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_SD0_DUMMY,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_ALL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//???Ball
{REG_PIN_SD2_CLK,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_SD2_CLK,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//LCM_SPI_CLK?LCM?SPI????
{REG_PIN_SD2_CMD,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_SD2_CMD,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//LCM_SPI_DO??LCMSPI???
{REG_PIN_SD2_D0,                        BITS_PIN_AF(1)},
{REG_MISC_PIN_SD2_D0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//LCM_SPI_DI?LCM??SPI????
{REG_PIN_SD2_D1,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_D1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_OE},//VDDSDCORE_ENSD??LDO?????
{REG_PIN_SD2_D2,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_SD2_D2,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//LCM_SPI_RS?LCM?RS??
{REG_PIN_SD2_D3,                        BITS_PIN_AF(1)},
{REG_MISC_PIN_SD2_D3,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//LCM_SPI_CSNLCMSPI?????
{REG_PIN_SD2_DUMMY,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_SD2_DUMMY,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_ALL|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//???Ball
{REG_PIN_SIMCLK0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMCLK0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_CLKBBSIM0??????
{REG_PIN_SIMDAT0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMDAT0,                  BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//SIM0_DABBSIM0??????
{REG_PIN_SIMRST0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMRST0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM0_RSTBBSIM0????????
{REG_PIN_SIMCLK1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMCLK1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_CLKBBSIM1??????
{REG_PIN_SIMDAT1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMDAT1,                  BITS_PIN_DS(1)|BIT_PIN_WPUS|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//SIM1_DABBSIM1??????
{REG_PIN_SIMRST1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SIMRST1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_NONE|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//SIM1_RSTBBSIM1????????
{REG_PIN_SIMCLK2,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SIMCLK2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN13????
{REG_PIN_SIMDAT2,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SIMDAT2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN14????
{REG_PIN_SIMRST2,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SIMRST2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN15????
{REG_PIN_KEYOUT0,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_KEYOUT0,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//KEYOUT0????
{REG_PIN_KEYOUT1,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_KEYOUT1,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//KEYOUT1????
{REG_PIN_KEYOUT2,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_KEYOUT2,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//KEYOUT2????
{REG_PIN_KEYIN0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_KEYIN0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN0?????Dbgmode0??
{REG_PIN_KEYIN1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_KEYIN1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN1????
{REG_PIN_KEYIN2,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_KEYIN2,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN2?????Dbfmode0??
{REG_PIN_RFFE0_SCK,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE0_SCK,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFE_SCLK0BB??LTE/WCDMAPAM??TDDB34/B39/GSMPA+Switch???????
{REG_PIN_RFFE0_SDA,                     BITS_PIN_AF(0)},
{REG_MISC_PIN_RFFE0_SDA,                BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//RFFR_SDA0BB??LTE/WCDMAPAM??TDDB34/B39/GSMPA+Switch???????
{REG_PIN_RFCTL0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL_0RFCTL0~2????RF-SW-RSW5108
{REG_PIN_RFCTL1,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL1,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL_1RFCTL0~2????RF-SW-RSW5108
{REG_PIN_RFCTL2,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL2,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL_2RFCTL0~2????RF-SW-RSW5108
{REG_PIN_RFCTL3,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL3,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL_3RFCTL3~4????RF-SW-EC646
{REG_PIN_RFCTL4,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL4,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//RFCTL_4RFCTL3~4????RF-SW-EC646
{REG_PIN_RFCTL5,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL5,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL6,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL6,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL7,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL7,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL8,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL8,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL9,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL9,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL10,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL10,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL11,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL11,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_GPIO31,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_GPIO31,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_GPIO32,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_GPIO32,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN3????
{REG_PIN_GPIO33,                        BITS_PIN_AF(3)},
{REG_MISC_PIN_GPIO33,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//BOARD_ID2BoardInformation????
{REG_PIN_RFCTL16,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL16,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL17,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_RFCTL17,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_GPIO9,                         BITS_PIN_AF(0)},
{REG_MISC_PIN_GPIO9,                    BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_CP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//NC
{REG_PIN_RFCTL19,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_RFCTL19,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//BB_U3TXDUART3?TestConn
{REG_PIN_RFCTL20,                       BITS_PIN_AF(1)},
{REG_MISC_PIN_RFCTL20,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//BB_U3RXDUART3?TestConn
{REG_PIN_RFSDA0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSDA0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_NO_CM4|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI_DATA_RF0?RFTransceiver
{REG_PIN_RFSCK0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSCK0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_NO_CM4|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI_CLK_RF0?RFTransceiver
{REG_PIN_RFSEN0,                        BITS_PIN_AF(0)},
{REG_MISC_PIN_RFSEN0,                   BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_ALL_NO_CM4|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI_LE_RF0?RFTransceiver
{REG_PIN_LVDSRF0_ADCON,                 BITS_PIN_AF(3)},
{REG_MISC_PIN_LVDSRF0_ADCON,            BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_LVDSRF0_DACON,                 BITS_PIN_AF(3)},
{REG_MISC_PIN_LVDSRF0_DACON,            BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//NC
{REG_PIN_SPI2_CSN,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_SPI2_CSN,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI2??????Sensor,?GPIO??????SPI,??NFC
{REG_PIN_SPI2_DO,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SPI2_DO,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI2??????Sensor,?GPIO??????SPI,??NFC
{REG_PIN_SPI2_DI,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_SPI2_DI,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI2??????Sensor,?GPIO??????SPI,??NFC
{REG_PIN_SPI2_CLK,                      BITS_PIN_AF(0)},
{REG_MISC_PIN_SPI2_CLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//SPI2??????Sensor,?GPIO??????SPI,??NFC
{REG_PIN_SPI0_CSN,                      BITS_PIN_AF(3)},
{REG_MISC_PIN_SPI0_CSN,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN6????
{REG_PIN_SPI0_DO,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SPI0_DO,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN7????
{REG_PIN_SPI0_DI,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_SPI0_DI,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN8????
{REG_PIN_SPI0_CLK,                      BITS_PIN_AF(3)},
{REG_MISC_PIN_SPI0_CLK,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPD|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//KEYIN9????
{REG_PIN_TDO_LTE,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_TDO_LTE,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN4????
{REG_PIN_TDI_LTE,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_TDI_LTE,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//BOARD_ID0BoardInormation????
{REG_PIN_TCK_LTE,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_TCK_LTE,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_IE},//BOARD_ID1BoardInformation????
{REG_PIN_TMS_LTE,                       BITS_PIN_AF(3)},
{REG_MISC_PIN_TMS_LTE,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_SE|BIT_PIN_WPU|BIT_PIN_SLP_AP|BIT_PIN_SLP_WPU|BIT_PIN_SLP_IE},//KEYIN5????
{REG_PIN_RTCK_LTE,                      BITS_PIN_AF(3)},
{REG_MISC_PIN_RTCK_LTE,                 BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_NUL|BIT_PIN_SLP_AP|BIT_PIN_SLP_NUL|BIT_PIN_SLP_OE},//CAMERA_FLASH_CHIPEN?FlashLEDDCDC?HWEN??
{REG_PIN_TCK_ARM,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_TCK_ARM,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//MTCK?TESTCONN?TestPoint
{REG_PIN_TMS_ARM,                       BITS_PIN_AF(0)},
{REG_MISC_PIN_TMS_ARM,                  BITS_PIN_DS(1)|BIT_PIN_NULL|BIT_PIN_WPU|BIT_PIN_SLP_NONE|BIT_PIN_SLP_WPD|BIT_PIN_SLP_Z},//MTMS?TESTCONN?TestPoint

};

/*here is the adie pinmap such as 2721*/
static pinmap_t adie_pinmap[]={
{REG_PIN_ANA_EXT_XTL_EN0,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//WB_CLK_REQ
{REG_PIN_ANA_EXT_XTL_EN1,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},
{REG_PIN_ANA_EXT_XTL_EN2,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},//XTL_BUF_EN1
{REG_PIN_ANA_EXT_XTL_EN3,		BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_WPD|BIT_ANA_PIN_SLP_IE},
{REG_PIN_ANA_PTESTO,            BITS_ANA_PIN_DS(1)|BIT_ANA_PIN_NUL|BITS_ANA_PIN_AF(1)|BIT_ANA_PIN_SLP_OE},//BUA_BAT_DET
};

int  pin_init(void)
{
	int i;
	for (i = 0; i < sizeof(pinmap)/sizeof(pinmap[0]); i++) {
		__raw_writel(pinmap[i].val, CTL_PIN_BASE + pinmap[i].reg);
	}

	for (i = 0; i < sizeof(adie_pinmap)/sizeof(adie_pinmap[0]); i++) {
		sci_adi_set(CTL_ANA_PIN_BASE + adie_pinmap[i].reg, adie_pinmap[i].val);
	}

	return 0;
}

