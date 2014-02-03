# -*- cmake -*-

# gpg.vs is just a place to put windows specific nastyness needed to
# make the libgcrypt, libgpg-error, and libotr compile.

set(gpg.vs_INCLUDE_DIRS )
add_definitions( /DHAVE_CONFIG_H=1 )
