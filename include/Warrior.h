#pragma once

#include "MovingObject.h"
#include "Ork.h"
class Warrior : public MovingObject {

public:
	 Warrior(const sf::Vector2f);
	~Warrior() {}
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision(GameObject&) override;
	virtual void handleCollision(Ork& )       override;
	
private:
};
