#include "Warrior.h"
//contructor 
//---------------------------------------------------------------
Warrior::Warrior(const sf::Vector2f loc)
	: MovingObject(3, loc)
{}

// Warrior with Warrior 
//---------------------------------------------------------------
void Warrior::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}

//---------------------------------------------------------------
// warrior with ork - kills the ork  
//---------------------------------------------------------------
void Warrior::handleCollision(Ork& gameObject)
{
	gameObject.SetDisposed(true);
	ResourcesManagement::instance().playSound(KillOrk);
}

