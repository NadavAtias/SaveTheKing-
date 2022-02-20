#pragma once
#include "GameObject.h"
#include "StaticObject.h"
#include "Teleport.h"
#include "GiftTime.h"
#include "GiftDwarf.h"


class MovingObject : public GameObject {

public:
	//contructor & descontructor
	//---------------------------------------------------------------
	               MovingObject         (const int, const sf::Vector2f);
		          ~MovingObject         ()       {}

	// handleCollision functions
	//---------------------------------------------------------------
	virtual void handleCollision                (GameObject&)           {};

	virtual void handleCollision                (Wall&)           override;
	virtual void handleCollision                (Ork& )           override;
	virtual void handleCollision                (Fire&)           override;
	virtual void handleCollision                (Key& )           override;
	virtual void handleCollision                (Gate&)           override;
	virtual void handleCollision                (Throne&)         override;
	virtual void handleCollision                (GiftTime&)       override;
	virtual void handleCollision                (GiftDwarf&)      override;
	virtual void handleCollision				(Teleport&)       override;
	
	virtual void handleCollision				(King&)    {};//ignore
	virtual void handleCollision				(Warrior&) {};//ignore
	virtual void handleCollision				(Thief& )   {};//ignore
	virtual void handleCollision				(Mage& )    {};//ignore
	virtual void handleCollision                (Dwarf& )   {};//ignore

	// Movment functions
	//---------------------------------------------------------------
	bool                   inBoardLimit(sf::Vector2f);
	virtual void           move(sf::Time, const sf::Vector2f);
	void                   moveBack();
	virtual sf::Vector2f   dircetion              (sf::Time ) const;
	
	// set functions
	//---------------------------------------------------------------
	sf::Vector2f           dirFromKey             ()          const;
	virtual void           setSpriteImageDirection(const sf::Event) override;
	void                   setTextureRectDefualt    ();
	void                   setOldPostion();
	void                   setMovingTextureRect();

	// get functions
    //---------------------------------------------------------------   
	virtual sf::Vector2f   getPositionWithOffset    (sf::Time);
	sf::Vector2f           getOldPosition           ()        const;

private:
	sf::Vector2f m_oldPostion;
};