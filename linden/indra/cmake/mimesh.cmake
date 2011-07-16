# -*- cmake -*-

set(G3D_INCLUDE_DIRS
    ${LIBS_OPEN_DIR}/mimesh/libg3d-0.0.8/include
    )

if (LINUX)
    # In order to support using ld.gold on linux, we need to explicitely
    # specify all libraries that this library uses.
    set(G3D_LIBRARIES g3d magic gsf-1)
else (LINUX)
    set(G3D_LIBRARIES g3d)
endif (LINUX)


set(MIMESH_INCLUDE_DIRS
    ${LIBS_OPEN_DIR}/mimesh/libg3d-0.0.8/include
    ${LIBS_OPEN_DIR}/mimesh
    )

set(MIMESH_LIBRARIES mimesh ${G3D_LIBRARIES})

