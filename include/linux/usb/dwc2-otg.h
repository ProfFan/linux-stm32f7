/* include/linux/usb/dwc2-otg.h
 *
 * Copyright 2008 Openmoko, Inc.
 * Copyright 2008 Simtec Electronics
 *      Ben Dooks <ben@simtec.co.uk>
 *      http://armlinux.simtec.co.uk/
 *
 * S3C USB2.0 High-speed / OtG platform information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#ifndef __LINUX_USB_DWC2_OTG_H
#define __LINUX_USB_DWC2_OTG_H

#define DWC2_DRIVER_HOST	"dwc2"
#define DWC2_DRIVER_DEVICE	"dwc2-udc"

struct platform_device;

/**
 * struct dwc2_otg_plat - platform data for high-speed otg/udc
 * rx_fifo_sz:	size of all OUT EPs FIFO, in words
 * tx_fifo_sz:	sizes of IN EPs, in words
 * ggpio:	GGPIO register value
 */
struct dwc2_otg_plat {
	/* FIFO specific configurations */
	struct {
		char	*name;		/* gadget name */
		u32	rx;		/* rx_fifo_sz */
		u32	tx[1 + 16];	/* tx_fifo_sz (per IN EPx) */
	} fifo[8];			/* [0]: default, [x] - for 'name' gadget */

	u32		ggpio;		/* GCCFG register value in STM32 */
	u32		gotgctl;

	int		phy_type;

	int (*phy_init)(struct platform_device *pdev, int type);
	int (*phy_exit)(struct platform_device *pdev, int type);
};

#endif /* __iLINUX_USB_DWC2_OTG_H */
