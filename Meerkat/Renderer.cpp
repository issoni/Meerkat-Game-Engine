#include "pch.h"
#include "Renderer.h"
#include "GLFWCode/OpenGLRenderer.h"

mk::Renderer::Renderer() {
#ifdef MEERKAT_MSCPP
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif MEERKAT_APPLE
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#elif MEERKAT_LINUX
	mImplementation = std::unique_ptr<RendererImplementation>{ new OpenGLRenderer };
#endif
}

void mk::Renderer::Init() {
	mImplementation->Init();
}

void mk::Renderer::Draw(int x, int y, Picture& pic) {
	mImplementation->Draw(x, y, pic);
}

void mk::Renderer::Clear() {
	mImplementation->Clear(); 
}