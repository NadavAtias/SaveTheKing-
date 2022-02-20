#include "DumbDwarf.h"

//constructors
//---------------------------------------------------------------
DumbDwarf::DumbDwarf(const sf::Vector2f loc)
	:Dwarf(loc , 12)
{
}
//---------------------------------------------------------------
// function that sets Dwarfs Direction randommly 
//---------------------------------------------------------------
void DumbDwarf::dwarfDircetion()
{
	int direction = rand() % (4) + 0;
	static int Spriteframe_y = 0;

	switch (direction)
	{
	case Down:
	{
		setDirection(sf::Vector2f(0, 1));
		Spriteframe_y = Down;
		break;
	}
	case Left:
	{
		setDirection(sf::Vector2f(-1, 0));
		Spriteframe_y = Left;
		break;
	}
	case Right:
	{
		setDirection(sf::Vector2f(1, 0));
		Spriteframe_y = Right;
		break;
	}
	case Up:
	{
		setDirection(sf::Vector2f(0, -1));
		Spriteframe_y = Up;
		break;
	}

	default:
		break;
	}
	setSpriteFrameRow(Spriteframe_y);
}
//---------------------------------------------------------------
// function that moves Dumb Dwarf
//---------------------------------------------------------------
void DumbDwarf::move(sf::Time deltaTime , const sf::Vector2f)
{
	setOldPostion();

	if (inBoardLimit(getPositionWithOffset(deltaTime))) {
		setMove(this->dwarfMovement(deltaTime));
	}
	else
		this->dwarfDircetion();

}