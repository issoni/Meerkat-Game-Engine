set(HEADER_FILES
	include/Meerkat.h
	MeerkatApp.h
	Utilities.h
	GameWindow.h
	WindowImplementation.h
	GLFWCode/GLFWImplementation.h
)

set(SOURCE_FILES
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
)

add_definitions(-DMK_DEBUG=2)
add_definitions(-DMEERKAT_LIB)

include_directories(../Meerkat)
include_directories(../glfw/include)

add_library(Meerkat SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Meerkat PRIVATE pch.h)

target_link_libraries(Meerkat glfw)