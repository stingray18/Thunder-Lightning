set(LIBNAME jogi)

set(${LIBNAME}_SOURCES
	JCamera.cc
	JMatrix.cc
	JOpenGLRenderer.cc
	JPoint.cc
	JSprite.cc
)


add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src 
	${SIGCPP_INCLUDE_DIRS}
	/usr/include/SDL3
	/usr/include/GL
)
