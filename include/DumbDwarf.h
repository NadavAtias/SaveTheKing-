#pragma once
#include "Dwarf.h"

class DumbDwarf: public Dwarf
{
public:
	//constructors & descontructor
   //-----------------------------------------------------
	 DumbDwarf(const sf::Vector2f);
	~DumbDwarf() {}

	virtual void dwarfDircetion()         override;

	virtual void move          (sf::Time, const sf::Vector2f) override;
private:

};

