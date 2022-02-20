#include "Throne.h"
//contructor 
//-----------------------------------------------------------------------
Throne::Throne(const sf::Vector2f loc)
	: StaticObject(10, loc, false)
{}
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
// Throne with any move object 
//---------------------------------------------------------------
void Throne::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}