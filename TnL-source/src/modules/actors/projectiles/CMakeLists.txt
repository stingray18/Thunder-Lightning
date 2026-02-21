set(LIBNAME projectiles)

set(${LIBNAME}_SOURCES
	aiminghelper.cc
	bullet.cc
	Decoy.cc
	dumbmissile.cc
	Missile.cc
	ProjectileFactories.cc
	smartmissile.cc
	smartmissile2.cc
)


add_library(${LIBNAME} STATIC)
target_sources(${LIBNAME} PUBLIC
	${${LIBNAME}_SOURCES}
)
target_include_directories(${LIBNAME} PUBLIC 
	${CMAKE_SOURCE_DIR}/src 
	${SIGCPP_INCLUDE_DIRS}
)
