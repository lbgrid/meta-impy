# -*- cmake -*-

include(00-Common)
include(libgpg-error)
include(Linking)

if (WINDOWS)

project(gpg-error)

    include_directories(
	../gpg.vs/inc.vs
	../gpg.vs/libgpg-error-1.1.vs/custom
	libgpg-error-1.0/src
	)

set(gpg-error_SOURCE_FILES
    libgpg-error-1.0/src/code-from-errno.c
    libgpg-error-1.0/src/code-to-errno.c
    libgpg-error-1.0/src/gpg-error.c
    libgpg-error-1.0/src/mkerrcodes.c
    libgpg-error-1.0/src/strerror-sym.c
    libgpg-error-1.0/src/strerror.c
    libgpg-error-1.0/src/strsource-sym.c
    libgpg-error-1.0/src/strsource.c
    )

set(gpg-error_HEADER_FILES
    CMakeLists.txt

    libgpg-error-1.0/src/err-codes.h
    libgpg-error-1.0/src/err-sources.h
    libgpg-error-1.0/src/gettext.h
    libgpg-error-1.0/src/gpg-error.h
    )

set_source_files_properties(${gpg-error_HEADER_FILES}
                            PROPERTIES HEADER_FILE_ONLY TRUE)

list(APPEND gpg-error_SOURCE_FILES ${gpg-error_HEADER_FILES})

add_library (gpg-error ${gpg-error_SOURCE_FILES})
target_link_libraries(
    gpg-error
    )

else (WINDOWS)

include(ExternalProject)

# Gotta fake a DOWNLOAD_COMMAND to work around a bug in cmake before 2.8.3.
externalproject_add(gpg-error
    DOWNLOAD_COMMAND ""
    PREFIX ${CMAKE_BINARY_DIR}/libgpg-error
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libgpg-error/libgpg-error-1.0
    CONFIGURE_COMMAND <SOURCE_DIR>/configure -prefix=<INSTALL_DIR>
    INSTALL_COMMAND make install
    )

endif (WINDOWS)

