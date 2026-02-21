set(LIBNAME LoDTerrain)

set(${LIBNAME}_SOURCES
	Collide.cc
	Drawing.cc
	Evaluator.cc
	LoDQuadManager.cc
	LoDTerrain.cc
	image.cc
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
