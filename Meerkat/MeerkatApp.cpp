#include"pch.h"
#include "MeerkatApp.h"
#include"Utilities.h"
#include"Meerkat.h"
#include"Shader.h"
#include"Picture.h"
#include"Renderer.h"

namespace mk {
	template<typename T> 
	MeerkatApp<T>::MeerkatApp()
	{
		mWindow.Create("Game IS", 1000, 800);
		mRenderer.Init();
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

	template<typename T>
	void MeerkatApp<T>::Init()
	{
		if (sInstance == nullptr)
			sInstance = new T; 
	}

	template<typename T>
	void MeerkatApp<T>::RunInterface()
	{
		sInstance->Run(); 
	}
	
	template<typename T>
	void MeerkatApp<T>::Run()
	{
		mk::Shader shader{ "../Assets/Shaders/DefaultVertexShader.glsl", "../Assets/Shaders/DefaultFragmentShader.glsl" };


		mNextFrameTime = std::chrono::steady_clock::now();

		while (mShouldContinue) {
			mRenderer.Clear();

			shader.Bind();
			shader.SetUniform2Ints("ScreenSize", mWindow.GetWidth(), mWindow.GetHeight());
			// mPic.Bind();

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			mWindow.SwapBuffers();
			mWindow.PollEvents();
		}
	}


	template<typename T>
	void MeerkatApp<T>::OnUpdate() {

	}

	
	
	template<typename T>
	void MeerkatApp<T>::Draw(int x, int y, Picture& pic) {
		mRenderer.Draw(x, y, pic);
	}

	template<typename T>
	void MeerkatApp<T>::Draw(Unit& item) {
		//item.mImage.Bind();
		mRenderer.Draw(item.GetXCoord(), item.GetYCoord(), item.mImage);
	}
	

	template<typename T>
	void MeerkatApp<T>::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		mWindow.SetKeyPressedCallback(callbackFunc);
	}

	template<typename T>
	void MeerkatApp<T>::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		mWindow.SetKeyReleasedCallback(callbackFunc);
	}

	template<typename T>
	void MeerkatApp<T>::SetWindowCloseCallback(std::function<void()> callBackFunc)
	{
		mWindow.SetWindowCloseCallback(callBackFunc);
	}

	template<typename T>
	void MeerkatApp<T>::DefaultWindowCloseHandler()
	{
		mShouldContinue = false; 
	}

}