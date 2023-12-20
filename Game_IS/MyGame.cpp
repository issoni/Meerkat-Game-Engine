// Game: Help Indiana Jones! 
#include "MyGame.h"
#include <iostream>

MyGame::MyGame() {
	SetKeyPressedCallback([this](const mk::KeyPressed& e) {OnKeyPress(e); });
	SetKeyReleasedCallback([this](const mk::KeyReleased& e) { OnKeyRelease(e); });
	mRenderer.Init();
	InitializeRocks();
}

void MyGame::OnUpdate() {
	const int moveDistance = 10;
	const int windowWidth = 1000;
	const int characterWidth = 90; 

	// Update indianaJones position based on key press and bounds checking
	if (leftKeyPressed && indianaJones.GetXCoord() > 0) {
		indianaJones.UpdateXCoord(-moveDistance);
	}
	if (rightKeyPressed && indianaJones.GetXCoord() < (windowWidth - characterWidth)) {
		indianaJones.UpdateXCoord(moveDistance);
	}

	mRenderer.Clear();

	// Static cave background
	Draw(cave);

	// Show game over scene
	if (endGame) {
		gameOver.SetCoords(320, 250);
		Draw(gameOver);
		return;
	}

	timer++;

	// Implementation of increasing speed of falling rocks
	int maxRockSpeed = 1000;
	int speedIncrease = 85;
	int baseSpeed = 4;
	for (size_t i = 0; i < rocks.size(); ++i) {
		if (timer > (i * 50)) {
			int rockSpeed = baseSpeed + (timer / speedIncrease);
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

// Smooth movement 
void MyGame::OnKeyPress(const mk::KeyPressed& e) {
	if (e.GetKeyCode() == MEERKAT_KEY_LEFT) {
		leftKeyPressed = true;
	}
	else if (e.GetKeyCode() == MEERKAT_KEY_RIGHT) {
		rightKeyPressed = true;
	}
}

void MyGame::OnKeyRelease(const mk::KeyReleased& e) {
	if (e.GetKeyCode() == MEERKAT_KEY_LEFT) {
		leftKeyPressed = false;
	}
	else if (e.GetKeyCode() == MEERKAT_KEY_RIGHT) {
		rightKeyPressed = false;
	}
}

void MyGame::InitializeRocks() {
	int startY = 800;
	std::uniform_int_distribution<int> dist(0, 800);

	// Random positions for several rocks to fall from top of screen
	for (int i = 0; i < 500; ++i) {
		int randomX = dist(ran);
		rocks.emplace_back("../Assets/Pictures/rock.png", randomX, startY);
		startY += 20;
	}
}


