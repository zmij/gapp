
include(FindPackageHandleStandardArgs)

if (gapp_INCLUDE_DIRS AND gapp_LIGRARIES)
	set(gapp_FIND_QUIETLY TRUE)
endif()

find_library(gapp_LIBRARY gapp)
find_path(gapp_INCLUDE_DIR gapp/gapp.hpp)

set(gapp_LIBRARIES ${gapp_LIBRARY})
set(gapp_INCLUDE_DIRS ${gapp_INCLUDE_DIR})

find_package_handle_standard_args(gapp DEFAULT_MSG gapp_LIBRARIES gapp_INCLUDE_DIRS)

mark_as_advanced(gapp_LIBRARIES gapp_INCLUDE_DIRS)
