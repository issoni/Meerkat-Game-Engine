#include"Meerkat.h"
#include"MyGame.h"
#include<iostream>

#include "MyGame.h"
/*
MyGame::MyGame() {
    SetKeyPressedCallback([this](const mk::KeyPressed& e) {OnKeyPress(e); });
    mRenderer.Init();
}

void MyGame::OnUpdate() {
    if (endGame) {
        Draw(gameOver);
        return; 
    }

    timer++; 
    int rockSpeed = timer / 100; 

    rocks.UpdateYCoord(rockSpeed); 

    if (mk::UnitsOverlap(indianaJones, rocks)) {
        endGame = true; 
    }

    mRenderer.Clear(); 

    Draw(indianaJones);
    Draw(rocks); 
}

void MyGame::OnKeyPress(const mk::KeyPressed& e) {
    int moveDistance = 50;
    if (e.GetKeyCode() == MEERKAT_KEY_LEFT) {
        indianaJones.UpdateXCoord(-moveDistance);
    }
    else if (e.GetKeyCode() == MEERKAT_KEY_RIGHT) {
        indianaJones.UpdateXCoord(moveDistance);
    }
}
*/