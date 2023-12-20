#pragma once

#include "Meerkat.h"
#include <vector>
#include <random>
#include <iostream>

class MyGame : public mk::MeerkatApp<MyGame> {
public:
    MyGame();
    virtual void OnUpdate() override;

private:
    void OnKeyPress(const mk::KeyPressed& e);
    void OnKeyRelease(const mk::KeyReleased& e);
    void InitializeRocks();

    mk::Unit indianaJones{ "../Assets/Pictures/jones.png", 80, 100 };
    std::vector<mk::Unit> rocks;
    mk::Unit cave{ "../Assets/Pictures/treasurecave.png", 0, 0 };
    mk::Unit gameOver{ "../Assets/Pictures/over.png", 320, 250 };
    mk::Renderer mRenderer;
    std::mt19937 ran{ std::random_device{}() };

    long timer{ 0 };
    bool endGame{ false };
    bool leftKeyPressed = false;
    bool rightKeyPressed = false;
};
