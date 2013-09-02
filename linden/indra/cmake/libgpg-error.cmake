# -*- cmake -*-

set(LIBGPG-ERROR_INCLUDE_DIRS
    ${CMAKE_BINARY_DIR}/libgpg-error/include
    ${LIBS_OPEN_DIR}/libgpg-error/libgpg-error-1.0/src
    )

if (DARWIN OR LINUX)
set(LIBGPG-ERROR_LIBRARIES
    ${CMAKE_BINARY_DIR}/libgpg-error/lib/libgpg-error.a
    )
endif (DARWIN OR LINUX)

if (WINDOWS)
set(LIBGPG-ERROR_LIBRARIES
    ${CMAKE_BINARY_DIR}/libgpg-error/gpg-error.lib
    )
endif (WINDOWS)

add_definitions( /DHAVE_CONFIG_H=1 )
