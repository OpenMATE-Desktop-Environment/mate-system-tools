/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/* main.c: this file is part of services-admin, a gnome-system-tool frontend 
 * for run level services administration.
 * 
 * Copyright (C) 2002 Ximian, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 *
 * Authors: Carlos Garnacho Parro <garnacho@tuxerver.net>.
 */


#include <config.h>
#include <gtk/gtk.h>
#include "gst.h"

#include "table.h"
#include "services-tool.h"
#include "service-settings-table.h"
#include "callbacks.h"

GstTool *tool;

static GstDialogSignal signals [] = {
	{ "services_list",          "button_press_event",     G_CALLBACK (on_table_button_press_event) },
	{ "services_list",          "popup_menu",             G_CALLBACK (on_table_popup_menu) },
	{ NULL }
};


int 
main (int argc, char *argv[])
{
	gst_init_tool ("services-admin", argc, argv, NULL);
	tool = gst_services_tool_new ();

	gst_dialog_connect_signals (tool->main_dialog, signals);
	table_create ();
	service_settings_table_create ();

	gtk_widget_show (GTK_WIDGET (tool->main_dialog));
	gtk_main ();

	return 0;
}
