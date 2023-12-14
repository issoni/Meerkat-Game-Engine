#pragma once
#include"Meerkat.h"
#include<iostream>

class MyGame : public mk::MeerkatApp<MyGame> {
public:
	MyGame();
	void OnUpdate() override; 
	void OnKeyPress(const mk::KeyPressed& e);
private: 
	mk::Picture indianaJones; 
	mk::Picture rocks; 
	long timer; 
	bool endGame;
	mk::Picture gameOver; 
};
