#pragma once

#include "StaticObject.h"

class Key : public StaticObject {

public:
	 Key(const sf::Vector2f);
	~Key() {}
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision(GameObject&)  override;

private:
};

