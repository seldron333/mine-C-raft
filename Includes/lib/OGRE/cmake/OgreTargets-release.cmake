#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "OgreMain" for configuration "Release"
set_property(TARGET OgreMain APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreMain PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libOgreMain.so.13.4"
  IMPORTED_SONAME_RELEASE "libOgreMain.so.13.4"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreMain )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreMain "${_IMPORT_PREFIX}/lib/libOgreMain.so.13.4" )

# Import target "OgreBitesQt" for configuration "Release"
set_property(TARGET OgreBitesQt APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreBitesQt PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libOgreBitesQt.so.13.4"
  IMPORTED_SONAME_RELEASE "libOgreBitesQt.so.13.4"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreBitesQt )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreBitesQt "${_IMPORT_PREFIX}/lib/libOgreBitesQt.so.13.4" )

# Import target "OgreBites" for configuration "Release"
set_property(TARGET OgreBites APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreBites PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "SDL2::SDL2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libOgreBites.so.13.4"
  IMPORTED_SONAME_RELEASE "libOgreBites.so.13.4"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreBites )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreBites "${_IMPORT_PREFIX}/lib/libOgreBites.so.13.4" )

# Import target "OgreRTShaderSystem" for configuration "Release"
set_property(TARGET OgreRTShaderSystem APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreRTShaderSystem PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libOgreRTShaderSystem.so.13.4"
  IMPORTED_SONAME_RELEASE "libOgreRTShaderSystem.so.13.4"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreRTShaderSystem )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreRTShaderSystem "${_IMPORT_PREFIX}/lib/libOgreRTShaderSystem.so.13.4" )

# Import target "OgreOverlay" for configuration "Release"
set_property(TARGET OgreOverlay APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(OgreOverlay PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libOgreOverlay.so.13.4"
  IMPORTED_SONAME_RELEASE "libOgreOverlay.so.13.4"
  )

list(APPEND _IMPORT_CHECK_TARGETS OgreOverlay )
list(APPEND _IMPORT_CHECK_FILES_FOR_OgreOverlay "${_IMPORT_PREFIX}/lib/libOgreOverlay.so.13.4" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
