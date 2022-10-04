# CMakeList.txt : CMake project for PCLDataViewer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("PCLDataViewer")

# Add source to this project's executable.
add_executable (PCLDataViewer "PCLDataViewer.cpp" "PCLDataViewer.h")
set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT "project" )
 
# Find Packages
find_package( PCL 1.8 REQUIRED )
 
if( PCL_FOUND )
  # Additional Include Directories
  # [C/C++]>[General]>[Additional Include Directories]
  include_directories( ${PCL_INCLUDE_DIRS} )
 
  # Preprocessor Definitions
  # [C/C++]>[Preprocessor]>[Preprocessor Definitions]
  add_definitions( ${PCL_DEFINITIONS} )
  #add_definitions( -DPCL_NO_PRECOMPILE )
 
  # Additional Library Directories
  # [Linker]>[General]>[Additional Library Directories]
  link_directories( ${PCL_LIBRARY_DIRS} )
 
  # Additional Dependencies
  # [Linker]>[Input]>[Additional Dependencies]
  target_link_libraries( PCLDataViewer ${PCL_LIBRARIES} )
endif()