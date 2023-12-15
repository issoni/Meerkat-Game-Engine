#include "MyGame.h"
#include <iostream>

MyGame::MyGame() {
	SetKeyPressedCallback([this](const mk::KeyPressed& e) {OnKeyPress(e); });
	mRenderer.Init();
	InitializeRocks();
}

void MyGame::OnUpdate() {
	mRenderer.Clear();

	Draw(bg);

	if (endGame) {
		gameOver.SetCoords(320, 250);
		Draw(gameOver);
		return;
	}

	timer++;

	int maxRockSpeed = 10;
	int speedIncrease = 100;
	for (size_t i = 0; i < rocks.size(); ++i) {
		if (timer > (i * 50)) {
			int rockSpeed = timer / speedIncrease;
			if (rockSpeed > maxRockSpeed) {
				rockSpeed = maxRockSpeed;
			}
			rocks[i].UpdateYCoord(-rockSpeed);

			if (mk::UnitsOverlap(indianaJones, rocks[i])) {
				endGame = true;
				break;
			}
		}
	}

	if (!endGame) {
		Draw(indianaJones);
		for (auto& rock : rocks) {
			Draw(rock);
		}
	}
}

void MyGame::OnKeyPress(const mk::KeyPressed& e) {
	int moveDistance = 10;
	if (e.GetKeyCode() == MEERKAT_KEY_LEFT) {
		indianaJones.UpdateXCoord(-moveDistance);
	}
	else if (e.GetKeyCode() == MEERKAT_KEY_RIGHT) {
		indianaJones.UpdateXCoord(moveDistance);
	}
}

void MyGame::InitializeRocks() {
	int startY = 800;
	std::uniform_int_distribution<int> dist(0, 800);

	for (int i = 0; i < 500; ++i) {
		int randomX = dist(ran);
		rocks.emplace_back("../Assets/Pictures/rock.png", randomX, startY);
		startY += 50;
	}
}


