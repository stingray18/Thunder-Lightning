set(LIBNAME physics)

set(${LIBNAME}_SOURCES
	RigidBody.cc
)


add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src
	${SIGCPP_INCLUDE_DIRS}
	/usr/include/SDL3
)
