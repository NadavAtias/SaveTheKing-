#pragma once
//------------------------ Include Section --------------------------
#include "ResourcesManagement.h"

//--------------------------- class section -------------------------
//						 *   Moving Object *                         
class King   ;
class Warrior;
class Thief  ;
class Mage   ;
class Dwarf  ;

//						 *   Static Object *                          

class Wall     ;
class Fire     ;
class Ork      ;
class Key      ;
class Gate     ;
class Throne   ;
class Teleport ;
class GiftTime ;
class GiftDwarf;


class GameObject {

public:
	//contructor & descontructor
	//---------------------------------------------------------------
	              GameObject          (const int ,const sf::Vector2f);
	virtual      ~GameObject          () = default;
    //********************** Get functions **************************
	//---------------------------------------------------------------
	sf::Vector2f  getPosition         ()const;
    sf::Sprite    getObject           ()const;
	sf::Vector2i  getSpriteFrame      ()const;
	//********************** Set functions **************************
   //---------------------------------------------------------------
	void		  setSpriteFrameRow(const int);
	void		  setSpriteFrameCol(const int);
	void          setTextureRect   (sf::IntRect);
    void          setMove          (sf::Vector2f );


	// Utilities functions
	//---------------------------------------------------------------
	bool checkCollision(const GameObject&) const;
	
	// handleCollision functions
    //---------------------------------------------------------------
	
	// handleCollision *  Moving Object *    
	//---------------------------------------------------------------
	virtual void handleCollision (GameObject&        ) = 0;
	virtual void handleCollision (King&              ) = 0;
	virtual void handleCollision (Warrior&           ) = 0;
	virtual void handleCollision (Thief&             ) = 0;
	virtual void handleCollision (Mage&              ) = 0;
	virtual void handleCollision (Dwarf&             ) = 0;

	// handleCollision *  Static Object *                            
	//---------------------------------------------------------------
	virtual void handleCollision (Wall&              ) = 0;
	virtual void handleCollision (Fire&              ) = 0;
	virtual void handleCollision (Ork&               ) = 0;
	virtual void handleCollision (Key&               ) = 0;
	virtual void handleCollision (Gate&              ) = 0;
	virtual void handleCollision (Throne&            ) = 0;
	virtual void handleCollision (Teleport&          ) = 0;
	virtual void handleCollision (GiftTime&          ) = 0;
	virtual void handleCollision (GiftDwarf&         ) = 0;

	//********************** Get functions *************************
	//---------------------------------------------------------------
	bool                 isDisposed()  const;

	//********************** Set functions *************************
    //---------------------------------------------------------------
	void                  setPosition               (const sf::Vector2f);
	void                  SetDisposed               (const bool);
	virtual void          setSpriteImageDirection   (const sf::Event)     = 0;
	// ******************  Display Game Object *********************
	//--------------------------------------------------------------- 
	virtual void          draw                (sf::RenderWindow &);
	//---------------------------------------------------------------
private:
	//--------------------------- Members ---------------------------
	sf::Sprite        m_Object;
	sf::Vector2i      m_SpriteFrame;
	bool              m_isDisposed;
};
	




