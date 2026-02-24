set(LIBNAME collide)

set(${LIBNAME}_SOURCES
	BoundingBox.cc
	BoundingGeometry.cc
	BoundingNode.cc
	Collidable.cc
	Contact.cc
	GeometryInstance.cc
	PossibleContact.cc
	Primitive.cc
	CollisionManager.cc
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
