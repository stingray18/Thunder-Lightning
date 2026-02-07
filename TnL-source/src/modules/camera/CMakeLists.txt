set(LIBNAME camera)

set(${LIBNAME}_SOURCES
	FollowingCamera.cc
	MirrorCamera.cc
	SimpleCamera.cc
	camera.cc
)

add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src 
	/usr/include/sigc++-3.0
	/usr/lib/x86_64-linux-gnu/sigc++-3.0/include
	/usr/include/SDL3
)
