#include "King.h"
//contructor 
//-----------------------------------------------------------------------
King::King(const sf::Vector2f loc)
	: MovingObject(0, loc)
{}

// Handle Collision functions 
//---------------------------------------------------------------

// King with any Object
//---------------------------------------------------------------
void King::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}

// King with Throne 
//---------------------------------------------------------------
void King::handleCollision(Throne& gameObject)
{
	sf::Clock soundTime;
	gameObject.SetDisposed(true);
	ResourcesManagement::instance().playSound(Win);
}


