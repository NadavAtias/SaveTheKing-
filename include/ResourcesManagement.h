#pragma once
#include "Features.h"

/**
 * The ResourcesManagement class using Singleton method and
   defines the `GetInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */
class ResourcesManagement {

public:
	~ResourcesManagement() = default;
	static ResourcesManagement& instance();
	ResourcesManagement(const ResourcesManagement&) = delete; //Singletons should not be cloneable.
	void operator=     (const ResourcesManagement&) = delete; // Singletons should not be assignable.

    //fonts 
	void       initFont      ();
	sf::Font&  getFont       ();

    // music & sound 
	void       initMusic     ();
	void       initSounds    ();
	sf::Music& getMenuMusic  ();
	sf::Music& getGameMusic  (const int );
	void       playSound     (const int);
	void       stopSound     (const int);

	// Images
	//---------------------------------------------------------------
	// Background Images
	void         initImages();
	sf::Texture& getBackgroundImage (const int );  
	sf::Texture& getLevelImage      (const int );
	sf::Texture& getCurrPlayerImage (const int );
	sf::Texture& getGameFigures     (const int );


private:
	ResourcesManagement() ;
	
	// fonts
	//---------------------------------------------------------------
	sf::Font                             m_font;
	
	
	// music & sound 
	//---------------------------------------------------------------
	sf::Music                            m_menuMusic;
	sf::Music                            m_gameMusic   [MUSIC+1];
    sf::SoundBuffer                      m_soundBuffers[SOUNDEFFECTS];
	sf::Sound                            m_playSounds  [SOUNDEFFECTS];

	
	// Images 
	//---------------------------------------------------------------
	std::vector <sf::Texture            > m_backGroundImages;
	std::vector <sf::Texture            > m_levelsImages;
	std::vector <sf::Texture            > m_currPlayer;
	std::vector <sf::Texture            > m_gameFigures;
 };