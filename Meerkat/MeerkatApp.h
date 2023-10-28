#pragma once

#include"Utilities.h"
#include"GameWindow.h"

namespace mk {
	template<typename T>
	class MeerkatApp {
	public:
		static void Init();
		static void RunInterface();

		void Run();
		virtual void OnUpdate();

		friend typename T;

	private:
		MeerkatApp();

		inline static MeerkatApp* sInstance{ nullptr };

		GameWindow mWindow;

		bool mShouldContinue{ true };
	};
};

#include"MeerkatApp.cpp"
