#pragma once
#include "GameWindow.h"
#include "Board.h"
#include "King.h"
#include "Wall.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "GiftDwarf.h"
#include "DumbDwarf.h"
#include "SmartDwarf.h"
#include "Teleport.h"



class DataManagement {

public:
	//constructors & descontructor
    //---------------------------------------------------------------
	           DataManagement                   (GameWindow*);
			  ~DataManagement				   () {};
	//---------------------------------------------------------------
    //Utilities Functions
	void         update              (const int );
	void         handleResetLevel    ();
	void         moveObject          (const int  ,  sf::Time);
	void         beginOfLevelFiles   ();
	void         updateCharactersGame(const char ,  sf::Vector2f );
	void         randomizeDwarf      (const sf::Vector2f);
	void         drawMoveObject      (const int ,sf::RenderWindow&);
	void         drawStaticObject    (sf::RenderWindow &);
    
	//---------------------------------------------------------------
    //Set Function
	void         setTexture          ();
	void         setSpriteDirection  (sf::Event);
	void         setlevelTime        ();
	void         setNewLevel         ();
  
	//---------------------------------------------------------------
	//Get Function
	bool         getlevelEnd         () const;

private:
	//---------------------------------------------------------------
	//Set private Function
	void setlevelEnd            (const bool );
	void reSizeMovingObject     ();
	void orkDisposed            (StaticObject& ); // replace the ork with key 
	void pairTeleport           ();
	std::vector<int> findTeleportIndex();
	void setPairTeleport        (const int, const int);
	void VanishDwarfs           (const bool);
	void randomGiftDwarf        (sf::Vector2f);
	//---------------------------------------------------------------
	void handleCollisions       (MovingObject& , const bool);
	void handleCollisionsStatic (MovingObject& );
	void updateStaticVector     ();
	void eraseDwarf             ();
	void eraseStaticObject      ();
	void handleTeleportCollision (std::unique_ptr<StaticObject>& );
	bool notCollisionWithTeleport(Teleport* );
	void GiftDwarfDisposed       (StaticObject& );
	void gameEnd                 (StaticObject& );
	void giftTimeDisposed        (std::unique_ptr<StaticObject>& );

	//---------------------------------------------------------------
	// Private Member
	Board             m_gameBoard;
	GameWindow*       m_p2GameWindow;
	sf::Clock         m_gameClock;
	bool              m_levelEnd;
	//---------------------------------------------------------------
    //vectors
	std::vector       <std::unique_ptr <MovingObject>> m_movingObject;
	std::vector       <std::unique_ptr <StaticObject>> m_staticObject;
    //---------------------------------------------------------------
};

