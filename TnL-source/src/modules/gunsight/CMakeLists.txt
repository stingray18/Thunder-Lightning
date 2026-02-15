set(LIBNAME gunsight)

set(${LIBNAME}_SOURCES
	basic.cc
	gunsight.cc
	flight.cc
	debug.cc
	notification.cc
	targeting.cc
)


add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src 
	/usr/include/SDL3
	/usr/include/sigc++-3.0
	/usr/lib/x86_64-linux-gnu/sigc++-3.0/include)
