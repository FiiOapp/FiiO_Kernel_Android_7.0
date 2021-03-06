/*
 * s2mu004-private.h - Voltage regulator driver for the s2mu004
 *
 * Copyright (C) 2016 Samsung Electronics Co.Ltd
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __LINUX_MFD_S2MU004_PRIV_H
#define __LINUX_MFD_S2MU004_PRIV_H

#include <linux/i2c.h>

//#include <linux/battery/charger/s2mu004_charger.h>
//#include <linux/battery/fuelgauge/s2mu004_fuelgauge.h>

#define S2MU004_I2C_ADDR		(0x7A)
#define S2MU004_REG_INVALID		(0xff)

enum s2mu004_reg {
	/* Slave addr = 0x7A */
	S2MU004_REG_SC_INT1,
	S2MU004_REG_SC_INT2,
	S2MU004_REG_SC_INT1_MASK,
	S2MU004_REG_SC_INT2_MASK,
	S2MU004_REG_AFC_INT,
	S2MU004_REG_AFC_INT_MASK,
	S2MU004_REG_MUIC_INT1,
	S2MU004_REG_MUIC_INT2,
	S2MU004_REG_MUIC_INT1_MASK,
	S2MU004_REG_MUIC_INT2_MASK,

	S2MU004_REG_SC_STATUS0,
	S2MU004_REG_SC_STATUS1,
	S2MU004_REG_SC_STATUS2,
	S2MU004_REG_SC_STATUS3,
	S2MU004_REG_SC_STATUS4,
	S2MU004_REG_SC_STATUS5,
	S2MU004_REG_SC_CTRL0,
	S2MU004_REG_SC_CTRL1,
	S2MU004_REG_SC_CTRL2,
	S2MU004_REG_SC_CTRL3,
	S2MU004_REG_SC_CTRL4,
	S2MU004_REG_SC_CTRL5,
	S2MU004_REG_SC_CTRL6,
	S2MU004_REG_SC_CTRL7,
	S2MU004_REG_SC_CTRL8,
	S2MU004_REG_SC_CTRL9,
	S2MU004_REG_SC_CTRL10,
	S2MU004_REG_SC_CTRL11,
	S2MU004_REG_SC_CTRL12,
	S2MU004_REG_SC_CTRL13,
	S2MU004_REG_SC_CTRL14,
	S2MU004_REG_SC_CTRL15,
	S2MU004_REG_SC_CTRL16,
	S2MU004_REG_SC_CTRL17,
	S2MU004_REG_SC_CTRL18,
	S2MU004_REG_SC_TEST0,
	S2MU004_REG_SC_TEST1,
	S2MU004_REG_SC_TEST2,
	S2MU004_REG_SC_TEST3,
	S2MU004_REG_SC_TEST4,
	S2MU004_REG_SC_TEST5,
	S2MU004_REG_SC_TEST6,
	S2MU004_REG_SC_TEST7,
	S2MU004_REG_SC_TEST8,
	S2MU004_REG_SC_RSVD2B,
	S2MU004_REG_SC_TEST10,

	S2MU004_REG_LED_EN = 0x39,
	S2MU004_REG_LED1_CURRENT,
	S2MU004_REG_LED2_CURRENT,
	S2MU004_REG_LED3_CURRENT,
	S2MU004_REG_LED4_CURRENT,
	S2MU004_REG_LED1_RAMP,
	S2MU004_REG_LED1_DUR,
	S2MU004_REG_LED2_RAMP,
	S2MU004_REG_LED2_DUR,
	S2MU004_REG_LED3_RAMP,
	S2MU004_REG_LED3_DUR,
	S2MU004_REG_LED4_RAMP,
	S2MU004_REG_LED4_DUR,
	S2MU004_REG_LED_TEST0,
	S2MU004_REG_LED_CTRL0,

	S2MU004_REG_AFC_STATUS = 0x48,
	S2MU004_REG_AFC_CTRL1,
	S2MU004_REG_AFC_CTRL2,
	S2MU004_REG_TX_BYTE1,
	S2MU004_REG_RX_BYTE1,
	S2MU004_REG_RX_BYTE2,
	S2MU004_REG_RX_BYTE3,
	S2MU004_REG_RX_BYTE4,
	S2MU004_REG_RX_BYTE5,
	S2MU004_REG_RX_BYTE6,
	S2MU004_REG_RX_BYTE7,
	S2MU004_REG_RX_BYTE8,
	S2MU004_REG_RX_BYTE9,
	S2MU004_REG_RX_BYTE10,
	S2MU004_REG_RX_BYTE11,
	S2MU004_REG_RX_BYTE12,
	S2MU004_REG_RX_BYTE13,
	S2MU004_REG_RX_BYTE14,
	S2MU004_REG_RX_BYTE15,
	S2MU004_REG_RX_BYTE16,

	S2MU004_REG_MUIC_ADC = 0x61,
	S2MU004_REG_MUIC_DEVICE_TYPE1,
	S2MU004_REG_MUIC_DEVICE_TYPE2,
	S2MU004_REG_MUIC_DEVICE_TYPE3,
	S2MU004_REG_MUIC_BUTTON1,
	S2MU004_REG_MUIC_BUTTON2,
	S2MU004_REG_MUIC_RESET,
	S2MU004_REG_MUIC_CHG_TYPE,
	S2MU004_REG_MUIC_DEVICE_APPLE,
	S2MU004_REG_MUIC_BCD_RESCAN,
	S2MU004_REG_MUIC_TEST1,
	S2MU004_REG_MUIC_TEST2,
	S2MU004_REG_MUIC_TEST3,
	S2MU004_REG_MUIC_TEST4,

	S2MU004_REG_COMMON_CFG1,
	S2MU004_REG_COMMON_CFG2,
	S2MU004_REG_MRSTB,
	S2MU004_REG_PWRSEL_CTRL0,
	S2MU004_REG_RSVD73,
	S2MU004_REG_SELFDIS_CFG1,
	S2MU004_REG_SELFDIS_CFG2,
	S2MU004_REG_SELFDIS_CFG3,
	S2MU004_REG_RSVD77,

	S2MU004_REG_REV_ID = 0x82,

	S2MU004_REG_MUIC_RID_CTRL = 0xCC,
	S2MU004_REG_MUIC_CTRL1 = 0xC7,
	S2MU004_REG_MUIC_TIMER_SET1,
	S2MU004_REG_MUIC_TIMER_SET2,
	S2MU004_REG_MUIC_SW_CTRL,
	S2MU004_REG_MUIC_TIMER_SET3,
	S2MU004_REG_MUIC_CTRL2,
	S2MU004_REG_MUIC_CTRL3,

	S2MU004_REG_END,
};

enum s2mu004_irq_source {
	CHG_INT1 = 0,
	CHG_INT2,
	AFC_INT,
	MUIC_INT1,
	MUIC_INT2,

	S2MU004_IRQ_GROUP_NR,
};

#define MUIC_MAX_INT			MUIC_INT2
#define S2MU004_NUM_IRQ_MUIC_REGS	(MUIC_MAX_INT - MUIC_INT1 + 1)

enum s2mu004_irq {

	S2MU004_CHG1_IRQ_SYS,		/* 0 */
	S2MU004_CHG1_IRQ_Poor_CHG,	/* 1 */
	S2MU004_CHG1_IRQ_CHG_Fault,	/* 2 */
	S2MU004_CHG1_IRQ_CHG_RSTART,	/* 3 */
	S2MU004_CHG1_IRQ_DONE,		/* 4 */
	S2MU004_CHG1_IRQ_TOP_OFF,	/* 5 */
	S2MU004_CHG1_IRQ_WCIN,		/* 6 */
	S2MU004_CHG1_IRQ_CHGIN,		/* 7 */

	S2MU004_CHG2_IRQ_ICR,		/* 8 */
	S2MU004_CHG2_IRQ_IVR,		/* 9 */
	S2MU004_CHG2_IRQ_AICL,		/* 10 */
	S2MU004_CHG2_IRQ_TX_Fault,	/* 11 */
	S2MU004_CHG2_IRQ_OTG_Fault,	/* 12 */
	S2MU004_CHG2_IRQ_DET_BAT,	/* 13 */
	S2MU004_CHG2_IRQ_BAT,		/* 14 */

	S2MU004_AFC_IRQ_VbADC,		/* 15 */
	S2MU004_AFC_IRQ_VDNMon,		/* 16 */
	S2MU004_AFC_IRQ_DNRes,		/* 17 */
	S2MU004_AFC_IRQ_MPNack,		/* 18 */
	S2MU004_AFC_IRQ_MRxBufOw,	/* 19 */
	S2MU004_AFC_IRQ_MRxTrf,		/* 20 */
	S2MU004_AFC_IRQ_MRxPerr,	/* 21 */
	S2MU004_AFC_IRQ_MRxRdy,		/* 22 */

	S2MU004_MUIC_IRQ1_ATTATCH,	/* 23 */
	S2MU004_MUIC_IRQ1_DETACH,	/* 24 */
	S2MU004_MUIC_IRQ1_KP,		/* 25 */
	S2MU004_MUIC_IRQ1_LKP,		/* 26 */
	S2MU004_MUIC_IRQ1_LKR,		/* 27 */
	S2MU004_MUIC_IRQ1_RID_CHG,	/* 28 */

	S2MU004_MUIC_IRQ2_VBUS_ON,	/* 29 */
	S2MU004_MUIC_IRQ2_RSVD_ATTACH,	/* 30 */
	S2MU004_MUIC_IRQ2_ADC_CHANGE,	/* 31 */
	S2MU004_MUIC_IRQ2_STUCK,	/* 32 */
	S2MU004_MUIC_IRQ2_STUCKRCV,	/* 33 */
	S2MU004_MUIC_IRQ2_MHDL,		/* 34 */
	S2MU004_MUIC_IRQ2_AV_CHARGE,	/* 35 */
	S2MU004_MUIC_IRQ2_VBUS_OFF,	/* 36 */
	S2MU004_IRQ_NR,
};

struct s2mu004_dev {
	struct device *dev;
	struct i2c_client *i2c; /* Slave addr = 0x7A */
	struct mutex i2c_lock;

	int type;

	int irq;
	int irq_base;
	int irq_gpio;
	bool wakeup;
	struct mutex irqlock;
	int irq_masks_cur[S2MU004_IRQ_GROUP_NR];
	int irq_masks_cache[S2MU004_IRQ_GROUP_NR];

#ifdef CONFIG_HIBERNATION
	/* For hibernation */
	u8 reg_pmic_dump[S2MU004_PMIC_REG_END];
	u8 reg_muic_dump[S2MU004_MUIC_REG_END];
	u8 reg_led_dump[S2MU004_LED_REG_END];
#endif

	/* pmic VER/REV register */
	u8 pmic_rev;	/* pmic Rev */
	u8 pmic_ver;	/* pmic version */

	struct s2mu004_platform_data *pdata;
};

enum s2mu004_types {
	TYPE_S2MU004,
};

extern int s2mu004_irq_init(struct s2mu004_dev *s2mu004);
extern void s2mu004_irq_exit(struct s2mu004_dev *s2mu004);

/* s2mu004 shared i2c API function */
extern int s2mu004_read_reg(struct i2c_client *i2c, u8 reg, u8 *dest);
extern int s2mu004_bulk_read(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int s2mu004_write_reg(struct i2c_client *i2c, u8 reg, u8 value);
extern int s2mu004_bulk_write(struct i2c_client *i2c, u8 reg, int count,
				u8 *buf);
extern int s2mu004_write_word(struct i2c_client *i2c, u8 reg, u16 value);
extern int s2mu004_read_word(struct i2c_client *i2c, u8 reg);

extern int s2mu004_update_reg(struct i2c_client *i2c, u8 reg, u8 val, u8 mask);

/* s2mu004 check muic path fucntion */
extern bool is_muic_usb_path_ap_usb(void);
extern bool is_muic_usb_path_cp_usb(void);

/* s2mu004 Debug. ft */
extern void s2mu004_muic_read_register(struct i2c_client *i2c);

/* for charger api */
extern void s2mu004_hv_muic_charger_init(void);
#endif /* __LINUX_MFD_S2MU004_PRIV_H */

