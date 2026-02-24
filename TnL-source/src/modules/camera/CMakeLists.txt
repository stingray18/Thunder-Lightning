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
	${SIGCPP_INCLUDE_DIRS}
	/usr/include/SDL3
)
