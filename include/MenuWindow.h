#pragma once
//------------------------ Include Section --------------------------
#include "ResourcesManagement.h"

class MenuWindow 
{
public:
	//constructors
	//---------------------------------------------------------------
	MenuWindow();
	//---------------------------------------------------------------
	//Set Function
    //---------------------------------------------------------------
	void                  setBackButton      (sf::RectangleShape);
	void                  setStratPlay       (const char);
	void                  stopMenuMusic      ();
	void                  playMenuMusic      ();
	//---------------------------------------------------------------
	//Get Functions
	//---------------------------------------------------------------
	char                  getIconMenu        (const int)		  const;
	char                  getCurrIcon        ()		              const;
	bool			      getStratPlay       ()                   const;
	sf::RectangleShape    getIconButton      (const int)          const;
	//---------------------------------------------------------------
	//Utilities Functions
	//---------------------------------------------------------------
	void			      containInMenu	     (sf::Vector2f &);
	void			      containInHelpMenu  (sf::Vector2f &);
	void                  trackingWithMouse  (sf::Vector2f &);
	void                  initButtons        ();
	void			      printMenu          ( sf::RenderWindow   &) ;
    void                  openingScreen      (sf::RenderWindow    &) ;
 
private:
	//---------------------------------------------------------------
	//vectors
	//---------------------------------------------------------------
	std::vector <sf::RectangleShape	    > m_buttons;
	//---------------------------------------------------------------
	sf::Sprite			                 m_backgroundImage;
	sf::Music                            m_menuSound;
	char                                 m_Icon;
};
