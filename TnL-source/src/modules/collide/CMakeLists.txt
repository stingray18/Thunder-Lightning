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
	/usr/include/SDL3
	/usr/include/sigc++-3.0
	/usr/lib/x86_64-linux-gnu/sigc++-3.0/include)
