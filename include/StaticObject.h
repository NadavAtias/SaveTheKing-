#pragma once
//------------------------ Include Section --------------------------
#include "GameObject.h"

class StaticObject : public GameObject {
public:
	//constructors
	//---------------------------------------------------------------
	          StaticObject       (const int, const sf::Vector2f , const bool);
			 ~StaticObject       () {}
	//---------------------------------------------------------------
	//Set Function
	//---------------------------------------------------------------
	virtual  void    setTextureStaticRect   ();
	void             setSpriteImageDirection(const sf::Event)    override {};
	void             setRestratTimer        ();
	//---------------------------------------------------------------
	//Get Functions
	//---------------------------------------------------------------
	bool      getSpriteSheet()  const;
	sf::Clock getFrameTimer()   const;
	
	void handleCollision(GameObject& ) {};
	 
	void handleCollision(King& )            override {}
	void handleCollision(Warrior& )         override {}
	void handleCollision(Thief& )           override {}
	void handleCollision(Mage& )            override {}
	void handleCollision(Dwarf& )           override {}

	void handleCollision(Wall& )            override {}
	void handleCollision(Fire& )            override {}
	void handleCollision(Ork& )             override {}
	void handleCollision(Key& )             override {}
	void handleCollision(Gate& )            override {}
	void handleCollision(Throne& )          override {}
	void handleCollision(Teleport& )        override {}
	void handleCollision(GiftTime & )       override {}
	void handleCollision(GiftDwarf& )       override {}

private:
	//--------------------------- Members ---------------------------
	bool      m_spriteSheet;
	sf::Clock m_frameTimer ;
};