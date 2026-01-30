set(LIBNAME scripting)

set(${LIBNAME}_SOURCES
	IoScriptingManager.cc
	mappings.cc
	ActorMapping.cc
	ArmamentMapping.cc
	CarrierMapping.cc
	ClockMapping.cc
	ConfigMapping.cc
	DataNodeMapping.cc
	DroneMapping.cc
	EnvironmentMapping.cc
	EventMapping.cc
	FactionMapping.cc
	GameMapping.cc
	LinalgMapping.cc
	NMatrixMapping.cc
	ModelMapping.cc
	ModelManMapping.cc
	ProviderMapping.cc
	PrimitiveMappings.cc
	ReceiverMapping.cc
	SimpleActorMapping.cc
	TankMapping.cc
	TargeterMapping.cc
	TerrainMapping.cc
	WeaponMapping.cc
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
