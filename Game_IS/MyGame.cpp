// Game: Help Indiana Jones! 
#include "MyGame.h"
#include <iostream>

MyGame::MyGame() {
	SetKeyPressedCallback([this](const mk::KeyPressed& e) {OnKeyPress(e); });
	mRenderer.Init();
	InitializeRocks();
}

void MyGame::OnUpdate() {
	mRenderer.Clear();

	// Static cave background
	Draw(bg);

	// Show game over scene
	if (endGame) {
		gameOver.SetCoords(320, 250);
		Draw(gameOver);
		return;
	}

	timer++;

	// Implementation of increasing speed of falling rocks
	int maxRockSpeed = 10;
	int speedIncrease = 100;
	for (size_t i = 0; i < rocks.size(); ++i) {
		if (timer > (i * 50)) {
			int rockSpeed = timer / speedIncrease;
			if (rockSpeed > maxRockSpeed) {
				rockSpeed = maxRockSpeed;
			}
			rocks[i].UpdateYCoord(-rockSpeed);

			// Collision detection
			if (mk::UnitsOverlap(indianaJones, rocks[i])) {
				endGame = true;
				break;
			}
		}
	}

	// Drawing of the multiple rocks
	if (!endGame) {
		Draw(indianaJones);
		for (auto& rock : rocks) {
			Draw(rock);
		}
	}
}

void MyGame::OnKeyPress(const mk::KeyPressed& e) {
	// Movement 
	if (e.GetKeyCode() == MEERKAT_KEY_LEFT) {
		indianaJones.UpdateXCoord(-10);
	}
	else if (e.GetKeyCode() == MEERKAT_KEY_RIGHT) {
		indianaJones.UpdateXCoord(10);
	}
}

void MyGame::InitializeRocks() {
	int startY = 800;
	std::uniform_int_distribution<int> dist(0, 800);

	// Random positions for several rocks to fall from top of screen
	for (int i = 0; i < 500; ++i) {
		int randomX = dist(ran);
		rocks.emplace_back("../Assets/Pictures/rock.png", randomX, startY);
		startY += 50;
	}
}


