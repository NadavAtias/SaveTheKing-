#include "Mage.h"
//contructor 
//-----------------------------------------------------------------------
Mage::Mage(const sf::Vector2f loc)
	: MovingObject(2, loc)
{}
//-----------------------------------------------------------------------
// Mage with Mage 
//---------------------------------------------------------------
void Mage::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
// Mage with Fire --> put out fire 
//---------------------------------------------------------------
void Mage::handleCollision(Fire& gameObject)
{
	gameObject.          SetDisposed(true);
	ResourcesManagement::instance().playSound(PutFire);
}
// Teleport with any move object Except from Thief
//---------------------------------------------------------------
void Mage::handleCollision(Teleport& )
{}