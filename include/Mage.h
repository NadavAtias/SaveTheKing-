#pragma once
#include "MovingObject.h"
#include "Fire.h"
class Mage : public MovingObject {

public:
	 Mage(const sf::Vector2f);
	~Mage() {}
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision(GameObject&)   override;
	virtual void handleCollision(Fire&)         override;
	virtual void handleCollision(Teleport&)     override;

};
