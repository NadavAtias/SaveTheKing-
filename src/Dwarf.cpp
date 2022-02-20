#include "Dwarf.h"
//contructor 
//----------------------------------------------------------------
Dwarf::Dwarf(const sf::Vector2f loc , const int ImageIndex)
	: MovingObject(ImageIndex, loc), m_direction(1, 0)
{}


//============================================================================
//                        HandleCollision Function's   
//============================================================================

//---------------------------------------------------------------
// Dwarf with any Object
//---------------------------------------------------------------
void Dwarf::handleCollision(GameObject& gameObject )
{
	if (&gameObject == this) return;
	// double dispatch
	gameObject.handleCollision(*this);
}

// Teleport with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Teleport& )
{
	action();
}
// GiftTime with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(GiftTime& )
{
	action( );
}
// GiftDwarfVanish with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(GiftDwarf& )
{
	action( );
}
// Wall with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Wall& )
{
	action( );
}
// Ork with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Ork& )
{
	action( );
}
// Fire with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Fire& )
{
	action( );
}
// Gate with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Gate& )
{
	action( );
}
// Throne with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Throne&)
{

}
// King with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(King& )
{
	action( );
}
// Warrior with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Warrior& )
{
	action( );
}
// Thief with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Thief& )
{
	action( );
}
// Mage with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Mage& )
{
	action( );
}
// Dwarf with Dwarf
//---------------------------------------------------------------
void Dwarf::handleCollision(Dwarf& )
{
	action( );
}
//---------------------------------------------------------------
void Dwarf::action()
{
	this->moveBack      ();
	this->dwarfDircetion();
}


//============================================================================
//                        Dwarf movment Function's   
//============================================================================

//---------------------------------------------------------------
void Dwarf::setDirection(const sf::Vector2f newLocation)
{
	m_direction = newLocation;
}

//---------------------------------------------------------------
sf::Vector2f Dwarf::dwarfMovement(sf::Time deltaTime)
{
	static int Spriteframe_x = 0;

	if (m_pass. getElapsedTime().asSeconds() > (float)0.25) {
		m_pass. restart();
		Spriteframe_x++;
	}
	setSpriteFrameCol   (Spriteframe_x); // changes images frame for animation 
	setMovingTextureRect();
	if (Spriteframe_x * 32 >= SPRITE_SHEET_WIDTH) {
		Spriteframe_x = 0;
	}

	return (m_direction * (float)100.0 * deltaTime.asSeconds());
}


//============================================================================
//                        Get Function's   
//============================================================================
sf::Vector2f Dwarf::getPositionWithOffset(sf::Time deltaTime)
{
	return this->getPosition() + dwarfMovement(deltaTime);
}
//-----------------------------------------------------------------------
sf::Vector2f Dwarf::getDirection() const 
{
	return m_direction;
}
//-----------------------------------------------------------------------