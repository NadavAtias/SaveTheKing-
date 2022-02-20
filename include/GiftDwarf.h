#pragma once

#include "StaticObject.h"

class GiftDwarf : public StaticObject {

public:
	   GiftDwarf (sf::Vector2f);
	  ~GiftDwarf() {}

	// Handle Collision functions 
//---------------------------------------------------------------
	virtual	void handleCollision(GameObject&) override;
	
//---------------------------------------------------------------

};

