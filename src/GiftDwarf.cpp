#include "GiftDwarf.h"

//-----------------------------------------------------------------------
GiftDwarf::GiftDwarf(const sf::Vector2f loc)
	: StaticObject(11, loc, false)
{}
//-----------------------------------------------------------------------
// GiftTime with any move object 
//---------------------------------------------------------------
void GiftDwarf::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
