# -*- cmake -*-

project(g3d)

include(00-Common)
include(mimesh)
include(Linking)

find_package(Libgsf REQUIRED)
find_package(Libmagic REQUIRED)

include_directories(
#    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/glib-2.0
#    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/libxml2
    ${LLXML_INCLUDE_DIRS}
    ${LIBGSF_INCLUDE_DIRS}
    ${LIBMAGIC_INCLUDE_DIRS}
    ${LIBS_OPEN_DIR}/mimesh/libg3d-0.0.8/include
)

set(G3D_SOURCE_FILES
    libg3d-0.0.8/src/context.c
    libg3d-0.0.8/src/plugins.c
    libg3d-0.0.8/src/model.c
    libg3d-0.0.8/src/object.c
    libg3d-0.0.8/src/face.c
    libg3d-0.0.8/src/material.c
    libg3d-0.0.8/src/texture.c
    libg3d-0.0.8/src/stream.c
    libg3d-0.0.8/src/stream_read.c
    libg3d-0.0.8/src/stream_file.c
    libg3d-0.0.8/src/stream_buffer.c
    libg3d-0.0.8/src/read.c
    libg3d-0.0.8/src/iff.c
    libg3d-0.0.8/src/primitive.c
    libg3d-0.0.8/src/vector.c
    libg3d-0.0.8/src/matrix.c
    libg3d-0.0.8/src/quat.c
    libg3d-0.0.8/src/stream_gsf.c
    libg3d-0.0.8/src/stream_gsf_class.c
    )

set(G3D_HEADER_FILES
    libg3d-0.0.8/src/stream_gsf_class.h
    )

set_source_files_properties(${G3D_HEADER_FILES}
    PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND G3D_SOURCE_FILES ${G3D_HEADER_FILES})

add_library(g3d
#    SHARED
    ${G3D_SOURCE_FILES}
    )

set(G3D_link_LIBRARIES
    g3d
    ${LIBGSF_LIBRARIES}
    ${LIBMAGIC_LIBRARIES}
    )

if (DARWIN)
  # don't embed a full path in the library's install name
  set_target_properties(
    g3d
    PROPERTIES
    BUILD_WITH_INSTALL_RPATH 1
    INSTALL_NAME_DIR "@executable_path/../Resources"
    )
endif (DARWIN)

#  set_target_properties(
#    g3d
#    PROPERTIES
#    LINK_FLAGS "-export-dynamic -no-undefined"
#    )

target_link_libraries(
    ${G3D_link_LIBRARIES}
    )


project(mimesh)

include(00-Common)
include(LLCommon)
#include(OpenGL)
include(LLImage)
include(LLInventory)
include(LLMath)
include(LLMessage)
include(LLPrimitive)
include(LLRender)
include(LLWindow)
include(LLXML)
include(mimesh)

include_directories(
    ${LLCOMMON_INCLUDE_DIRS}
    ${LLIMAGE_INCLUDE_DIRS}
    ${LLINVENTORY_INCLUDE_DIRS}
    ${LLMATH_INCLUDE_DIRS}
    ${LLMESSAGE_INCLUDE_DIRS}
    ${LLPRIMITIVE_INCLUDE_DIRS}
    ${LLRENDER_INCLUDE_DIRS}
    ${LLWINDOW_INCLUDE_DIRS}
    ${LLXML_INCLUDE_DIRS}
    ${G3D_INCLUDE_DIRS}
    ${MIMESH_INCLUDE_DIRS}
    ../newview
    )

set(mimesh_SOURCE_FILES
    mimesh.cpp
    gl.c
    trackball.c
    )

set(mimesh_HEADER_FILES
    CMakeLists.txt

    mimesh.h
    gl.h
    trackball.h
    )

set_source_files_properties(${mimesh_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND mimesh_SOURCE_FILES ${mimesh_HEADER_FILES})

add_library(mimesh ${mimesh_SOURCE_FILES})

target_link_libraries(mimesh
    g3d
    )



project(g3d_plugin_dae)

include(mimesh)

include_directories(
    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/glib-2.0
    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/libxml2
    ${LIBGSF_INCLUDE_DIRS}
    ${LIBMAGIC_INCLUDE_DIRS}
    ${LIBS_OPEN_DIR}/mimesh/libg3d-0.0.8/include
)

set(g3d_plugin_dae_SOURCE_FILES
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae.c
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae_cb.c
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae_library.c
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae_xml.c
    )

set(g3d_plugin_dae_HEADER_FILES
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae_cb.h
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae_chunks.h
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae_library.h
    libg3d-0.0.8/plugins/import/imp_dae/imp_dae_xml.h
    )

set_source_files_properties(${g3d_plugin_dae_HEADER_FILES}
    PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND g3d_plugin_dae_SOURCE_FILES ${g3d_plugin_dae_HEADER_FILES})

add_library(g3d_plugin_dae
    SHARED
    ${g3d_plugin_dae_SOURCE_FILES}
    )

target_link_libraries(g3d_plugin_dae
    )


project(g3d_plugin_kmz)

include(mimesh)

include_directories(
    ${LIBS_OPEN_DIR}/mimesh/libg3d-0.0.8/include
)

set(g3d_plugin_kmz_SOURCE_FILES
    libg3d-0.0.8/plugins/import/imp_kmz/imp_kmz.c
    )

set(g3d_plugin_kmz_HEADER_FILES
    )

set_source_files_properties(${g3d_plugin_kmz_HEADER_FILES}
    PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND g3d_plugin_kmz_SOURCE_FILES ${g3d_plugin_kmz_HEADER_FILES})

add_library(g3d_plugin_kmz
    SHARED
    ${g3d_plugin_kmz_SOURCE_FILES}
    )

target_link_libraries(g3d_plugin_kmz
    )


project(g3d_plugin_gdkpixbuf)

include(mimesh)

include_directories(
    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/gtk-2.0
    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/cairo
    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/pango-1.0
    ${LIBS_OPEN_DIR}/mimesh/libg3d-0.0.8/include
)

set(g3d_plugin_gdkpixbuf_SOURCE_FILES
    libg3d-0.0.8/plugins/image/img_gdkpixbuf.c
    )

set(g3d_plugin_gdkpixbuf_HEADER_FILES
    )

set_source_files_properties(${g3d_plugin_gdkpixbuf_HEADER_FILES}
    PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND g3d_plugin_gdkpixbuf_SOURCE_FILES ${g3d_plugin_gdkpixbuf_HEADER_FILES})

add_library(g3d_plugin_gdkpixbuf
    SHARED
    ${g3d_plugin_gdkpixbuf_SOURCE_FILES}
    )

set(g3d_plugin_gdkpixbuf_link_LIBRARIES
    g3d_plugin_gdkpixbuf
    ${LIBGTK_LIBRARIES}
    ${LIBCAIRO_LIBRARIES}
    ${LIBPANGO_LIBRARIES}
    )

target_link_libraries(g3d_plugin_gdkpixbuf
    ${g3d_plugin_gdkpixbuf_link_LIBRARIES}
    )

