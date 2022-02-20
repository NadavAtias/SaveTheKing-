#include "Gate.h"

//-----------------------------------------------------------------------
Gate::Gate(const sf::Vector2f loc)
	: StaticObject(9, loc, false)
{}
//-----------------------------------------------------------------------
// Gate with any move object 
//---------------------------------------------------------------
void Gate::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
