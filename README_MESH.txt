This is my experimental mesh version of meta-impy.  At this point, you
can have usable meshes, with a little bit of work.  The next step in my
experiment is to make the meshes proper objects.  This next step should
solve a lot of the existing problems.

This is very rough, and just a proof of concept.  I wrote it in 2010.  I
will be making it better, making it work right.  So far only tested on
Ubuntu Linux.  I really need a Windows and Mac programmer to help me get
this ported to those platforms.

Only the dae and kmz (COLLADA) loaders are included in the build so far. 
The gdk_pixbuf and jpeg image loaders are included to.  Many more
loaders are to come.  Models from google warehouse should work fine.

BUILDING -

libmagic and libgsf are needed components, but I think they are
installed in Ubuntu 10.04 and up by default. All other requirements are
part of the viewer anyway.  So you need to install libmagic-dev and
libgsf-1-dev to build this.  Not libmagic++-dev.  The same probably goes
for other modern linux distros.  Windows and Mac builds might need to do
the prebuilt library thing, or something similar to what Chris did with
OTR.

libg3d (the library this is based on) itself is available for Ubuntu,
but not installed by default, plus I've made lots of small changes, and
some major ones.


USAGE -

It works by having a totally transparent hovertext on some prim that
specifies the name of the mesh file to load -

llSetText("http://onefang.net/downloads/Citizen%20Extras_Female%2002.zip", <1.0, 1.0, 1.0>, 0.0);

The prim itself will still be visible, in fact you should NOT include
any transparency on that prim.  No texture with an alpha channel, and
set transparency for the prim to 0.  See below for a work around.

Does not matter what web server you download them from, so long as the
URL include the proper file extension.  As far as I can tell, google
warehouse does not, but that might just be a matter of more complex
download code sorting through the redirects.

I (onefang) have a few test objects in Infinite Grid, ask me for them.


PROBLEMS - 

This is experimental, so you get debugging stuff printed in local chat.

If the prim is not moving, it will only show for a few seconds, then
flicker out until you move it again.  Even if it is moving, it can
flicker if the underlying prim is not visible.

I have not sorted out how to scale them yet to the size of the prim. 
Expect meshes to be about 2 meters across.

The mesh code is not yet multitasking, so the client freezes when they
are downloaded and decoded.


MESH STAND -

For best results, I have been putting them on a stand I made.  The prim
with the hover text, and thus the model, is made to be as thin as
possible, and flexible.  Have the bottom end of the prim reach down to
ground level.  That way the model will sit on the ground when you rez
it.  The flexible part keeps the prim moving, enough to work around the
flicker problem.  The thin size makes it virtually invisible.  The thin
prim is attached to a large transparent base.   The base is to make the
entire thing easy to select when you want to move or edit it.

