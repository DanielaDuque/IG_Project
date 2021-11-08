# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BINARY_7Z "")
set(CPACK_BINARY_BUNDLE "")
set(CPACK_BINARY_CYGWIN "")
set(CPACK_BINARY_DEB "")
set(CPACK_BINARY_DRAGNDROP "")
set(CPACK_BINARY_FREEBSD "")
set(CPACK_BINARY_IFW "")
set(CPACK_BINARY_NSIS "")
set(CPACK_BINARY_NUGET "")
set(CPACK_BINARY_OSXX11 "")
set(CPACK_BINARY_PACKAGEMAKER "")
set(CPACK_BINARY_PRODUCTBUILD "")
set(CPACK_BINARY_RPM "")
set(CPACK_BINARY_STGZ "")
set(CPACK_BINARY_TBZ2 "")
set(CPACK_BINARY_TGZ "")
set(CPACK_BINARY_TXZ "")
set(CPACK_BINARY_TZ "")
set(CPACK_BINARY_WIX "")
set(CPACK_BINARY_ZIP "")
set(CPACK_BUILD_SOURCE_DIRS "/home/daniela/Documents/insa/2021-2INFO_GRA/TP7_IG_2021-22/practical07/sfmlGraphicsPipeline/extlib/freetype-2.5.5;/home/daniela/Documents/insa/2021-2INFO_GRA/TP7_IG_2021-22/practical07/sfmlGraphicsPipeline/extlib/freetype-2.5.5/build")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.16/Templates/CPack.GenericDescription.txt")
set(CPACK_GENERATOR "TGZ")
set(CPACK_IGNORE_FILES "/CVS/;/.svn/;.swp$;.#;/#;/build/;/serial/;/ser/;/parallel/;/par/;~;/preconfig.out;/autom4te.cache/;/.config")
set(CPACK_INSTALLED_DIRECTORIES "/home/daniela/Documents/insa/2021-2INFO_GRA/TP7_IG_2021-22/practical07/sfmlGraphicsPipeline/extlib/freetype-2.5.5;/")
set(CPACK_INSTALL_CMAKE_PROJECTS "")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "")
set(CPACK_NSIS_DISPLAY_NAME "freetype 2.5.5}")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "freetype 2.5.5}")
set(CPACK_OUTPUT_CONFIG_FILE "/home/daniela/Documents/insa/2021-2INFO_GRA/TP7_IG_2021-22/practical07/sfmlGraphicsPipeline/extlib/freetype-2.5.5/build/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/usr/share/cmake-3.16/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "freetype")
set(CPACK_PACKAGE_FILE_NAME "freetype-2.5.5-r")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "freetype 2.5.5}")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "freetype 2.5.5}")
set(CPACK_PACKAGE_NAME "freetype")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "2.5.5}")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "5")
set(CPACK_PACKAGE_VERSION_PATCH "5}")
set(CPACK_RESOURCE_FILE_LICENSE "/usr/share/cmake-3.16/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "/usr/share/cmake-3.16/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/usr/share/cmake-3.16/Templates/CPack.GenericWelcome.txt")
set(CPACK_RPM_PACKAGE_SOURCES "ON")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "")
set(CPACK_SOURCE_CYGWIN "")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "/CVS/;/.svn/;.swp$;.#;/#;/build/;/serial/;/ser/;/parallel/;/par/;~;/preconfig.out;/autom4te.cache/;/.config")
set(CPACK_SOURCE_INSTALLED_DIRECTORIES "/home/daniela/Documents/insa/2021-2INFO_GRA/TP7_IG_2021-22/practical07/sfmlGraphicsPipeline/extlib/freetype-2.5.5;/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/daniela/Documents/insa/2021-2INFO_GRA/TP7_IG_2021-22/practical07/sfmlGraphicsPipeline/extlib/freetype-2.5.5/build/CPackSourceConfig.cmake")
set(CPACK_SOURCE_PACKAGE_FILE_NAME "freetype-2.5.5-r")
set(CPACK_SOURCE_RPM "")
set(CPACK_SOURCE_TBZ2 "")
set(CPACK_SOURCE_TGZ "")
set(CPACK_SOURCE_TOPLEVEL_TAG "Linux-Source")
set(CPACK_SOURCE_TXZ "")
set(CPACK_SOURCE_TZ "")
set(CPACK_SOURCE_ZIP "")
set(CPACK_STRIP_FILES "")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_TOPLEVEL_TAG "Linux-Source")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/daniela/Documents/insa/2021-2INFO_GRA/TP7_IG_2021-22/practical07/sfmlGraphicsPipeline/extlib/freetype-2.5.5/build/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
