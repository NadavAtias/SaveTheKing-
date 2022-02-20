#include "SmartDwarf.h"
//constructors
//---------------------------------------------------------------
SmartDwarf::SmartDwarf(sf::Vector2f loc)
	:Dwarf(loc, 13)
{
}
//---------------------------------------------------------------
// function that sets the Dwarf to chase after the cuurent player
// by reciving the cuerrent player position
//---------------------------------------------------------------
void SmartDwarf::dwarfSmartDircetion(const sf::Vector2f currPlayer)
{
	static int Spriteframe_y = 0;
	float x, y;

	setOldPostion();

	if (currPlayer.y > getPosition().y)
	{
		y = 0.4;
		Spriteframe_y = Down;
	}
	else
	{
		y = -0.4;
		Spriteframe_y = Up;
	}

	if (currPlayer.x > getPosition().x)
	{
		x = 0.4;
		Spriteframe_y = Right;
	}
	else
	{
		x = -0.4;
		Spriteframe_y = Left;
	}

	setDirection(sf::Vector2f(x, y));
	setSpriteFrameRow(Spriteframe_y);
}
//---------------------------------------------------------------
// function that moves smart Dwarf
//---------------------------------------------------------------
void SmartDwarf::move(sf::Time timeFactor,  const sf::Vector2f currPlayer)
{
	dwarfSmartDircetion(currPlayer);
	
	if (inBoardLimit(getPositionWithOffset(timeFactor))) {
		setMove(this->dwarfMovement(timeFactor));
	}
	else
		this->dwarfDircetion();
}
