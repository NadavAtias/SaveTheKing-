#pragma once

#include "MovingObject.h"
class Dwarf : public MovingObject {

public:
	 Dwarf(const sf::Vector2f , const int);
	~Dwarf() {}

	// set functions
    //----------------------------------------------------------------
	void setDirection (const sf::Vector2f);
// Handle Collision functions 
//---------------------------------------------------------------
	virtual void handleCollision(GameObject& )        override;
	virtual void handleCollision(Teleport&   )        override;
	virtual void handleCollision(GiftTime&   )        override;
	virtual void handleCollision(GiftDwarf& )         override;


	virtual void handleCollision(Wall& )           override;
	virtual void handleCollision(Ork& )            override;
	virtual void handleCollision(Fire& )           override;

	virtual void handleCollision(Gate& )           override;
	virtual void handleCollision(Throne& )         override;
	
	virtual void handleCollision(King& )           override;//ignore
	virtual void handleCollision(Warrior& )        override;//ignore
	virtual void handleCollision(Thief& )          override;//ignore
	virtual void handleCollision(Mage& )           override;//ignore
	virtual void handleCollision(Dwarf& )          override;//ignore
	        void action         ();


	virtual void         dwarfDircetion()                          {}
	sf::Vector2f         dwarfMovement                  (sf::Time) ;
	virtual void         move                           (sf::Time, const sf::Vector2f) {}
	virtual sf::Vector2f getPositionWithOffset          (sf::Time) override;
	sf::Vector2f         getDirection                   ()            const;


private:
	sf::Clock    m_pass;
	sf::Vector2f m_direction;

};
