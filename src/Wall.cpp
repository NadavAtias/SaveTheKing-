#include "Wall.h"
//contructor 
//---------------------------------------------------------------
Wall::Wall(const sf::Vector2f loc)
	: StaticObject(7, loc ,false)
{}
//---------------------------------------------------------------

// Handle Collision functions 
//---------------------------------------------------------------

// Wall with any move object 
//---------------------------------------------------------------
void Wall::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
