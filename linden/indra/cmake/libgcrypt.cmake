# -*- cmake -*-

set(LIBGCRYPT_INCLUDE_DIRS
    ${CMAKE_BINARY_DIR}/libgcrypt/include
    ${LIBS_OPEN_DIR}/libgcrypt/libgcrypt-1.2.2/src
    )

if (DARWIN OR LINUX)
set(LIBGCRYPT_LIBRARIES
    ${CMAKE_BINARY_DIR}/libgcrypt/lib/libgcrypt.a
    )
endif (DARWIN OR LINUX)

if (WINDOWS)
set(LIBGCRYPT_LIBRARIES
    ${CMAKE_BINARY_DIR}/libgcrypt/gcrypt.lib
    )
endif (WINDOWS)

add_definitions( /DHAVE_CONFIG_H=1 )
