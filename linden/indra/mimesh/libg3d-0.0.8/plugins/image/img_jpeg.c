/* $Id$ */

/*
    libg3d - 3D object loading library

    Copyright (c) 2011, Dawid Seikel.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <g3d/types.h>
#include <g3d/stream.h>


EAPI
gboolean plugin_load_image_from_stream(G3DContext *context, G3DStream *stream, G3DImage *image, gpointer user_data)
{
	return TRUE;
}

EAPI
gchar *plugin_description(G3DContext *context)
{
	return g_strdup("Plugin to read JPEG images.\n");
}

EAPI
gchar **plugin_extensions(G3DContext *context)
{
	return g_strsplit("jpg:jpeg:jpe:jfif:jif", ":", 0);
}

