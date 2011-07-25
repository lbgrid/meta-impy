# -*- cmake -*-

include(00-Common)
include(LLCommon)
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


macro(add_mimesh_library name type path)

    project(${name})

    # Note, will have to rebuild from scratch when adding or deleting a file.
    if (${ARGC} EQUAL 3)
	file(GLOB ${name}_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${path}/*.c ${path}/*.cpp)
	file(GLOB ${name}_HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${path}/*.h)
    else (${ARGC} EQUAL 3)
	file(GLOB ${name}_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${path}/${ARGV3})
    endif (${ARGC} EQUAL 3)

    list(APPEND ${name}_SOURCE_FILES ${${name}_HEADER_FILES})
    add_library(${name} ${type} ${${name}_SOURCE_FILES})

    if (DARWIN)
	# don't embed a full path in the library's install name
	set_target_properties(
	    ${name}
	    PROPERTIES
	    BUILD_WITH_INSTALL_RPATH 1
	    INSTALL_NAME_DIR "@executable_path/../Resources"
	    )
    endif (DARWIN)

#    set_target_properties(
#	 ${name}
#	PROPERTIES
#	LINK_FLAGS "-export-dynamic -no-undefined"
#    )

    target_link_libraries(${name} ${${name}_link_LIBRARIES})

    install(TARGETS ${name}
	ARCHIVE DESTINATION ${CMAKE_CURRENT_BINARY_DIR}	# This is just be a dummy.
	LIBRARY DESTINATION lib/libg3d
	)

endmacro(add_mimesh_library)


set(g3d_link_LIBRARIES
    ${LIBGSF_LIBRARIES}
    ${LIBMAGIC_LIBRARIES}
    )
add_mimesh_library(g3d STATIC libg3d-0.0.8/src)
add_mimesh_library(mimesh STATIC ".")
add_mimesh_library(g3d_plugin_dae SHARED libg3d-0.0.8/plugins/import/imp_dae)
add_mimesh_library(g3d_plugin_kmz SHARED libg3d-0.0.8/plugins/import/imp_kmz)

set(g3d_plugin_gdkpixbuf_link_LIBRARIES
    ${LIBGTK_LIBRARIES}
    ${LIBCAIRO_LIBRARIES}
    ${LIBPANGO_LIBRARIES}
    )
add_mimesh_library(g3d_plugin_gdkpixbuf SHARED libg3d-0.0.8/plugins/image img_gdkpixbuf.c)
install(FILES libg3d-0.0.8/libg3d.magic DESTINATION lib/libg3d)

