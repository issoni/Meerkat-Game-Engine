#include"Meerkat.h"

#include<iostream>

class MyGame : public mk::MeerkatApp<MyGame> {
public:
	virtual void OnUpdate() override
	{
		std::cout << "Meerkat running" << std::endl; 
	}
};

MEERKAT_APPLICATION_START(MyGame);