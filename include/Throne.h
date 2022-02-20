#pragma once

#include "StaticObject.h"

class Throne : public StaticObject {

public:
	 Throne(const sf::Vector2f);
	~Throne() {}
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision(GameObject&) override;

private:
};

