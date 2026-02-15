set(LIBNAME engines)

set(${LIBNAME}_SOURCES
	controls.cc
	ChasingEngine.cc
	effectors.cc
	carengine.cc
	newtonianengine.cc
	missileengine.cc
	ObserverEngine.cc
	flightengine.cc
	flightengine2.cc
	flightengine3.cc
	rigidengine.cc
	tankengine.cc
	Turret.cc
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
