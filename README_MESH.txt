Notes -

This is very rough, and just a proof of concept.  I wrote it in 2010.

It works by having a totally transparent hovertext that specifies the
name of the mesh file to load -

llSetText("http://onefang.net/downloads/Citizen%20Extras_Female%2002.zip", <1.0, 1.0, 1.0>, 0.0);

Only the dae and kmz loaders are included in the build so far.  The
gdk_pixbuf one is included in the build to, but it's broken.

libmagic and libgsf are optional components, but I think they are
installed in ubuntu 10.04 LTS by default. All other requirements are
part of the viewer anyway.  So need to install libmagic-dev and
libgsf-1-dev to build.

libg3d itself is available for ubuntu, but not installed by default,
plus I've made lots of nmall changes, and will make major ones later..

PROBLEMS - 

I was unable to get texture loading working, though that worked on my
meta7 viewer tests.

If the model is not moving, it will only show for a few seconds, then
flicker out until you move it again.

I have not sorted out how to scale them yet.

