#include "GiftTime.h"

//-----------------------------------------------------------------------
GiftTime::GiftTime(const sf::Vector2f loc)
	: StaticObject(11, loc, false)
{}
//-----------------------------------------------------------------------
// GiftTime with any move object 
//---------------------------------------------------------------
void GiftTime::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
//---------------------------------------------------------------
int GiftTime::giftRandomaizer()
{
	return  rand() % 50 + (-25);
}
