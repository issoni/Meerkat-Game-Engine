#include"Meerkat.h"

#include<iostream>

class MyGame : public mk::MeerkatApp<MyGame> {
public:
	MyGame() {
		SetKeyPressedCallback([this](const mk::KeyPressed& e) {OnKeyPress(e); });
	}

	virtual void OnUpdate() override
	{
		//std::cout << "Meerkat running" << std::endl; 
		Draw(x, y, mPic);
		//Draw(mUnit);
	}

	void OnKeyPress(const mk::KeyPressed& e) {
		if (e.GetKeyCode() == MEERKAT_KEY_RIGHT)
			x += 50;
			// mUnit.UpdateXCoord(50);
		else if (e.GetKeyCode() == MEERKAT_KEY_LEFT)
			x += 50; 
			// mUnit.UpdateXCoord(-50);
	}

private:
	mk::Picture mPic{ "../Assets/Pictures/test.png" }; 
	mk::Unit mUnit{ "../Assets/Pictures/test.png", 100, 500 };

	int x{ 100 };
	int y{ 100 };
};

MEERKAT_APPLICATION_START(MyGame);