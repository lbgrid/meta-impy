This is very rough, and just a proof of concept.  I wrote it in 2010.  I
will be making it better, making it work right.  So far only tested on
Ubuntu Linux.  I really need a Windows and Mac programmer to help me get
this ported to those platforms.

Only the dae and kmz (COLLADA) loaders are included in the build so far.  The
gdk_pixbuf one is included in the build to, but it's broken.  Many more
loaders are to come.  Models from google warehouse should work fine.

BUILDING -

libmagic and libgsf are needed components, but I think they are
installed in Ubuntu 10.04 and up by default. All other requirements are
part of the viewer anyway.  So you need to install libmagic-dev and
libgsf-1-dev to build this.  Not libmagic++-dev.

libg3d itself is available for Ubuntu, but not installed by default,
plus I've made lots of small changes, and will make major ones later.

USAGE -

It works by having a totally transparent hovertext that specifies the
name of the mesh file to load -

llSetText("http://onefang.net/downloads/Citizen%20Extras_Female%2002.zip", <1.0, 1.0, 1.0>, 0.0);

Does not matter what web server you download them from, so long as the
URL include the proper file extension.  As far as I can tell, google
warehouse does not, but that might just be a matter of more complex
download code sorting through the redirects.

I (onefang) have a few test objects in Infinite Grid, ask me for them.

PROBLEMS - 

This is experimental, so you get debugging stuff printed in local chat.

I was unable to get texture loading working, though that worked on my
meta7 viewer tests.

If the model is not moving, it will only show for a few seconds, then
flicker out until you move it again.  Even if it is moving, it can
flicker if the underlaying prim is not visible.

I have not sorted out how to scale them yet.  Expect meshes to be about
20 meters across.

The mesh code is not yet multitasking, so the client freezes when they
are downloaded and decoded.

