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
	${SIGCPP_INCLUDE_DIRS}
)
