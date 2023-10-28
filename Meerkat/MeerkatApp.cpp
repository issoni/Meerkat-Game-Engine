#include"pch.h"
#include "MeerkatApp.h"

namespace mk {
	template<typename T> 
	MeerkatApp<T>::MeerkatApp()
	{
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
		mWindow.Create("Game IS", 1000, 800);

		while (mShouldContinue) {
			OnUpdate(); 

			mWindow.SwapBuffers();
			mWindow.PollEvents();

		}
	}

	template<typename T>
	void MeerkatApp<T>::OnUpdate() {

	}
}