#pragma once

#include "StaticObject.h"

class GiftDwarfVanish : public StaticObject {

public:
	GiftDwarfVanish(sf::Vector2f);

	// Handle Collision functions 
//---------------------------------------------------------------
	void handleCollision(GameObject&, sf::Time) override;
	
//---------------------------------------------------------------

};

