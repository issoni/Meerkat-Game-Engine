set(HEADER_FILES
	include/Meerkat.h
	MeerkatApp.h
	Events.h
	GameWindow.h
	GLFWCode/GLFWImplementation.h
	GLFWCode/OpenGLPicture.h
	GLFWCode/OpenGLRenderer.h
	GLFWCode/OpenGLShader.h
	Picture.h
	PictureImplementation.h
	Renderer.h
	RendererImplementation.h
	Shader.h
	ShaderImplementation.h
	Unit.h
	Utilities.h
	WindowImplementation.h
)

set(SOURCE_FILES
	Events.cpp
	GameWindow.cpp
	GLFWCode/GLFWImplementation.cpp
	GLFWCode/OpenGLPicture.cpp
	GLFWCode/OpenGLRenderer.cpp
	GLFWCode/OpenGLShader.cpp
	Picture.cpp
	Renderer.cpp
	Shader.cpp
	Unit.cpp
)

add_definitions(-DMK_DEBUG=2)
add_definitions(-DMEERKAT_LIB)

include_directories(../Meerkat)
include_directories(../glfw/include)
include_directories(../glad/include)
include_directories(../stbi)


add_library(Meerkat SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_precompile_headers(Meerkat PRIVATE pch.h)

target_link_libraries(Meerkat glfw)
target_link_libraries(Meerkat glad)
target_link_libraries(Meerkat stbi)