/******************************************************************************
 ** File Name:      pmu.c                                                     *
 ** Author:         Bruce_kui.Wang                                            *
 ** DATE:           20/11/2018                                                *
 ** Copyright:      2018 Spreatrum, Incoporated. All Rights Reserved.         *
 ** Description:    This file defines the basic information on chip.          *
 ******************************************************************************

 ******************************************************************************
 **                        Edit History                                       *
 ** ------------------------------------------------------------------------- *
 ** DATE           NAME             DESCRIPTION                               *
 ** 20/11/2018     Bruce_kui.Wang   Edit.                                     *
 ******************************************************************************/

/**---------------------------------------------------------------------------*
 **                         Dependencies                                      *
 **---------------------------------------------------------------------------*/
#include <asm/io.h>
#include "adi_hal_internal.h"
#include "asm/arch-roc1/sprd_reg.h"
#include "asm/arch-roc1/common.h"
/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef   __cplusplus
extern   "C"
{
#endif

#ifndef CONFIG_FPGA
#define AON_IDLE_CLK_4M_AON	 (0)

void pmu_commom_config(void)
{
	uint32_t reg_val;

	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_TOP_CFG,
		//BIT_PMU_APB_PD_APCPU_TOP_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_TOP_PD_SEL |
		//BIT_PMU_APB_PD_APCPU_TOP_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_APCPU_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_TOP_PWR_ON_SEQ_DLY(0x02) |
		BIT_PMU_APB_PD_APCPU_TOP_ISO_ON_DLY(0x09) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C0_CFG,
		//BIT_PMU_APB_PD_APCPU_C0_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C0_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C0_PD_SEL |
		//BIT_PMU_APB_PD_APCPU_C0_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_APCPU_C0_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C0_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C0_PWR_ON_SEQ_DLY(0x0A) |
		BIT_PMU_APB_PD_APCPU_C0_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C1_CFG,
		//BIT_PMU_APB_PD_APCPU_C1_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C1_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C1_PD_SEL |
		BIT_PMU_APB_PD_APCPU_C1_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_APCPU_C1_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C1_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C1_PWR_ON_SEQ_DLY(0x09) |
		BIT_PMU_APB_PD_APCPU_C1_ISO_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C2_CFG,
		//BIT_PMU_APB_PD_APCPU_C2_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C2_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C2_PD_SEL |
		BIT_PMU_APB_PD_APCPU_C2_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_APCPU_C2_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C2_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C2_PWR_ON_SEQ_DLY(0x08) |
		BIT_PMU_APB_PD_APCPU_C2_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C3_CFG,
		//BIT_PMU_APB_PD_APCPU_C3_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C3_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C3_PD_SEL |
		BIT_PMU_APB_PD_APCPU_C3_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_APCPU_C3_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C3_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C3_PWR_ON_SEQ_DLY(0x07) |
		BIT_PMU_APB_PD_APCPU_C3_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_TOP_CFG2,
		BIT_PMU_APB_PD_APCPU_TOP_DCDC_PWR_ON_DLY(0x0F) |
		BIT_PMU_APB_PD_APCPU_TOP_DCDC_PWR_OFF_DLY(0x0F) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AP_VSP_CFG,
		BIT_PMU_APB_PD_AP_VSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_AP_VSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AP_VSP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AP_VSP_PWR_ON_SEQ_DLY(0x03) |
		BIT_PMU_APB_PD_AP_VSP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AP_SYS_CFG,
		//BIT_PMU_APB_PD_AP_SYS_FORCE_SHUTDOWN |
		BIT_PMU_APB_PD_AP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AP_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AP_SYS_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_AP_SYS_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AP_VDSP_CFG,
		//BIT_PMU_APB_PD_AP_VDSP_PD_SEL |
		BIT_PMU_APB_PD_AP_VDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_AP_VDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AP_VDSP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AP_VDSP_PWR_ON_SEQ_DLY(0x02) |
		BIT_PMU_APB_PD_AP_VDSP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_MM_TOP_CFG,
		//BIT_PMU_APB_PD_MM_TOP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_MM_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_MM_TOP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_MM_TOP_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_MM_TOP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GPU_RGX_DUST_CFG0,
		//BIT_PMU_APB_PD_GPU_RGX_DUST_PWRUP_ABORT |
		//BIT_PMU_APB_PD_GPU_RGX_DUST_PWRDWN_ABORT |
		//BIT_PMU_APB_PD_GPU_RGX_DUST_PD_SEL |
		BIT_PMU_APB_PD_GPU_RGX_DUST_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_GPU_RGX_DUST_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_GPU_RGX_DUST_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_RGX_DUST_PWR_ON_SEQ_DLY(0x14) |
		BIT_PMU_APB_PD_GPU_RGX_DUST_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GPU_RGX_DUST_CFG1,
		BIT_PMU_APB_PD_GPU_RGX_DUST_SHUTDOWN_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_RGX_DUST_RST_DEASSERT_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_RGX_DUST_RST_ASSERT_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_RGX_DUST_ISO_OFF_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GPU_TOP_CFG0,
		//BIT_PMU_APB_PD_GPU_TOP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_GPU_TOP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_GPU_TOP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_TOP_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_TOP_ISO_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_CE_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_CE_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_CE_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_CE_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LTE_CE_PWR_ON_SEQ_DLY(0x06) |
		BIT_PMU_APB_PD_WTLCP_LTE_CE_ISO_ON_DLY(0x06) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_DPFEC_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_DPFEC_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_DPFEC_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_DPFEC_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LTE_DPFEC_PWR_ON_SEQ_DLY(0x0A) |
		BIT_PMU_APB_PD_WTLCP_LTE_DPFEC_ISO_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LDSP_CFG,
		//BIT_PMU_APB_PD_WTLCP_LDSP_PD_SEL |
		BIT_PMU_APB_PD_WTLCP_LDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LDSP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LDSP_PWR_ON_SEQ_DLY(0x0B) |
		BIT_PMU_APB_PD_WTLCP_LDSP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_TGDSP_CFG,
		//BIT_PMU_APB_PD_WTLCP_TGDSP_PD_SEL |
		BIT_PMU_APB_PD_WTLCP_TGDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_TGDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_TGDSP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_TGDSP_PWR_ON_SEQ_DLY(0x08) |
		BIT_PMU_APB_PD_WTLCP_TGDSP_ISO_ON_DLY(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_HU3GE_A_CFG,
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_HU3GE_A_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_PWR_ON_SEQ_DLY(0x05) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_A_ISO_ON_DLY(0x07) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_HU3GE_B_CFG,
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_HU3GE_B_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_PWR_ON_SEQ_DLY(0x09) |
		BIT_PMU_APB_PD_WTLCP_HU3GE_B_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_LTE_PROC_CFG,
		BIT_PMU_APB_PD_WTLCP_LTE_PROC_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_LTE_PROC_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_LTE_PROC_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_LTE_PROC_PWR_ON_SEQ_DLY(0x02) |
		BIT_PMU_APB_PD_WTLCP_LTE_PROC_ISO_ON_DLY(0x0A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_TD_PROC_CFG,
		BIT_PMU_APB_PD_WTLCP_TD_PROC_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_TD_PROC_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_TD_PROC_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_TD_PROC_PWR_ON_SEQ_DLY(0x04) |
		BIT_PMU_APB_PD_WTLCP_TD_PROC_ISO_ON_DLY(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_WTLCP_SYS_CFG,
		BIT_PMU_APB_PD_WTLCP_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_WTLCP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_WTLCP_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_SYS_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_WTLCP_SYS_ISO_ON_DLY(0x0B) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_PUBCP_SYS_CFG,
		//BIT_PMU_APB_PD_PUBCP_DBG_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUBCP_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_PUBCP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_PUBCP_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_PUBCP_SYS_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_PUBCP_SYS_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AUDCP_AUDDSP_CFG,
		//BIT_PMU_APB_PD_AUDCP_AUDDSP_PD_SEL |
		BIT_PMU_APB_PD_AUDCP_AUDDSP_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_AUDCP_AUDDSP_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AUDCP_AUDDSP_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AUDCP_AUDDSP_PWR_ON_SEQ_DLY(0x03) |
		BIT_PMU_APB_PD_AUDCP_AUDDSP_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AUDCP_SYS_CFG,
		BIT_PMU_APB_PD_AUDCP_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_AUDCP_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AUDCP_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AUDCP_SYS_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_AUDCP_SYS_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT3,
		BIT_PMU_APB_PCIEPLL_V_WAIT_CNT(0x08) |
		BIT_PMU_APB_PCIEPLL_H_WAIT_CNT(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTL_WAIT_CNT,
		BIT_PMU_APB_XTLBUF1_WAIT_CNT(0x06) |
		BIT_PMU_APB_XTLBUF0_WAIT_CNT(0x06) |
		BIT_PMU_APB_XTL1_WAIT_CNT(0x46) |
		BIT_PMU_APB_XTL0_WAIT_CNT(0x46) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT0,
		BIT_PMU_APB_MPLL2_WAIT_CNT(0x0F) |
		BIT_PMU_APB_MPLL1_WAIT_CNT(0x0F) |
		BIT_PMU_APB_MPLL0_WAIT_CNT(0x0F) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT1,
		BIT_PMU_APB_LTEPLL_WAIT_CNT(0x08) |
		BIT_PMU_APB_TWPLL_WAIT_CNT(0x08) |
		BIT_PMU_APB_DPLL1_WAIT_CNT(0x08) |
		BIT_PMU_APB_DPLL0_WAIT_CNT(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PLL_WAIT_CNT2,
		BIT_PMU_APB_ISPPLL_WAIT_CNT(0x08) |
		BIT_PMU_APB_RPLL_WAIT_CNT(0x04) |
		BIT_PMU_APB_GPLL_WAIT_CNT(0x08) |
		BIT_PMU_APB_APLL_WAIT_CNT(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTLBUF_LDO_WAIT_CNT,
		BIT_PMU_APB_XTLBUF_PCIEV_LDO_WAIT_CNT(0x03) |
		BIT_PMU_APB_XTLBUF_PCIEH_LDO_WAIT_CNT(0x03) |
		BIT_PMU_APB_XTLBUF1_LDO_WAIT_CNT(0x03) |
		BIT_PMU_APB_XTLBUF0_LDO_WAIT_CNT(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_XTL_WAIT_CNT1,
		BIT_PMU_APB_XTLBUF_PCIEH_WAIT_CNT(0x04) |
		BIT_PMU_APB_XTLBUF_PCIEV_WAIT_CNT(0x04) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_CNT_WAIT_CFG0,
		BIT_PMU_APB_AUDCP_PWR_WAIT_CNT(0x08) |
		BIT_PMU_APB_PUBCP_PWR_WAIT_CNT(0x08) |
		BIT_PMU_APB_WTLCP_PWR_WAIT_CNT(0x08) |
		BIT_PMU_APB_AP_PWR_WAIT_CNT(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_CNT_WAIT_CFG1,
		BIT_PMU_APB_IPA_PWR_WAIT_CNT(0x08) |
		BIT_PMU_APB_SP_SYS_PWR_WAIT_CNT(0x08) |
		BIT_PMU_APB_ESE_PWR_WAIT_CNT(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_RCO_CNT_WAIT_CFG,
		BIT_PMU_APB_RCO_WAIT_CNT(0x0B) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PMU_CLK_DIV_CFG,
		BIT_PMU_APB_PWR_ST_CLK_DIV_CFG(0x0F) |
		BIT_PMU_APB_SLP_CTRL_CLK_DIV_CFG(0x7F) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_CGM_PMU_SEL,
		BIT_PMU_APB_CGM_PMU_SEL_REG(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PWR_DGB_PARAMETER,
		BIT_PMU_APB_RAM_PWR_DLY(0x01) |
		BIT_PMU_APB_ISO_OFF_DLY(0x01) |
		BIT_PMU_APB_CGM_ON_DLY(0x01) |
		BIT_PMU_APB_RST_ASSERT_DLY(0x01) |
		0
	);

	reg_val = CHIP_REG_GET(REG_PMU_APB_ANALOG_PHY_PD_CFG) & 0xFFFFF00F;
	CHIP_REG_SET(REG_PMU_APB_ANALOG_PHY_PD_CFG,
		reg_val |
		BIT_PMU_APB_PHY_PWR_DLY(0x01) |
		0
	);

	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C4_CFG,
		//BIT_PMU_APB_PD_APCPU_C4_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C4_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C4_PD_SEL |
		BIT_PMU_APB_PD_APCPU_C4_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_APCPU_C4_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C4_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C4_PWR_ON_SEQ_DLY(0x06) |
		BIT_PMU_APB_PD_APCPU_C4_ISO_ON_DLY(0x05) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C5_CFG,
		//BIT_PMU_APB_PD_APCPU_C5_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C5_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C5_PD_SEL |
		BIT_PMU_APB_PD_APCPU_C5_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_APCPU_C5_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C5_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C5_PWR_ON_SEQ_DLY(0x05) |
		BIT_PMU_APB_PD_APCPU_C5_ISO_ON_DLY(0x06) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C6_CFG,
		//BIT_PMU_APB_PD_APCPU_C6_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C6_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C6_PD_SEL |
		BIT_PMU_APB_PD_APCPU_C6_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_APCPU_C6_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C6_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C6_PWR_ON_SEQ_DLY(0x04) |
		BIT_PMU_APB_PD_APCPU_C6_ISO_ON_DLY(0x07) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_C7_CFG,
		//BIT_PMU_APB_PD_APCPU_C7_WFI_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C7_DBG_SHUTDOWN_EN |
		//BIT_PMU_APB_PD_APCPU_C7_PD_SEL |
		BIT_PMU_APB_PD_APCPU_C7_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_APCPU_C7_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_APCPU_C7_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_APCPU_C7_PWR_ON_SEQ_DLY(0x03) |
		BIT_PMU_APB_PD_APCPU_C7_ISO_ON_DLY(0x08) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_TOP_CFG3,
		BIT_PMU_APB_PD_DCDC_CPU1_ISO_ON_DLY(0x01) |
		BIT_PMU_APB_PD_DCDC_CPU1_SHUTDOWN_WINDOW(0x00) |
		BIT_PMU_APB_PD_DCDC_CPU1_PWR_ON_DLY(0x0F) |
		BIT_PMU_APB_PD_DCDC_CPU1_PWR_OFF_DLY(0x0F) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_APCPU_TOP_CFG4,
		BIT_PMU_APB_PD_DCDC_CPU1_PWR_SEQ_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_DCDC_AI_CFG0,
		BIT_PMU_APB_PD_DCDC_AI_ISO_ON_DLY(0x01) |
		BIT_PMU_APB_PD_DCDC_AI_SHUTDOWN_WINDOW(0x00) |
		BIT_PMU_APB_PD_DCDC_AI_PWR_ON_DLY(0x0B) |
		BIT_PMU_APB_PD_DCDC_AI_PWR_OFF_DLY(0x0B) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_DCDC_AI_CFG1,
		BIT_PMU_APB_PD_DCDC_AI_PWR_SEQ_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_ESE_SYS_CFG,
		BIT_PMU_APB_PD_ESE_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_ESE_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_ESE_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_ESE_SYS_PWR_ON_SEQ_DLY(0x01)|
		BIT_PMU_APB_PD_ESE_SYS_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_APCPU_MODE_ST_CFG,
		BIT_PMU_APB_APCPU_CORINTH_RAM_PWR_DLY(0x01) |
		BIT_PMU_APB_APCPU_CORE_RAM_PWR_DLY(0x01) |
		BIT_PMU_APB_APCPU_CORE_INITIAL_DLY(0x0A) |
		BIT_PMU_APB_APCPU_CORINTH_INITIAL_DLY(0x0A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PCIEPLL_H_RST_CTRL_CFG,
		//BIT_PMU_APB_PCIEPLL_H_RST_CTRL_BYPASS |
		BIT_PMU_APB_PCIEPLL_H_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_PCIEPLL_H_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_PCIEPLL_H_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PCIEPLL_V_RST_CTRL_CFG,
		//BIT_PMU_APB_PCIEPLL_V_RST_CTRL_BYPASS |
		BIT_PMU_APB_PCIEPLL_V_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_PCIEPLL_V_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_PCIEPLL_V_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_GPU_TOP_CFG1,
		BIT_PMU_APB_PD_GPU_TOP_SHUTDOWN_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_TOP_RST_DEASSERT_DLY(0x01)|
		BIT_PMU_APB_PD_GPU_TOP_RST_ASSERT_DLY(0x01) |
		BIT_PMU_APB_PD_GPU_TOP_ISO_OFF_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_MPLL_WAIT_CLK_DIV_CFG,
		BIT_PMU_APB_MPLL_WAIT_CLK_DIV_CFG(0x00) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_MPLL0_RST_CTRL_CFG,
		//BIT_PMU_APB_MPLL0_RST_CTRL_BYPASS |
		BIT_PMU_APB_MPLL0_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_MPLL0_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_MPLL0_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_MPLL1_RST_CTRL_CFG,
		//BIT_PMU_APB_MPLL1_RST_CTRL_BYPASS |
		BIT_PMU_APB_MPLL1_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_MPLL1_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_MPLL1_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_MPLL2_RST_CTRL_CFG,
		//BIT_PMU_APB_MPLL2_RST_CTRL_BYPASS |
		BIT_PMU_APB_MPLL2_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_MPLL2_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_MPLL2_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_APLL_RST_CTRL_CFG,
		//BIT_PMU_APB_APLL_RST_CTRL_BYPASS |
		BIT_PMU_APB_APLL_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_APLL_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_APLL_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_DPLL0_RST_CTRL_CFG,
		//BIT_PMU_APB_DPLL0_RST_CTRL_BYPASS |
		BIT_PMU_APB_DPLL0_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_DPLL0_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_DPLL0_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_DPLL1_RST_CTRL_CFG,
		//BIT_PMU_APB_DPLL1_RST_CTRL_BYPASS |
		BIT_PMU_APB_DPLL1_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_DPLL1_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_DPLL1_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_TWPLL_RST_CTRL_CFG,
		//BIT_PMU_APB_TWPLL_RST_CTRL_BYPASS |
		BIT_PMU_APB_TWPLL_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_TWPLL_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_TWPLL_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_LTEPLL_RST_CTRL_CFG,
		//BIT_PMU_APB_LTEPLL_RST_CTRL_BYPASS |
		BIT_PMU_APB_LTEPLL_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_LTEPLL_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_LTEPLL_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_GPLL_RST_CTRL_CFG,
		//BIT_PMU_APB_GPLL_RST_CTRL_BYPASS |
		BIT_PMU_APB_GPLL_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_GPLL_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_GPLL_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_RPLL_RST_CTRL_CFG,
		//BIT_PMU_APB_RPLL_RST_CTRL_BYPASS |
		BIT_PMU_APB_RPLL_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_RPLL_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_RPLL_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_ISPPLL_RST_CTRL_CFG,
		//BIT_PMU_APB_ISPPLL_RST_CTRL_BYPASS |
		BIT_PMU_APB_ISPPLL_DELAY_PWR_ON(0x1A) |
		BIT_PMU_APB_ISPPLL_DELAY_EN_OFF(0x04) |
		BIT_PMU_APB_ISPPLL_DELAY_RST_ASSERT(0x1A) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_APCPU_MODE_ST_CFG1,
		BIT_PMU_APB_APCPU_CORE_RST_DEASSERT_DLY(0x02) |
		BIT_PMU_APB_APCPU_CORE_RST_ASSERT_DLY(0x02) |
		BIT_PMU_APB_APCPU_CORINTH_RST_DEASSERT_DLY(0x02) |
		BIT_PMU_APB_APCPU_CORINTH_RST_ASSERT_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_APCPU_MODE_ST_CFG2,
		BIT_PMU_APB_APCPU_CORE_CGM_OFF_DLY(0x02) |
		BIT_PMU_APB_APCPU_CORE_CGM_ON_DLY(0x02) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_SP_CLK_GATE_BYP_CFG,
		BIT_PMU_APB_SP_PWR_PD_AON_MEM_BYP |
		//BIT_PMU_APB_SP_PWR_PD_SP_MEM_BYP |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AI_POWERVR_CFG,
		//BIT_PMU_APB_PD_AI_POWERVR_PD_SEL |
		BIT_PMU_APB_PD_AI_POWERVR_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_AI_POWERVR_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AI_POWERVR_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AI_POWERVR_PWR_ON_SEQ_DLY(0x02) |
		BIT_PMU_APB_PD_AI_POWERVR_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AI_SYS_CFG,
		//BIT_PMU_APB_PD_AI_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_AI_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AI_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AI_SYS_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_AI_SYS_ISO_ON_DLY(0x03) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_AI_CAMBRICON_CFG,
		//BIT_PMU_APB_PD_AI_CAMBRICON_PD_SEL |
		BIT_PMU_APB_PD_AI_CAMBRICON_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_AI_CAMBRICON_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_AI_CAMBRICON_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_AI_CAMBRICON_PWR_ON_SEQ_DLY(0x03) |
		BIT_PMU_APB_PD_AI_CAMBRICON_ISO_ON_DLY(0x01) |
		0
	);
	CHIP_REG_SET(REG_PMU_APB_PD_IPA_SYS_CFG,
		//BIT_PMU_APB_PD_IPA_SYS_FORCE_SHUTDOWN |
		//BIT_PMU_APB_PD_IPA_SYS_AUTO_SHUTDOWN_EN |
		BIT_PMU_APB_PD_IPA_SYS_PWR_ON_DLY(0x01) |
		BIT_PMU_APB_PD_IPA_SYS_PWR_ON_SEQ_DLY(0x01) |
		BIT_PMU_APB_PD_IPA_SYS_ISO_ON_DLY(0x01) |
		0
	);
}

#ifdef ROC1_CACHE_MODIFICATION
volatile u32 wait_sync = 0;
extern void mmu_dcache_sync_va(u64 va);
extern void secondary_start();
/*
 ********************************************************************
 *func name:
 *	cache_workaround
 *func description:
 *     1.core0 config core1~core3 boot addr to secondary_boot
 *	     and then power on core1~core3.
 *     2.core1~3 powered on and hold until core0 change vddsram
 *	     to 0.85V
 *     3.core0 wait until core1~core3 apcpu_mode_state and pwr_state
 *	     become on and then change vddsram voltage to 0.85V
 *     4.force core0~4 cache on
 *     5.after the vddsram voltage become 0.85V, core1~3 enter wfi and
 *	     apcpu_mode_state become off but keep pwr_state on
 * param:
 *     none
 * return:
 *     none
 *********************************************************************
 */
void cache_workaround()
{
	//config core1~3 boot addr
	CHIP_REG_SET(REG_AON_SEC_APB_RVBARADDR1, (u32)secondary_start >>2);
	CHIP_REG_SET(REG_AON_SEC_APB_RVBARADDR2, (u32)secondary_start >>2);
	CHIP_REG_SET(REG_AON_SEC_APB_RVBARADDR3, (u32)secondary_start >>2);

	//disable core1~3 to enter sleep and power down
	CHIP_REG_AND(REG_PMU_APB_APCPU_C1_DSLP_ENA, ~BIT_PMU_APB_APCPU_C1_DSLP_ENA);
	CHIP_REG_AND(REG_PMU_APB_APCPU_C2_DSLP_ENA, ~BIT_PMU_APB_APCPU_C2_DSLP_ENA);
	CHIP_REG_AND(REG_PMU_APB_APCPU_C3_DSLP_ENA, ~BIT_PMU_APB_APCPU_C3_DSLP_ENA);

	//power on core1~3
	CHIP_REG_OR(REG_PMU_APB_PD_APCPU_C1_CFG,
				BIT_PMU_APB_PD_APCPU_C1_AUTO_SHUTDOWN_EN);
	CHIP_REG_OR(REG_PMU_APB_PD_APCPU_C2_CFG,
				BIT_PMU_APB_PD_APCPU_C2_AUTO_SHUTDOWN_EN);
	CHIP_REG_OR(REG_PMU_APB_PD_APCPU_C3_CFG,
				BIT_PMU_APB_PD_APCPU_C3_AUTO_SHUTDOWN_EN);

	CHIP_REG_OR(REG_PMU_APB_APCPU_DUAL_RAIL_RAM_FORCE_ON_CFG,
				BIT_PMU_APB_APCPU_SNOOP_FILTER_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_L3CACHE_TAG_P3_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_L3CACHE_TAG_P2_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_L3CACHE_TAG_P1_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_L3CACHE_TAG_P0_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_CORE3_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_CORE2_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_CORE1_RAM_FRC_ON |
				BIT_PMU_APB_APCPU_CORE0_RAM_FRC_ON);
	//core0 wait until core1~core3 apcpu_mode_state and pwr_state on
	while((CHIP_REG_GET(REG_PMU_APB_APCU_MODE_STATE0) != 0x02020202) ||
		  (CHIP_REG_GET(REG_PMU_APB_PWR_STATUS6_DBG) != 0x0));

	//regulator_set_voltage("vddsram", 850);

	wait_sync = 1;
	mmu_dcache_sync_va(&wait_sync);

	//chip_sleep mask following signal
	CHIP_REG_OR(REG_PMU_APB_PAD_OUT_CHIP_SLEEP_CFG,
				BIT_PMU_APB_PAD_OUT_CHIP_SLEEP_TOP_DVFS_DEEP_SLEEP_MASK |
				BIT_PMU_APB_PAD_OUT_CHIP_SLEEP_APCPU_TOP_PD_MASK);
}
#endif

//AON idle config
void aon_idle_config(void)
{
	uint32_t value = 0U;

	//Get register value and mask bit
	value = CHIP_REG_GET(REG_AON_APB_AON_APB_FREQ_CTRL) | BIT_AON_APB_AON_APB_IDLE_EN;

	//Enable aon idle
	CHIP_REG_SET(REG_AON_APB_AON_APB_FREQ_CTRL, value);

	//4M clock when aon idle
	CHIP_REG_SET(REG_AON_APB_AON_APB_CLK_SEL, BIT_AON_APB_CGM_AON_APB_LP_SEL(AON_IDLE_CLK_4M_AON));
}

// Clock auto gate
void clock_auto_gate(void)
{
	uint32_t value = 0U;

	CHIP_REG_OR(REG_AON_APB_AUTO_GATE_CTRL0,
		BIT_AON_APB_CGM_AP_AXI_AUTO_GATE_SEL |
		BIT_AON_APB_CGM_APCPU_PMU_AUTO_GATE_SEL
	);

	value = CHIP_REG_GET(REG_AON_APB_AUTO_GATE_CTRL0) & ~(BIT_AON_APB_CGM_AP_AXI_FORCE_EN | BIT_AON_APB_CGM_APCPU_PMU_FORCE_EN);
	CHIP_REG_SET(REG_AON_APB_AUTO_GATE_CTRL0, value);

	value = CHIP_REG_GET(REG_AON_APB_AUTO_GATE_CTRL1) & ~BIT_AON_APB_CGM_TOP_DVFS_ROOT_FORCE_EN | BIT_AON_APB_CGM_TOP_DVFS_ROOT_AUTO_GATE_SEL;
	CHIP_REG_SET(REG_AON_APB_AUTO_GATE_CTRL1, value);

	CHIP_REG_OR(REG_AON_APB_AUTO_GATE_CTRL3,
		BIT_AON_APB_CGM_PERIPH_AUTO_GATE_EN |
		BIT_AON_APB_CGM_GIC_AUTO_GATE_EN |
		BIT_AON_APB_CGM_ACP_AUTO_GATE_EN |
		BIT_AON_APB_CGM_AXI_PERIPH_AUTO_GATE_EN |
		BIT_AON_APB_CGM_ACE_AUTO_GATE_EN |
		BIT_AON_APB_CGM_SCU_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE7_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE6_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE5_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE4_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE3_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE2_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE1_AUTO_GATE_EN |
		BIT_AON_APB_CGM_CORE0_AUTO_GATE_EN
	);

	value = CHIP_REG_GET(REG_AON_APB_RC100M_CFG) &
			~BIT_AON_APB_RC100M_FORCE_EN |
			BIT_AON_APB_RC100M_AUTO_GATE_EN;
	CHIP_REG_SET(REG_AON_APB_RC100M_CFG, value);

	value = CHIP_REG_GET(REG_TOP_DVFS_APB_TOP_DVFS_CLK_CTRL) & ~BIT_TOP_DVFS_APB_CGM_TOP_DVFS_FORCE_EN | BIT_TOP_DVFS_APB_CGM_TOP_DVFS_AUTO_GATE_SEL;
	CHIP_REG_SET(REG_TOP_DVFS_APB_TOP_DVFS_CLK_CTRL, value);

	value = CHIP_REG_GET(REG_APCPU_DVFS_APB_CGM_APCPU_DVFS_CLK_GATE_CTRL) & ~BIT_APCPU_DVFS_APB_CGM_APCPU_DVFS_FORCE_EN | BIT_APCPU_DVFS_APB_CGM_APCPU_DVFS_AUTO_GATE_SEL;
	CHIP_REG_SET(REG_APCPU_DVFS_APB_CGM_APCPU_DVFS_CLK_GATE_CTRL, value);

	value = CHIP_REG_GET(REG_AP_DVFS_APB_CGM_AP_DVFS_CLK_GATE_CTRL) & ~BIT_AP_DVFS_APB_CGM_AP_DVFS_FORCE_EN | BIT_AP_DVFS_APB_CGM_AP_DVFS_AUTO_GATE_SEL;
	CHIP_REG_SET(REG_AP_DVFS_APB_CGM_AP_DVFS_CLK_GATE_CTRL, value);
}

void apcpu_hw_dvfs_config(void)
{
	// Disable apcpu dvfs upd delay en bit
	CHIP_REG_AND(REG_APCPU_DVFS_APB_APCPU_FREQ_UPD_TYPE_CFG, ~(
		BIT_APCPU_DVFS_APB_APCPU_GIC_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_PERIPH_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_ATB_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_SCU_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE7_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE6_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE5_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE4_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE3_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE2_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE1_FREQ_UPD_DELAY_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE0_FREQ_UPD_DELAY_EN)
	);
	// Enable apcpu dvfs upd_hdsk
	CHIP_REG_OR(REG_APCPU_DVFS_APB_APCPU_FREQ_UPD_TYPE_CFG,
		BIT_APCPU_DVFS_APB_APCPU_GIC_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_PERIPH_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_ATB_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_SCU_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE7_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE6_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE5_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE4_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE3_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE2_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE1_FREQ_UPD_HDSK_EN |
		BIT_APCPU_DVFS_APB_APCPU_CORE0_FREQ_UPD_HDSK_EN
	);
}

//AON lpc config
void aon_lpc_config(void)
{
	CHIP_REG_OR(REG_AON_APB_AP_AXI_CTRL,
		BIT_AON_APB_CGM_AP_AXI_AUTO_FREQ_DOWN_CTRL_SEL |
		BIT_AON_APB_CGM_AP_AXI_AUTO_FREQ_DOWN_EN);

	CHIP_REG_OR(REG_AON_APB_APCPU_CLUSTER_APB_LPC_CTRL, BIT_AON_APB_APCPU_CLUSTER_APB_LP_EB);
	CHIP_REG_OR(REG_AON_APB_APCPU_CLUSTER_GIC_LPC_CTRL, BIT_AON_APB_APCPU_CLUSTER_GIC_LP_EB);
	CHIP_REG_OR(REG_AON_APB_APCPU_GIC600_GIC_LPC_CTRL, BIT_AON_APB_APCPU_GIC600_GIC_LP_EB);
	//In WhaleK, Ken recommends not enabled the bit
	//CHIP_REG_OR(REG_AON_APB_APCPU_DBG_BLK_LPC_CTRL, BIT_AON_APB_APCPU_DBG_BLK_LP_EB);


	CHIP_REG_OR(REG_AON_APB_APCPU_TOP_MTX_M0_LPC_CTRL,
		BIT_AON_APB_APCPU_TOP_MTX_MIAN_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_S3_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_S2_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_S1_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_S0_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_M3_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_M2_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_M1_LP_EB |
		BIT_AON_APB_APCPU_TOP_MTX_M0_LP_EB
	);
	CHIP_REG_OR(REG_AON_APB_APCPU_CLUSTER_SCU_LPC_CTRL, BIT_AON_APB_APCPU_CLUSTER_SCU_LP_EB);

	CHIP_REG_OR(REG_AON_APB_AON_MTX_MAIN_LPC_CTRL, BIT_AON_APB_AON_MTX_MAIN_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_M0_LPC_CTRL, BIT_AON_APB_AON_MTX_M0_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_M1_LPC_CTRL, BIT_AON_APB_AON_MTX_M1_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_M2_LPC_CTRL, BIT_AON_APB_AON_MTX_M2_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_M3_LPC_CTRL, BIT_AON_APB_AON_MTX_M3_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_M4_LPC_CTRL, BIT_AON_APB_AON_MTX_M4_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_M5_LPC_CTRL, BIT_AON_APB_AON_MTX_M5_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_M6_LPC_CTRL, BIT_AON_APB_AON_MTX_M6_LP_EB);

	CHIP_REG_OR(REG_AON_APB_AON_MTX_S0_LPC_CTRL, BIT_AON_APB_AON_MTX_S0_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S1_LPC_CTRL, BIT_AON_APB_AON_MTX_S1_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S2_LPC_CTRL, BIT_AON_APB_AON_MTX_S2_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S3_LPC_CTRL, BIT_AON_APB_AON_MTX_S3_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S4_LPC_CTRL, BIT_AON_APB_AON_MTX_S4_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S5_LPC_CTRL, BIT_AON_APB_AON_MTX_S5_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S6_LPC_CTRL, BIT_AON_APB_AON_MTX_S6_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S7_LPC_CTRL, BIT_AON_APB_AON_MTX_S7_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S8_LPC_CTRL, BIT_AON_APB_AON_MTX_S8_LP_EB);
	CHIP_REG_OR(REG_AON_APB_AON_MTX_S9_LPC_CTRL, BIT_AON_APB_AON_MTX_S9_LP_EB);
}

void ap_lpc_config(void)
{
	CHIP_REG_OR(REG_AP_AHB_AP_SYS_FORCE_SLEEP_CFG, BIT_AP_AHB_CGM_CLK_AP_AXI_AUTO_GATE_EN);

	CHIP_REG_OR(REG_AP_AHB_VDSP_ASYNC_BRG, BIT_AP_AHB_VDSP_ASYNC_BRG_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_DISP_ASYNC_BRG, BIT_AP_AHB_DISP_ASYNC_BRG_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_AP_ASYNC_BRG, BIT_AP_AHB_AP_ASYNC_BRG_LP_EB);

	CHIP_REG_OR(REG_AP_AHB_M0_LPC, BIT_AP_AHB_MAIN_M0_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M1_LPC, BIT_AP_AHB_MAIN_M1_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M2_LPC, BIT_AP_AHB_MAIN_M2_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M3_LPC, BIT_AP_AHB_MAIN_M3_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M4_LPC, BIT_AP_AHB_MAIN_M4_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M5_LPC, BIT_AP_AHB_MAIN_M5_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M6_LPC, BIT_AP_AHB_MAIN_M6_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M7_LPC, BIT_AP_AHB_MAIN_M7_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M8_LPC, BIT_AP_AHB_MAIN_M8_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_M9_LPC, BIT_AP_AHB_MAIN_M9_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MAIN_LPC, BIT_AP_AHB_CGM_MATRIX_AUTO_GATE_EN | BIT_AP_AHB_MAIN_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S0_LPC, BIT_AP_AHB_CGM_MTX_S0_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S0_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S1_LPC, BIT_AP_AHB_CGM_MTX_S1_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S1_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S2_LPC, BIT_AP_AHB_CGM_MTX_S2_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S2_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S3_LPC, BIT_AP_AHB_CGM_MTX_S3_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S3_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S4_LPC, BIT_AP_AHB_CGM_MTX_S4_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S4_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S5_LPC, BIT_AP_AHB_CGM_MTX_S5_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S5_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S6_LPC, BIT_AP_AHB_CGM_MTX_S6_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S6_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S7_LPC, BIT_AP_AHB_CGM_MTX_S7_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S7_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S8_LPC, BIT_AP_AHB_CGM_MTX_S8_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S8_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_S9_LPC, BIT_AP_AHB_CGM_MTX_S9_AUTO_GATE_EN | BIT_AP_AHB_MAIN_S9_LP_EB);

	CHIP_REG_OR(REG_AP_AHB_MERGE_VDSP_M0_LPC, BIT_AP_AHB_MERGE_VDSP_M0_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MERGE_VDSP_M1_LPC, BIT_AP_AHB_MERGE_VDSP_M1_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MERGE_VDSP_M2_LPC, BIT_AP_AHB_MERGE_VDSP_M2_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MERGE_VDSP_S0_LPC, BIT_AP_AHB_MERGE_VDSP_S0_LP_EB | BIT_AP_AHB_CGM_MERGE_VDSP_S0_AUTO_GATE_EN);
	CHIP_REG_OR(REG_AP_AHB_MERGE_VDMA_M0_LPC, BIT_AP_AHB_MERGE_VDMA_M0_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MERGE_VDMA_M1_LPC, BIT_AP_AHB_MERGE_VDMA_M1_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MERGE_VDMA_S0_LPC, BIT_AP_AHB_MERGE_VDMA_S0_LP_EB | BIT_AP_AHB_CGM_MERGE_VDMA_S0_AUTO_GATE_EN);

	CHIP_REG_OR(REG_AP_AHB_MERGE_M0_LPC, BIT_AP_AHB_MERGE_M0_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MERGE_M1_LPC, BIT_AP_AHB_MERGE_M1_LP_EB);
	CHIP_REG_OR(REG_AP_AHB_MERGE_S0_LPC, BIT_AP_AHB_MERGE_S0_LP_EB | BIT_AP_AHB_CGM_MERGE_S0_AUTO_GATE_EN);
}

void CSP_Init(uint32_t gen_para)
{
	//uint32_t reg_val;
	pmu_commom_config();

	//as defaut byp ufs_pwr_gate, if board use ufs,the ufs owner will clear it.
	CHIP_REG_OR(REG_PMU_APB_UFS_PWR_GATE_BYP_CFG,
		BIT_PMU_APB_UFS_PWR_GATE_BYP);

	//pub sleep condition
	CHIP_REG_OR(REG_PMU_APB_LIGHT_SLEEP_ENABLE, BIT_PMU_APB_AON_LSLP_ENA);

	//hw-dvfs need binding to dcdc_cpu1
	CHIP_REG_OR(REG_PMU_APB_DVFS_BLOCK_SHUTDOWN_CFG, BIT_PMU_APB_DCDC_CPU1_DVFS_BLOCK_SHUTDOWN_EN);

	//cache workaround
#ifdef ROC1_CACHE_MODIFICATION
	cache_workaround();
#endif

	aon_idle_config();
	aon_lpc_config();
	ap_lpc_config();
	clock_auto_gate();

	apcpu_hw_dvfs_config();
}
#endif

/**---------------------------------------------------------------------------*
 **                         Compiler Flag                                     *
 **---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif


