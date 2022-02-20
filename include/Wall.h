#pragma once
#include "StaticObject.h"


class Wall : public StaticObject{

public:
	  Wall(const sf::Vector2f);
	 ~Wall() {}
	// Handle Collision functions 
    //---------------------------------------------------------------
	virtual void handleCollision(GameObject&)  override;

private:
};

