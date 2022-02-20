#include "Fire.h"
//contructor 
//-----------------------------------------------------------------------
Fire::Fire(const sf::Vector2f loc)
	: StaticObject(6, loc, true)
{}
//-----------------------------------------------------------------------

// Fire with any move object 
//-----------------------------------------------------------------------
void Fire::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
//-----------------------------------------------------------------------
// function for animation of the fire object
//-----------------------------------------------------------------------
void Fire::setTextureStaticRect()
{
	static int Spriteframe_y = 0;
	if (getFrameTimer().getElapsedTime().asSeconds() > (float)0.15) {
		setRestratTimer();
		Spriteframe_y++;
		if (Spriteframe_y * 48 >= 265) {
			Spriteframe_y = 0;
		}
	}
      
	setSpriteFrameRow(Spriteframe_y);        
	setTextureRect(sf::IntRect(15, getSpriteFrame().y * 48, 20, 32));
}
