set(LIBNAME ui)

set(${LIBNAME}_SOURCES
	Component.cc
	Console.cc
	Label.cc
	loadingscreen.cc
	MainGUI.cc
	MainMenu.cc
	MissionSelector.cc
	Panel.cc
	PanelRenderPass.cc
	SettingsDlg.cc
	status.cc
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

