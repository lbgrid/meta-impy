# -*- cmake -*-

# - Find libgsf
# Find the Gsf includes and library
# This module defines
#  GSF_INCLUDE_DIR, where to find gsf.h, etc.
#  GSF_LIBRARIES, the libraries needed to use Gsf.
#  GSF_FOUND, If false, do not try to use Gsf.
# also defined, but not for general use are
#  GSF_LIBRARY, where to find the Gsf library.

#IF (NOT GSF_FOUND)
#  IF (NOT GSF_FIND_QUIETLY)
#    MESSAGE(STATUS "-- Looking for libgsf")
#  ENDIF (NOT GSF_FIND_QUIETLY)

#  FIND_PATH(GSF_INCLUDE_DIR "gsf/gsf.h"
#  /usr/local/include/libgsf-1
#  /usr/local/include
#  /usr/include/libgsf-1
#  /usr/include
#  )

#  SET(GSF_NAMES ${GSF_NAMES} gsf-1)
#  FIND_LIBRARY(GSF_LIBRARY
#    NAMES ${GSF_NAMES}
#    PATHS /usr/lib /usr/local/lib
#    )

#  IF (GSF_LIBRARY AND GSF_INCLUDE_DIR)
#    SET(GSF_LIBRARIES ${GSF_LIBRARY})
#    SET(GSF_FOUND "YES")
#  ELSE (GSF_LIBRARY AND GSF_INCLUDE_DIR)
#    SET(GSF_FOUND "NO")
#  ENDIF (GSF_LIBRARY AND GSF_INCLUDE_DIR)


#  IF (GSF_FOUND)
#    IF (NOT GSF_FIND_QUIETLY)
#      MESSAGE(STATUS "-- Found libgsf: ${GSF_LIBRARIES} and: ${GSF_INCLUDE_DIR}")
#    ENDIF (NOT GSF_FIND_QUIETLY)
#  ELSE (GSF_FOUND)
#    IF (GSF_FIND_REQUIRED)
#      MESSAGE(FATAL_ERROR "-- Could not find ldbgsf")
#    ENDIF (GSF_FIND_REQUIRED)
#  ENDIF (GSF_FOUND)

#  MARK_AS_ADVANCED(
#    GSF_LIBRARY
#    GSF_INCLUDE_DIR
#    )
#ENDIF (NOT GSF_FOUND)




# - Try to find libgsf
# Once done this will define
#  LIBGSF_FOUND - System has libgsf
#  LIBGSF_INCLUDE_DIRS - The libgsf include directories
#  LIBGSF_LIBRARIES - The libraries needed to use libgsf
#  LIBGSF_DEFINITIONS - Compiler switches required for using libgsf

find_package(PkgConfig)
pkg_check_modules(PC_LIBGSF libgsf-1)
set(LIBGSF_DEFINITIONS ${PC_LIBGSF_CFLAGS_OTHER})

find_path(LIBGSF_INCLUDE_DIR gsf/gsf.h
    HINTS ${PC_LIBGSF_INCLUDEDIR} ${PC_LIBGSF_INCLUDE_DIRS}
    PATH_SUFFIXES libgsf-1 )

find_library(LIBGSF_LIBRARY NAMES gsf-1
    HINTS ${PC_LIBGSF_LIBDIR} ${PC_LIBGSF_LIBRARY_DIRS} )

set(LIBGSF_LIBRARIES ${LIBGSF_LIBRARY} )
set(LIBGSF_INCLUDE_DIRS ${LIBGSF_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBGSF_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(libgsf DEFAULT_MSG
    LIBGSF_LIBRARY LIBGSF_INCLUDE_DIR)

mark_as_advanced(LIBGSF_INCLUDE_DIR LIBGSF_LIBRARY)

