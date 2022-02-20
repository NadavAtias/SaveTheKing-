#include "StaticObject.h"

//-----------------------------------------------------------
StaticObject::StaticObject(const int characterSymbol, const sf::Vector2f loc, const bool animaetd)
	:GameObject(characterSymbol, loc), m_spriteSheet(animaetd)
{}
//============================================================================
//                             Get Function's   
//============================================================================
//-----------------------------------------------------------
bool StaticObject::getSpriteSheet() const {
	return m_spriteSheet;
}
//-----------------------------------------------------------
sf::Clock StaticObject::getFrameTimer() const
{
	return m_frameTimer;
}
//============================================================================
//                             Set Function's   
//============================================================================
//-----------------------------------------------------------
void StaticObject::setTextureStaticRect()
{
	static int Spriteframe_x = 0;
	if (getSpriteSheet()) {
		if (getFrameTimer().getElapsedTime().asSeconds() > (float)0.25) {
			setRestratTimer();
			Spriteframe_x++;
			if (Spriteframe_x * 32 >= SPRITE_SHEET_WIDTH) {
				Spriteframe_x = 0;
			}
		}
	}
	setSpriteFrameCol(Spriteframe_x);
	setSpriteFrameRow(Down);
	setTextureRect(sf::IntRect(getSpriteFrame().x * 32, 0, 32, 32));
}
//-----------------------------------------------------------
void StaticObject::setRestratTimer()
{
	m_frameTimer.restart();
}
