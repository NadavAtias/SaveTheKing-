#pragma once

#include "StaticObject.h"

class Gate : public StaticObject {

public:
	 Gate(const sf::Vector2f);
	~Gate() {}
	// Handle Collision functions 
//---------------------------------------------------------------
	void handleCollision(GameObject&) override;

private:
};

