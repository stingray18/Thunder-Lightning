set(EXE_NAME tnl)

add_executable(${EXE_NAME})

add_subdirectory(modules/LoDTerrain)
add_subdirectory(modules/ai)
add_subdirectory(modules/actors)
add_subdirectory(modules/actors/carrier)
add_subdirectory(modules/actors/drone)
add_subdirectory(modules/actors/fx)
add_subdirectory(modules/actors/projectiles)
add_subdirectory(modules/actors/tank)
add_subdirectory(modules/camera)
add_subdirectory(modules/clock)
add_subdirectory(modules/collide)
add_subdirectory(modules/config)
add_subdirectory(modules/drawing)
add_subdirectory(modules/engines)
add_subdirectory(modules/environment)
add_subdirectory(modules/flight)
add_subdirectory(modules/fontman)
add_subdirectory(modules/gunsight)
add_subdirectory(modules/jogi)
add_subdirectory(modules/math)
add_subdirectory(modules/model)
add_subdirectory(modules/physics)
add_subdirectory(modules/scripting)
add_subdirectory(modules/skybox)
add_subdirectory(modules/texman)
add_subdirectory(modules/ui)
add_subdirectory(modules/weaponsys)


set(BIN_SOURCES
	game.cc
  defaults.cc 
  CEGUIEventFilter.cc
  object.cc
  initControls.cc
	remap.cc
  sound.cc
	TargetInfo.cc
	TypedObject.cc
	ActorStage.cc
	Faction.cc
	debug.cc
	DataNode.cc
	RenderContext.cc
	RenderPass.cc
	SceneRenderPass.cc
	AxisTransform.cc
	TnlCeguiLogger.cc
	mission.cc
)

target_sources(${EXE_NAME} PRIVATE
	${BIN_SOURCES}
)
target_include_directories(${EXE_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/src
	/usr/include/sigc++-3.0
	/usr/lib/x86_64-linux-gnu/sigc++-3.0/include
	/usr/include/GL
	/usr/include/AL
	/usr/include/SDL3
)
target_link_libraries(${EXE_NAME} PRIVATE
	LoDTerrain
	carrier
	drone
	fx
	projectiles
	tank
	ai
	actors
	camera
	clock
	collide
	config
	drawing
	engines
	environment
	flight
	fontman
	gunsight
	jogi
	math
	model
	physics
	scripting
	skybox
	texman
	ui
	weaponsys
	alut
	openal
	sigc-3.0
	SDL3
	GLEW
	GL
	png
)

target_link_directories(${EXE_NAME} PRIVATE
	${CMAKE_BINARY_DIR}/src/modules/LoDTerrain

)
