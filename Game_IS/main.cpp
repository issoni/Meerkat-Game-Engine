#include"Meerkat.h"

#include <iostream>
#include <vector>
#include <random>


class MyGame : public mk::MeerkatApp<MyGame> {
public:
	MyGame() {
		SetKeyPressedCallback([this](const mk::KeyPressed& e) {OnKeyPress(e); });
		mRenderer.Init();
		InitializeRocks();
	}

	virtual void OnUpdate() override
	{
		mRenderer.Clear();

		Draw(bg);

		if (endGame) {
			gameOver.SetCoords(250, 250);
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

	void OnKeyPress(const mk::KeyPressed& e) {
		int moveDistance = 10;
		if (e.GetKeyCode() == MEERKAT_KEY_LEFT) {
			indianaJones.UpdateXCoord(-moveDistance);
		}
		else if (e.GetKeyCode() == MEERKAT_KEY_RIGHT) {
			indianaJones.UpdateXCoord(moveDistance);
		}
	}


private:
	mk::Unit indianaJones{ "../Assets/Pictures/jones.png", 50, 100 };
	std::vector<mk::Unit> rocks;
	mk::Unit bg{ "../Assets/Pictures/cave.png", 0, 0 };
	long timer{ 0 };
	bool endGame{ false };
	mk::Unit gameOver{ "../Assets/Pictures/gameover.png", 300, 300 };
	mk::Renderer mRenderer;
	std::mt19937 ran{ std::random_device{}() };


	void InitializeRocks() {
		int startY = 800;  
		std::uniform_int_distribution<int> dist(0, 800); 

		for (int i = 0; i < 100; ++i) {
			int randomX = dist(ran); 
			rocks.emplace_back("../Assets/Pictures/rock.png", randomX, startY);
			startY += 50;  
		}
	}
};

MEERKAT_APPLICATION_START(MyGame);