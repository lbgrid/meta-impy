# -*- cmake -*-

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
include(Linking)
include(UI)

find_package(Libgsf REQUIRED)
find_package(Libmagic REQUIRED)

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
    ${LIBS_PREBUILT_DIR}/${LL_ARCH_DIR}/include/libxml2
    ${LIBGSF_INCLUDE_DIRS}
    ${LIBMAGIC_INCLUDE_DIRS}
    ${G3D_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/newview
)


project(g3d)

set(G3D_link_LIBRARIES
    ${LIBGSF_LIBRARIES}
    ${LIBMAGIC_LIBRARIES}
    )

# Note, will have to rebuild from scratch when adding or deleting a file.
file(GLOB G3D_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} libg3d-0.0.8/src/*.c)
file(GLOB G3D_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} libg3d-0.0.8/src/*.h)
set_source_files_properties(${G3D_HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
list(APPEND G3D_SOURCE_FILES ${G3D_HEADER_FILES})

add_library(g3d
#    SHARED
    ${G3D_SOURCE_FILES}
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

target_link_libraries(g3d
    ${G3D_link_LIBRARIES}
    )


project(mimesh)

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
set_source_files_properties(${mimesh_HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
list(APPEND mimesh_SOURCE_FILES ${mimesh_HEADER_FILES})
add_library(mimesh ${mimesh_SOURCE_FILES})
target_link_libraries(mimesh g3d)


project(g3d_plugin_dae)
file(GLOB g3d_plugin_dae_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} libg3d-0.0.8/plugins/import/imp_dae/*.c)
file(GLOB g3d_plugin_dae_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} libg3d-0.0.8/plugins/import/imp_dae/*.h)
set_source_files_properties(${g3d_plugin_dae_HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
list(APPEND g3d_plugin_dae_SOURCE_FILES ${g3d_plugin_dae_HEADER_FILES})
add_library(g3d_plugin_dae SHARED ${g3d_plugin_dae_SOURCE_FILES})
target_link_libraries(g3d_plugin_dae)


project(g3d_plugin_kmz)
file(GLOB g3d_plugin_kmz_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} libg3d-0.0.8/plugins/import/imp_kmz/*.c)
file(GLOB g3d_plugin_kmz_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} libg3d-0.0.8/plugins/import/imp_kmz/*.h)
set_source_files_properties(${g3d_plugin_kmz_HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
list(APPEND g3d_plugin_kmz_SOURCE_FILES ${g3d_plugin_kmz_HEADER_FILES})
add_library(g3d_plugin_kmz SHARED ${g3d_plugin_kmz_SOURCE_FILES})
target_link_libraries(g3d_plugin_kmz)


project(g3d_plugin_gdkpixbuf)

set(g3d_plugin_gdkpixbuf_link_LIBRARIES
    ${LIBGTK_LIBRARIES}
    ${LIBCAIRO_LIBRARIES}
    ${LIBPANGO_LIBRARIES}
    )

set(g3d_plugin_gdkpixbuf_SOURCE_FILES libg3d-0.0.8/plugins/image/img_gdkpixbuf.c)
set(g3d_plugin_gdkpixbuf_HEADER_FILES)
set_source_files_properties(${g3d_plugin_gdkpixbuf_HEADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
list(APPEND g3d_plugin_gdkpixbuf_SOURCE_FILES ${g3d_plugin_gdkpixbuf_HEADER_FILES})
add_library(g3d_plugin_gdkpixbuf SHARED ${g3d_plugin_gdkpixbuf_SOURCE_FILES})

target_link_libraries(g3d_plugin_gdkpixbuf
    ${g3d_plugin_gdkpixbuf_link_LIBRARIES}
    )

