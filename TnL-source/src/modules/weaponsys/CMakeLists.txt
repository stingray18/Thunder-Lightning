set(LIBNAME weaponsys)

set(${LIBNAME}_SOURCES
	Armament.cc
	Cannon.cc
	ProjectileLauncher.cc
	RadarNet.cc
	Targeter.cc
	Weapon.cc
)


add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src 
	${SIGCPP_INCLUDE_DIRS}
)

