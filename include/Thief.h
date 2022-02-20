#pragma once
#include "MovingObject.h"
#include "Key.h"
#include "Gate.h"
class Thief : public MovingObject {

public:
	 Thief(const sf::Vector2f);
	~Thief() {}

	void setKey     (const bool )        ;
	bool getHoldKey ()           const   ;
	void draw       (sf::RenderWindow & ) override;
	// Handle Collision functions 
	//---------------------------------------------------------------
	virtual void handleCollision(GameObject&)  override;
	virtual void handleCollision(Key &)        override;
	virtual void handleCollision(Gate &)       override;
	
private:
	bool                              m_holdKey;
	sf::Sprite			              m_keyImage;
};
