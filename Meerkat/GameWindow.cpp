#include"pch.h"
#include"GameWindow.h"
#include "GLFWCode/GLFWImplementation.h"

namespace mk {
	GameWindow::GameWindow()
	{
#ifdef MEERKAT_MSCPP
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif MEERKAT_APPLE
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#elif MEERKAT_LINUX
		mImplementation = std::unique_ptr<WindowImplementation>{ new GLFWImplementation };
#endif
	}
	void GameWindow::Create(const std::string& name, int width, int height)
	{
		mImplementation->Create(name, width, height);
	}
	int GameWindow::GetHeight() const
	{
		return mImplementation->GetHeight();
	}
	int GameWindow::GetWidth() const
	{
		return mImplementation->GetWidth();
	}
	void GameWindow::SwapBuffers()
	{
		mImplementation->SwapBuffers(); 
	}
	void GameWindow::PollEvents()
	{
		mImplementation->PollEvents();
	}
}