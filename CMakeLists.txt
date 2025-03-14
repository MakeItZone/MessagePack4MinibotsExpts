# First time usage of CMake... some excessive notes to self

# setting cmake version is *very* important- there have been breaking changes between versions
# e.g. CMP0076 where relative/absolute path behavior for `target_sources` changed...
# This can be a real trap when looking at on-line examples 
# if you don't carefully look for the cmake version referenced.
# Ref: 
# * https://stackoverflow.com/questions/77630380/error-in-building-cmake-project-with-custom-source-and-include-directories

# Suggestions for 'modern' CMake best practices
# * gentle, practical, applicable introduction: https://iamsorush.com/posts/cpp-cmake-build/
#   * BUT I think there are some parts (eg the header only library section) where some of the cmake commands and nuances are 
#     not explicitly mentioned. OR I was already very confused (likely) when I found the article, and had yet to realize
#     that the conflicting information I'd read was all correct - just for different versions of cmake.
# * https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1#file-effective_modern_cmake-md
# * https://cliutils.gitlab.io/modern-cmake/README.html
# * https://cmake.org/cmake/help/latest/guide/tutorial/index.html
# * the official docs... <gasp!> : https://cmake.org/cmake/help/latest/index.html
# * https://stackoverflow.com/questions/78558637/how-are-file-sets-supposed-to-be-used-in-cmake
# * https://cmake.org/cmake/help/latest/command/target_sources.html#command:target_sources
# * https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/
# * https://www.kitware.com/psa-your-package-name-and-target-namespace-should-match/
# 
# Adding 3rd party header-only libraries
# * This may be out of date? - https://stackoverflow.com/questions/38159466/cmake-include-header-only-library

# Beginners note, especially with a helpful IDE like VSCode (ie where things are linted/built/run in real time)
# Sometimes it's quicker to just delete the genereated (e.g. `build`) directory than figure out what needs to be done
# to invalidate the cached/previously genererated outputs.

#
# Final note- remember CMake is a makefile generator, not a build system!
# (But it means that you can then easily use your project with command line GCC, MSVC via Visual Studio*, or XCode + CLang, etc)

cmake_minimum_required(VERSION 3.30.0)

project(MsgBuff VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add libraries with their own CMAakeLists.txt, and configure them

# Read: https://dev.to/pgradot/please-meet-the-system-property-from-cmake-325-4007
# Need to read: https://cmake.org/cmake/help/latest/guide/using-dependencies/index.html#downloading-and-building-from-source-with-fetchcontent
# because fetch-content makes more sense than using git submodules for external libraries - versioning requirements are all in one place, 
# the CMakeLists.txt file!

OPTION (MSGPACK_USE_BOOST               "Use Boost libraried"                  OFF)
OPTION (MSGPACK_BUILD_DOCS              "Build Doxygen documentation"          OFF)

add_subdirectory("${PROJECT_SOURCE_DIR}/msgpack-c" SYSTEM)

# setup common build attributes for the main executable - hence INTERFACE type
# TODO: try and find out where this idea came from- don't understand it's implications and advantages
#add_library(build_settings INTERFACE)
# add the apps includes; they won't be exported/built/copied etc automatically
#target_include_directories(build_settings INTERFACE "${PROJECT_SOURCE_DIR}/include")

# add the apps source code
add_executable(MsgBuff)
#target_include_directories(MsgBuff PRIVATE "include")
add_subdirectory("include")
add_subdirectory("src") 
#target_link_libraries(MsgBuff PRIVATE build_settings)
target_link_libraries(MsgBuff PRIVATE msgpack-cxx)

