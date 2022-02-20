#pragma once

#include "StaticObject.h"

class GiftTime : public StaticObject {

public:
	  GiftTime(const sf::Vector2f);
	 ~GiftTime() {}
	// Handle Collision functions 
//---------------------------------------------------------------
	virtual void handleCollision(GameObject&) override;

	int giftRandomaizer();
	
//---------------------------------------------------------------

};

