/*
    This is a wrapper around the libg3d mesh loading library.

    Copyright (c) 2010, Dawid Seikel.

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

#include "linden_common.h"
#include "m3math.h"
#include "m4math.h"
#include "llcamera.h"
#include "llpartdata.h"
#include "lldrawable.h"
#include "llface.h"
#include "llvovolume.h"
#include "pipeline.h"
#include "glib.h"	// Foc G_BEGIN_DECLS
#include "gl.h"
#include "mimesh.h"

void cmdline_printchat(std::string message);


G3DContext* mimesh::context;

void mimesh::startup(void)
{
    context = g3d_context_new();
}

void mimesh::load(LLViewerObject* object, std::string URL)
{
    if ((URL.substr(0, 7).compare("file://") == 0) || (URL.substr(0, 7).compare("http://") == 0))
    {
	if ((NULL == object->mimeshModel) || (0 != object->mimeshURL.compare(URL)))
	{
	    object->mimeshURL = URL;
	    std::string temp_URL = URL;
	    if (temp_URL.substr(0, 7).compare("file://") == 0)
		temp_URL = temp_URL.substr(6);
	    if (NULL != context)
	    {
		G3DModel* model;

		cmdline_printchat("Loading model " + temp_URL);
		model = g3d_model_load(context, temp_URL.c_str());
		if (model)
		{
		    texture_load_all_textures(model);
		    cmdline_printchat("Loaded model " + temp_URL);
		    if (object->mimeshModel)
		    {
			cmdline_printchat("Freeing old  model.");
			g3d_model_free(object->mimeshModel);
		    }
		    object->mimeshModel = model;
//			    gPipeline.markTextured(object->mDrawable);
//			    gPipeline.markRebuild(object->mDrawable, LLDrawable::REBUILD_VOLUME, TRUE);
//			    object->mDrawable->getVOVolume()->mVolumeChanged = TRUE;
		}
		else
		    cmdline_printchat("Failed to load model "  + URL);
	    }
	    else
		cmdline_printchat("No G3D context!");
	}
    }
    else
	object->mimeshURL.clear();
}


/*
    What to do with the data?


LLVeiwerObject contains a pointer to a LLDrawable

LLDrawable has our LLVOVolume
    contains a LLViewerObject, which apparently can be cast to a LLVOVolume
	LLVOVolume  inherits from LLViewerObject <- LLPrimitive <- LLXform
	LLVOAvataer inherits from LLViewerObject and LLCharacter
	    LLPrimitive contains a protected pointer to LLVolume mVolumep, with a public getVolume().

LLVOVolume->mVolumeChanged = TRUE;

LLVOVolume::updateGeometry() might be what we need to trigger.  Think it's called in a loop anyway.
    LLVOVolume::setVolume() is what it calls, which we DO need to trigger.
	(for sculpties it calls LLVolume->sculpt which does the actual work.)
llmath/LLVolume->mMesh is - 	std::vector<Point> mMesh;  // Can treat it like an array.
Point contains a LLVector3 -	Point->mPos (-0.5 to 0.5)

mMesh is protected.

LLVolume->mMesh gets the original prim data.
LLVolumeFace->mVertices gets a copy.
LLFace->mVertexBuffer gets a copy.
    Does the actual drawing (pushing vertices and such to GL).
    Has pointers to LLDrawable and LLViewerObject.
*/


//void mimesh::getData(LLVolume* volume)
//{
//    cmdline_printchat("Transferring model data for " + std::string(volume->mimeshModel->filename));
//}


void mimesh::render(LLViewerObject* object)
{
//    cmdline_printchat("Rendering model data for " + std::string(object->mimeshModel->filename));
    gl_draw_model(object->mimeshModel);
}


void mimesh::unload(LLViewerObject* object)
{
    cmdline_printchat("Deleting model data for " + std::string(object->mimeshModel->filename));
    g3d_model_free(object->mimeshModel);
    object->mimeshModel = NULL;
    object->mimeshURL.clear();
}

void mimesh::shutdown(void)
{
    g3d_context_free(context);
}
