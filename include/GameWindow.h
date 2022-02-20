#pragma once
//------------------------- Include Section ------------------------------ 

#include "GameObject.h"
#include "ResourcesManagement.h"


class GameWindow {

public:
	//constructors
	//---------------------------------------------------------------
	 GameWindow();
	 ~GameWindow() {}
	//---------------------------------------------------------------
	//Set Function
	//---------------------------------------------------------------
	void setNextLevel      ();
	void resetLevels       ();
	void setLevelTime      (const int);
	void setPlayer         ();
	void setPauseGame      (const bool );
	void setLevelTimer     ();
	void trackingWithMouse(sf::Vector2f&);
	void setVainshDwarfMsg(const int , sf::Vector2f);
	void stopGameMusic     ();
	void setUpdateTimeLevel(sf::Vector2f, const int);
	void setTextureFigure  ();
	void setTextLife       ();
	void updateLife        ();
	void resetLife         ();
	void playGameMusic     ();
	//---------------------------------------------------------------
	//Get Functions
	//---------------------------------------------------------------
	int   getPlayer       () const;
	int   getCurrLevel    () const;
	bool  getTimePassed   () const;
	int   getLife         () const;
	bool  getPauseGame    () const;

	bool getMute() const;

	void containInVolume(sf::Vector2f& mouseLocation);

	bool containInNext(sf::Vector2f&) const ;

   //---------------------------------------------------------------
   //draw Game Window Functions
   //---------------------------------------------------------------
	void draw            (sf::RenderWindow &);
	void drawGameStatus  (sf::RenderWindow & , const int, const float,const bool);
	void drawPauseGame   (sf::RenderWindow &);

private:

	//Prviate Function
	void initNextButton    ();
	void initVolumeButton  ();
	void initText          (sf::Text&);
	void initPauseGameText ();
	void setText           (const int);
	void setLevelTexture   ();
	void timerDesign       ();

	//--------------------------- Members ------------------------------- 
	sf::Sprite			              m_levelBackground;
	sf::Sprite			              m_imageFigure    ;
	sf::Sprite			              m_volumeImgae    ;
	sf::RectangleShape			      m_pauseGame      ;
	sf::RectangleShape			      m_nextLevel      ;
	sf::RectangleShape			      m_volume         ;
	sf::Text                          m_giftTimeText   ;
	sf::Text                          m_nameFigure     ;
	sf::Text                          m_numOfLife      ;
	sf::Clock                         m_timer          ;
    sf::Text                          m_timerText      ;
	int                               m_Level          ;
	int                               m_Life           ;
	int							      m_currPlayer     ;
	int                               m_timeMin        ;
	int                               m_timeSec        ;
	bool                              m_pause          ;
	bool                              m_mute           ;	
};