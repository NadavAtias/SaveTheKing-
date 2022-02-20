#include "Key.h"

//-----------------------------------------------------------------------
Key::Key(const sf::Vector2f loc)
	: StaticObject(8, loc, false)
{}
//-----------------------------------------------------------------------
// Key with any move object 
//---------------------------------------------------------------
void Key::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}

