#include "GiftDwarfVanish.h"

//-----------------------------------------------------------------------
GiftDwarfVanish::GiftDwarfVanish(sf::Vector2f loc)
	: StaticObject(11, loc, false)
{}
//-----------------------------------------------------------------------
// GiftTime with any move object 
//---------------------------------------------------------------
void GiftDwarfVanish::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
