cmake_minimum_required(VERSION 3.25)
project(tnl LANGUAGES CXX)

include(CMakePrintHelpers)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/tmp/install)
cmake_print_variables(CMAKE_INSTALL_PREFIX)
cmake_print_variables(PROJECT_SOURCE_DIR)

# create compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

# set compiler
set(CMAKE_CXX_COMPILER /usr/local/gcc/gcc-15.2.0/bin/g++)

# CXX Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions

# setup compiler flags
if (CMAKE_COMPILER_IS_GNUCXX)
	add_compile_options(
		-fdiagnostics-color=auto
		-Wall
		-Wextra
		-Wno-unused-parameter
		-Wno-unused-but-set-parameter
		-Wno-implicit-fallthrough
	)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")
	if (USE_LLD_LINKER)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=lld")
	endif(USE_LLD_LINKER)
	set(CMAKE_CXX_FLAGS_DEBUG "-g -Og")
endif (CMAKE_COMPILER_IS_GNUCXX)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING
		"Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel."
		FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS None Debug Release RelWithDebInfo MinSizeRel)
endif()

# Get the GIT hash of the latest commit
include(FindGit OPTIONAL)
if (GIT_FOUND AND EXISTS ${PROJECT_SOURCE_DIR}/.git)
	execute_process(
		COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		OUTPUT_VARIABLE PROJECT_VERSION_GIT
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)
endif()

string(TIMESTAMP PROJECT_VERSION "%Y%m%d")

# find cppunit
find_library(LIB_CPPUNIT cppunit REQUIRED)
# find doxygen
# find_package(Doxygen)
# if (DOXYGEN_FOUND)
# 	set(DOXYGEN_IN "")
# 	add_custom_target(doxygen_docs ALL
# 		COMMAND ${Doxygen::doxygen}
# 		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# 	)
# else()
# 	message("Install Doxygen to generate the API documentation")
# endif (DOXYGEN_FOUND)

add_subdirectory(src)

# find_package(Doxygen)
# option(BUILD_DOCUMENTATION "Create and install the HTML based API
# documentation (requires Doxygen)" ${DOXYGEN_FOUND})
#
# if(BUILD_DOCUMENTATION)
#     if(NOT DOXYGEN_FOUND)
#          message(FATAL_ERROR "Doxygen is needed to build the documentation.")
#     endif()
#
# 		set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
#     set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#
#     configure_file(${doxyfile_in} ${doxyfile} @ONLY)
#
#     message("Doxygen build started.")
#
#     add_custom_target(doc
#                       COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
# 											WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#                       COMMENT "Generating API documentation with Doxygen"
#                       VERBATIM)
#
#     #    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION     share/doc)
# endif()



# strip debug symbols into file
# 1.<Run "objcopy --only-keep-debug foo foo.dbg" to>
#              create a file containing the debugging info.
#
#           1.<Run "objcopy --strip-debug foo" to create a>
#               stripped executable.
#
#           1.<Run "objcopy --add-gnu-debuglink=foo.dbg foo">
#               to add a link to the debugging info into the stripped
#               executable.
#
#           Note---the choice of ".dbg" as an extension for the debug
#           info file is arbitrary.  Also the "--only-keep-debug" step is
#           optional.  You could instead do this:
#
#           1.<Link the executable as normal.>
#           1.<Copy "foo" to "foo.full">
#           1.<Run "strip --strip-debug foo">
#           1.<Run "objcopy --add-gnu-debuglink=foo.full foo">

