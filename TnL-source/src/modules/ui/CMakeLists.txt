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
	/usr/include/SDL3
	/usr/include/sigc++-3.0
	/usr/lib/x86_64-linux-gnu/sigc++-3.0/include)
