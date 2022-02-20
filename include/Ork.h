#pragma once
#include "StaticObject.h"

class Ork : public StaticObject {

public:
	 Ork(const sf::Vector2f);
	~Ork() {};
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision(GameObject&) override;

private:
};

