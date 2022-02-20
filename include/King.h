#pragma once
#include "MovingObject.h"
#include "Throne.h"

class King : public MovingObject {

public:
	 
	King      (const sf::Vector2f);
	
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision(GameObject&)  override;
	virtual void handleCollision(Throne&    )  override;

private:
};
