#include "Thief.h"
//-----------------------------------------------------------------------
Thief::Thief(const sf::Vector2f loc)
	: MovingObject(1, loc), m_holdKey(false)
{
	m_keyImage.setPosition(sf::Vector2f({ 125, 370 }));
	m_keyImage.setTexture(ResourcesManagement::instance().getGameFigures(8));
	m_keyImage.setScale(1.2, 1.2);
}

//============================================================================
//                             Set Function's   
//============================================================================

void Thief::setKey(const bool status) {
	m_holdKey = status;
}

//============================================================================
//                             Get Function's   
//============================================================================

bool Thief::getHoldKey() const {
	return m_holdKey;
}


//============================================================================
//      function to display to user if he has a Key or not (for better UI)
//============================================================================

void Thief::draw(sf::RenderWindow& window) {

	
	GameObject::draw(window);
	if (getHoldKey())
		window.draw(m_keyImage);
}


//============================================================================
//                        HandleCollision Function's   
//============================================================================


// Thief with Thief 
//---------------------------------------------------------------
void Thief::handleCollision(GameObject& gameObject)
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}
//---------------------------------------------------------------
// Thief with key - thief takes key (can only hold 1 !)
//---------------------------------------------------------------
void Thief::handleCollision(Key& gameObject)
{
	if (!getHoldKey()) {
		gameObject.SetDisposed(true);
		this->setKey(true);
		ResourcesManagement::instance().playSound(GrabKey);
	}
	else {
		this->moveBack();
	}

}
//---------------------------------------------------------------
// Thief with Gate - if he has key --> open the Gate
//---------------------------------------------------------------
void Thief::handleCollision(Gate& gameObject)
{
	if (getHoldKey()) {
		gameObject.SetDisposed(true);
		this->setKey(false);
		ResourcesManagement::instance().playSound(OpenGate);
	}
	else {
		this->moveBack();
	}

}


