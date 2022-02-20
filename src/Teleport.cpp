#include "Teleport.h"

//-----------------------------------------------------------------------
Teleport::Teleport(const sf::Vector2f loc)
	: StaticObject(5, loc, false), m_lockTeleport(true), m_pairedTeleport(nullptr)
{}
//---------------------------------------------------------------

// Handle Collision functions 
//---------------------------------------------------------------

// Teleport with 3 moving objects (KING THIEF WARRIOR)
//---------------------------------------------------------------
void Teleport::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	if (getLockTeleport()) {
		gameObject.handleCollision(*this);
	}

}
//============================================================================
//                             Set Function's   
//============================================================================

void Teleport::setLockTeleport(const bool status) {
	m_lockTeleport = status;
}
//---------------------------------------------------------------
void Teleport::setPairdTeleport(const Teleport* teleport) {
	m_pairedTeleport = (Teleport*)teleport;
}
//============================================================================
//                             Get Function's   
//============================================================================

bool Teleport::getLockTeleport() const {
	return m_lockTeleport;
}
//---------------------------------------------------------------
Teleport* Teleport::getPairdTeleport() const {
	return m_pairedTeleport;
}