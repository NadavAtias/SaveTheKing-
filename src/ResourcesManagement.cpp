
#include "ResourcesManagement.h"

//Constructor
//---------------------------------------------------------------
ResourcesManagement::ResourcesManagement() {
	this->initFont();
	this->initMusic();
	this->initSounds();
	this->initImages();
}
//---------------------------------------------------------------
ResourcesManagement& ResourcesManagement::instance()
{
	static ResourcesManagement instance;
	return instance;
}
// fonts 
//---------------------------------------------------------------
void ResourcesManagement::initFont()
{
	m_font.loadFromFile("FONT_ARCADE.TTF");
}

// music & sound 
//---------------------------------------------------------------
void ResourcesManagement::initMusic()
{
	//m_menuMusic.openFromFile("Opening.wav");
	m_menuMusic.openFromFile("introduction.wav");
	for (int i = 0; i < MUSIC ; i++)
	{
		m_gameMusic[i].openFromFile(LEVEL_MUSIC[i]);
	}
}
//---------------------------------------------------------------
void ResourcesManagement::initSounds()
{
	for (int i = 0; i < SOUNDEFFECTS; i++)
	{
		m_soundBuffers[i].loadFromFile(SOUND_EFFECTS[i]);
		m_playSounds[i].setBuffer(m_soundBuffers[i]);
	}
}
//                     End of Get Function's
//===============================================================
// Images 
//---------------------------------------------------------------
// funcion that creats all menu buttons
//---------------------------------------------------------------
void ResourcesManagement::initImages() {

	auto imageFile = sf::Texture();

	for (int i = 0; i < NUM_OF_IMAGE - 1; i++)
	{
		imageFile.loadFromFile(MENU_FILE_IMAGE[i]);
		imageFile.setSmooth(true);
		m_backGroundImages.push_back(imageFile);
	}

	for (int i = 0; i < NUM_OF_LEVEL + 8; ++i) {
		imageFile.loadFromFile(LEVEL_IMAGES[i]);
		imageFile.setSmooth(true);
		m_levelsImages.push_back(imageFile);
	}

	for (int i = 0; i < NUM_OF_MAIN_CHAR; ++i) {
		imageFile.loadFromFile(CUUR_PLAYER[i]);
		imageFile.setSmooth(true);
		m_currPlayer.push_back(imageFile);
	}

	for (int i = 0; i < NUM_OF_GAME_CHAR; ++i) {
		imageFile.loadFromFile(CHARACTERS_NAMES[i]);
		imageFile.setSmooth(true);
		m_gameFigures.push_back(imageFile);
	}
}
//===============================================================
//                      Get Function's 
//===============================================================

sf::Font& ResourcesManagement::getFont()
{
	return m_font;
}
//---------------------------------------------------------------
sf::Music& ResourcesManagement::getGameMusic(const int index)
{
	return m_gameMusic[index];
}
//---------------------------------------------------------------
sf::Music& ResourcesManagement::getMenuMusic()
{
	return  m_menuMusic;
}
//---------------------------------------------------------------
void  ResourcesManagement::playSound(const int index)
{
	return  m_playSounds[index].play();
}
//---------------------------------------------------------------
void  ResourcesManagement::stopSound(const int index)
{
	return  m_playSounds[index].stop();
}
//---------------------------------------------------------------
sf::Texture& ResourcesManagement::getBackgroundImage(const int index)
{
	return m_backGroundImages[index];
}
//---------------------------------------------------------------
sf::Texture& ResourcesManagement::getLevelImage(const int index)
{
	return m_levelsImages[index];
}//---------------------------------------------------------------
sf::Texture& ResourcesManagement::getCurrPlayerImage(const int index)
{
	return m_currPlayer[index];
}
//---------------------------------------------------------------
sf::Texture& ResourcesManagement::getGameFigures(const int index)
{
	return m_gameFigures[index];
}

