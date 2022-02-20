#include "GameObject.h"

//contructor 
//---------------------------------------------------------------
GameObject::GameObject(const int characterSymbol,const sf::Vector2f loc)
	: m_isDisposed(false), m_SpriteFrame(1, Down)
{
	m_Object.setTexture(ResourcesManagement::instance().getGameFigures(characterSymbol));
	m_Object.setScale(1.3, 1.3);
	m_Object.setPosition(loc);
}
//********************** Set functions **************************
//---------------------------------------------------------------
void GameObject::setPosition(const sf::Vector2f position)
{
	m_Object.setPosition(position);
}
//---------------------------------------------------------------
void GameObject::SetDisposed(const bool cond) {

	m_isDisposed = cond;
}
//---------------------------------------------------------------
void GameObject::setSpriteFrameRow(const int y)
{
	m_SpriteFrame.y = y;
}
//---------------------------------------------------------------
void GameObject::setSpriteFrameCol(const int x)
{
	m_SpriteFrame.x = x;
}
//---------------------------------------------------------------
void GameObject::setTextureRect(sf::IntRect frameRect)
{
	m_Object.setTextureRect(frameRect);
}

//---------------------- * Move Function * -----------------------
void GameObject::setMove(sf::Vector2f location) {
	    m_Object.move(location);
}

//********************** Get functions **************************
//---------------------------------------------------------------
sf::Vector2f  GameObject::getPosition() const
{
	return m_Object.getPosition();
}

//---------------------------------------------------------------
sf::Sprite GameObject::getObject() const 
{
	return m_Object;
}
//---------------------------------------------------------------
sf::Vector2i GameObject::getSpriteFrame() const
{
	return m_SpriteFrame;
}
//---------------------------------------------------------------
bool GameObject::isDisposed() const {

	return m_isDisposed;
}

//********************** Utilities functions ********************
//---------------------------------------------------------------

bool GameObject::checkCollision(const GameObject& other) const
{
	return m_Object.getGlobalBounds().intersects(other.getObject().getGlobalBounds());
}

//===============================================================
// Display Game Object
//---------------------------------------------------------------
void  GameObject::draw(sf::RenderWindow & window)
{
	window.draw(getObject());
}
