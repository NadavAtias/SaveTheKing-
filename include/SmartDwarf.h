#pragma once
#include "Dwarf.h"

class SmartDwarf : public Dwarf
{
public:
	//constructors & descontructor
   //-----------------------------------------------------
	 SmartDwarf(const sf::Vector2f);
	~SmartDwarf() {}
	
	void         dwarfSmartDircetion(const sf::Vector2f currPlayer);

	virtual void dwarfDircetion()             override {};

	virtual void move(sf::Time,  sf::Vector2f) override;
private:

};

