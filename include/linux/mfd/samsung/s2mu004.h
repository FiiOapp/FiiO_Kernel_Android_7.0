/*
 * s2mu004.h - Driver for the s2mu004
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
 *
 * This driver is based on max8997.h
 *
 * s2mu004 has Flash LED, SVC LED, Haptic, MUIC devices.
 * The devices share the same I2C bus and included in
 * this mfd driver.
 */

#ifndef __S2MU004_H__
#define __S2MU004_H__
#include <linux/platform_device.h>
#include <linux/regmap.h>
#include <linux/power/s2mu004_charger_common.h>

#define MFD_DEV_NAME "s2mu004"
#define M2SH(m) ((m) & 0x0F ? ((m) & 0x03 ? ((m) & 0x01 ? 0 : 1) : ((m) & 0x04 ? 2 : 3)) : \
		((m) & 0x30 ? ((m) & 0x10 ? 4 : 5) : ((m) & 0x40 ? 6 : 7)))

#ifdef CONFIG_VIBETONZ
/*struct s2mu004_haptic_platform_data {
	u16 max_timeout;
	u16 duty;
	u16 period;
	u16 reg2;
	char *regulator_name;
	unsigned int pwm_id;

	void (*init_hw) (void);
	void (*motor_en) (bool);
};*/
#endif

struct s2mu004_regulator_data {
	int id;
	struct regulator_init_data *initdata;
	struct device_node *reg_node;
};

typedef struct s2mu004_charger_platform_data {
	sec_charging_current_t *charging_current_table;
	sec_charging_current_t *charging_current;
	int chg_float_voltage;
	char *charger_name;
	char *fuelgauge_name;
	bool chg_eoc_dualpath;
	int recharge_vcell;
	int chg_full_vcell;
	uint32_t is_1MHz_switching:1;
	int chg_switching_freq;
	/* 2nd full check */
	sec_battery_full_charged_t full_check_type_2nd;
} s2mu004_charger_platform_data_t;

struct s2mu004_platform_data {
	/* IRQ */
	int irq_base;
	int irq_gpio;
	bool wakeup;
	int num_regulators;
	struct s2mu004_regulator_data *regulators;
#ifdef CONFIG_VIBETONZ
	/* haptic motor data */
	/* struct s2mu004_haptic_platform_data *haptic_data; */
#endif
	s2mu004_charger_platform_data_t *pdata;

	struct mfd_cell *sub_devices;
	int num_subdevs;
};

struct s2mu004 {
	struct regmap *regmap;
};

#endif /* __S2MU004_H__ */

