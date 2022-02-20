#pragma once

#include "StaticObject.h"

class Fire : public StaticObject {

public:
	  Fire(const sf::Vector2f);
	 ~Fire() {}
	
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision     (GameObject&) override;
	virtual void setTextureStaticRect()                      override;

private:
};

