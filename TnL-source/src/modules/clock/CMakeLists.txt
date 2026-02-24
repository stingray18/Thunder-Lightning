set(LIBNAME clock)

set(${LIBNAME}_SOURCES
	clock.cc
)

add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src 
	/usr/include/SDL3
	${SIGCPP_INCLUDE_DIRS}
)
