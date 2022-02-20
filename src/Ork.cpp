#include "Ork.h"
//contructor 
//-----------------------------------------------------------------------
Ork::Ork(const sf::Vector2f loc)
	: StaticObject(4, loc, true)
{}
//-----------------------------------------------------------------------
// Ork with any move object 
//---------------------------------------------------------------
void Ork::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}