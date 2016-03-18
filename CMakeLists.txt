#
# Copyright (C) 2015 Cybernetica
#
# Research/Commercial License Usage
# Licensees holding a valid Research License or Commercial License
# for the Software may use this file according to the written
# agreement between you and Cybernetica.
#
# GNU General Public License Usage
# Alternatively, this file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl-3.0.html.
#
# For further information, please contact us at sharemind@cyber.ee.
#

CMAKE_MINIMUM_REQUIRED(VERSION "2.8.12")
PROJECT(SHAREMIND_LIBPROCESSFACILITY "C")
SET(LIBPROCESSFACILITY_VERSION "0.1.0.0")
SET(LIBPROCESSFACILITY_COMPAT_VERSION "0.1.0.0")

INCLUDE("${CMAKE_CURRENT_SOURCE_DIR}/config.local" OPTIONAL)
INCLUDE("${CMAKE_CURRENT_BINARY_DIR}/config.local" OPTIONAL)

FIND_PACKAGE(SharemindCHeaders REQUIRED)
FIND_PACKAGE(SharemindLibmodapi REQUIRED)

FILE(GLOB_RECURSE SHAREMIND_LIBPROCESSFACILITY_HEADERS
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
ADD_CUSTOM_TARGET("include_SharemindLibProcessFacility_headers_in_IDE"
                  SOURCES ${SHAREMIND_LIBPROCESSFACILITY_HEADERS})

INSTALL(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/src/"
        DESTINATION "include/sharemind")

# Install cmake files:
FILE(GLOB_RECURSE sharemind_libprocessfacility_in_files
     "${CMAKE_CURRENT_SOURCE_DIR}/*.in")
ADD_CUSTOM_TARGET("include_sharemind_libprocessfacility_in_files_in_IDE"
                  SOURCES ${sharemind_libprocessfacility_in_files})
SET(LIBPROCESSFACILITY_INSTALL_INCLUDE_DIRS
    ${Boost_INCLUDE_DIRS}
    ${SharemindCHeaders_INCLUDE_DIRS}
    ${SharemindLibmodapi_INCLUDE_DIRS}
    "${CMAKE_INSTALL_PREFIX}/include"
)
CONFIGURE_FILE(
    "${CMAKE_CURRENT_SOURCE_DIR}/SharemindLibProcessFacilityConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/SharemindLibProcessFacilityConfig.cmake" @ONLY)
CONFIGURE_FILE(
    "${CMAKE_CURRENT_SOURCE_DIR}/SharemindLibProcessFacilityConfigVersion.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/SharemindLibProcessFacilityConfigVersion.cmake" @ONLY)
INSTALL(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/SharemindLibProcessFacilityConfig.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/SharemindLibProcessFacilityConfigVersion.cmake"
    DESTINATION "lib/SharemindLibProcessFacility")
