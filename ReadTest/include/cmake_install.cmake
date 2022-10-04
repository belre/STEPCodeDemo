# Install script for directory: /home/okui/stepcode/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/okui/stepcode/../sc-install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode/express" TYPE FILE FILES
    "/home/okui/stepcode/include/express/alg.h"
    "/home/okui/stepcode/include/express/basic.h"
    "/home/okui/stepcode/include/express/caseitem.h"
    "/home/okui/stepcode/include/express/dict.h"
    "/home/okui/stepcode/include/express/entity.h"
    "/home/okui/stepcode/include/express/error.h"
    "/home/okui/stepcode/include/express/expbasic.h"
    "/home/okui/stepcode/include/express/expr.h"
    "/home/okui/stepcode/include/express/express.h"
    "/home/okui/stepcode/include/express/hash.h"
    "/home/okui/stepcode/include/express/lexact.h"
    "/home/okui/stepcode/include/express/linklist.h"
    "/home/okui/stepcode/include/express/memory.h"
    "/home/okui/stepcode/include/express/object.h"
    "/home/okui/stepcode/include/express/resolve.h"
    "/home/okui/stepcode/include/express/schema.h"
    "/home/okui/stepcode/include/express/scope.h"
    "/home/okui/stepcode/include/express/stmt.h"
    "/home/okui/stepcode/include/express/symbol.h"
    "/home/okui/stepcode/include/express/type.h"
    "/home/okui/stepcode/include/express/variable.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode/exppp" TYPE FILE FILES "/home/okui/stepcode/include/exppp/exppp.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode" TYPE FILE FILES
    "/home/okui/stepcode/include/ordered_attrs.h"
    "/home/okui/stepcode/include/sc_export.h"
    "/home/okui/stepcode/include/sc_stdbool.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/stepcode" TYPE FILE FILES
    "/home/okui/stepcode/build/include/sc_cf.h"
    "/home/okui/stepcode/build/include/sc_version_string.h"
    )
endif()

