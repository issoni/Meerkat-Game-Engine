#pragma once
#include"Meerkat.h"
#include<iostream>

class MyGame : public mk::MeerkatApp<MyGame> {
public:
	MyGame();
	void OnUpdate() override; 
	void OnKeyPress(const mk::KeyPressed& e);
private:

	mk::Unit indianaJones{ "../Assets/Pictures/jones.png", 100, 500 };
	mk::Unit rocks{ "../Assets/Pictures/rock.png", 100, 500 };
	long timer{ 0 };
	bool endGame{ false };
	mk::Unit gameOver{ "../Assets/Pictures/gameover.jpg", 100, 500 };


};
