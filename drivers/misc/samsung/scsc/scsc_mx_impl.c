/****************************************************************************
 *
 * Copyright (c) 2014 - 2016 Samsung Electronics Co., Ltd. All rights reserved
 *
 ****************************************************************************/

#include <linux/module.h>
#include <linux/slab.h>
#include <scsc/scsc_logring.h>
#include "scsc_mx_impl.h"
#include "mifintrbit.h"
#include "miframman.h"
#include "mifmboxman.h"
#include "mifproc.h"
#include "mxman.h"
#include "mxproc.h"
#include "srvman.h"
#include "mxmgmt_transport.h"
#include "gdb_transport.h"
#include "mxlog.h"
#include "panicmon.h"
#include "mxlog_transport.h"
#include "suspendmon.h"

struct scsc_mx {
	struct scsc_mif_abs     *mif_abs;
	struct mifintrbit       intr;
	struct miframman        ram;
	struct mifmboxman       mbox;
	struct mifproc          proc;
	struct mxman            mxman;
	struct srvman           srvman;
	struct mxmgmt_transport mxmgmt_transport;
	struct gdb_transport    gdb_transport_r4;
	struct gdb_transport    gdb_transport_m4;
	int                     users;
	struct mxlog            mxlog;
	struct panicmon         panicmon;
	struct mxlog_transport  mxlog_transport;
	struct suspendmon	suspendmon;
};


struct scsc_mx *scsc_mx_create(struct scsc_mif_abs *mif)
{
	struct scsc_mx *mx;

	mx = kzalloc(sizeof(*mx), GFP_KERNEL);
	if (!mx)
		return NULL;

	mx->mif_abs = mif;

	mifintrbit_init(&mx->intr, mif);

	mifmboxman_init(&mx->mbox);
	suspendmon_init(&mx->suspendmon, mx);
	mxman_init(&mx->mxman, mx);
	srvman_init(&mx->srvman, mx);
	mifproc_create_proc_dir(mx->mif_abs);
	SCSC_TAG_DEBUG(MXMAN, "Hurray Maxwell is here with %p\n", mx);
	return mx;
}

void scsc_mx_destroy(struct scsc_mx *mx)
{
	SCSC_TAG_DEBUG(MXMAN, "\n");
	BUG_ON(mx == NULL);
	mifintrbit_deinit(&mx->intr);
	mifmboxman_deinit(scsc_mx_get_mboxman(mx));
	suspendmon_deinit(scsc_mx_get_suspendmon(mx));
	mifproc_remove_proc_dir();
	srvman_deinit(&mx->srvman);
	mxman_deinit(&mx->mxman);
	kfree(mx);
	SCSC_TAG_DEBUG(MXMAN, "OK\n");
}

struct scsc_mif_abs *scsc_mx_get_mif_abs(struct scsc_mx *mx)
{
	return mx->mif_abs;
}

struct mifintrbit *scsc_mx_get_intrbit(struct scsc_mx *mx)
{
	return &mx->intr;
}

struct miframman *scsc_mx_get_ramman(struct scsc_mx *mx)
{
	return &mx->ram;
}

struct mifmboxman *scsc_mx_get_mboxman(struct scsc_mx *mx)
{
	return &mx->mbox;
}

struct device *scsc_mx_get_device(struct scsc_mx *mx)
{
	return mx->mif_abs->get_mif_device(mx->mif_abs);
}
EXPORT_SYMBOL_GPL(scsc_mx_get_device); /* TODO: export a top-level API for this */

struct mxman *scsc_mx_get_mxman(struct scsc_mx *mx)
{
	return &mx->mxman;
}

struct srvman *scsc_mx_get_srvman(struct scsc_mx *mx)
{
	return &mx->srvman;
}

struct mxmgmt_transport *scsc_mx_get_mxmgmt_transport(struct scsc_mx *mx)
{
	return &mx->mxmgmt_transport;
}

struct gdb_transport *scsc_mx_get_gdb_transport_r4(struct scsc_mx *mx)
{
	return &mx->gdb_transport_r4;
}

struct gdb_transport *scsc_mx_get_gdb_transport_m4(struct scsc_mx *mx)
{
	return &mx->gdb_transport_m4;
}

struct mxlog *scsc_mx_get_mxlog(struct scsc_mx *mx)
{
	return &mx->mxlog;
}

struct panicmon *scsc_mx_get_panicmon(struct scsc_mx *mx)
{
	return &mx->panicmon;
}

struct mxlog_transport *scsc_mx_get_mxlog_transport(struct scsc_mx *mx)
{
	return &mx->mxlog_transport;
}

struct suspendmon *scsc_mx_get_suspendmon(struct scsc_mx *mx)
{
	return &mx->suspendmon;
}
