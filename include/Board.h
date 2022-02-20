#pragma once
//------------------------ Include Section --------------------------
#include "Features.h"

class DataManagement;

//------------------------ Const Section ----------------------------

class Board
{
public:
	
	//Constructors & Destructors
	//---------------------------------------------------------------
	  Board();
	 ~Board();
	//---------------------------------------------------------------
	//Get & Set  functions
	//---------------------------------------------------------------
	char                    getChar                    ( const int , const int ) const;
	std::vector<std::string>getLevelRows               ()      const;
	int                     getTimeLevel               ()   const;
    void                    initCharacters             ( DataManagement& );
    bool                    setNewLevel                ();
	//---------------------------------------------------------------	
	// Initializiton functions
	//---------------------------------------------------------------
	void                    designBoard                ();
	//---------------------------------------------------------------	
	// Utilities functions
	//---------------------------------------------------------------
	void                     beginOfLevelFiles           ();
	sf::Vector2f             calcBoardLocation           (const int, const int);
	void                     drawBoard                   (sf::RenderWindow &);
	bool                     validFigure                 (const char ) const;


private:
	//--------------------------------------------------
	int                      m_timeLevel;
	std::vector<std::string> m_levelrows;
	std::ifstream            m_levelsFile;
	sf::RectangleShape       m_Board;
};

