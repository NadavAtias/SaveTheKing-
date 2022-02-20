#include "GameWindow.h"
//                      COSTRUCTOR                       //
//--------------------------------------------------------
GameWindow::GameWindow()
	:m_Level(0), m_currPlayer(0), m_Life(3), m_pauseGame(sf::Vector2f(1280, 720)), m_pause(false), m_mute(false)
{
	m_imageFigure.setPosition(sf::Vector2f({ 60, 355 }));
	m_imageFigure.setScale(2, 2);
	m_numOfLife.setPosition(sf::Vector2f({ 80, 570 }));
	m_numOfLife.setCharacterSize(50);
	m_giftTimeText.setPosition(0, 0);

	this->initNextButton   ();
	this->initVolumeButton ();
	this->initPauseGameText();
	this->initText         (m_giftTimeText);
	this->initText         (m_nameFigure);
	this->initText         (m_numOfLife);
	this->timerDesign      ();
	this->setLevelTexture  ();
	this->setTextureFigure ();
	this->setTextLife      ();
}

//============================================================================
//                             Init Function's   
//============================================================================
void GameWindow::initNextButton()
{
	m_nextLevel.setPosition        (sf::Vector2f(517, 520));
	m_nextLevel.setSize            ({ 245 , 95 });
	m_nextLevel.setFillColor       (sf::Color(255, 255, 255, 0));
	m_nextLevel.setOutlineThickness(3.f);
	m_nextLevel.setOutlineColor    (sf::Color().White);
}
//----------------------------------------------------------------------------
void GameWindow::initVolumeButton() 
{
	m_volume.setPosition        (sf::Vector2f(52, 80));
	m_volume.setSize            ({ 70 , 70 });
	m_volume.setFillColor       (sf::Color(255, 255, 255, 0));
	m_volume.setOutlineThickness(2.f);
	m_volume.setOutlineColor    (sf::Color().White);
	m_volumeImgae.setPosition   (sf::Vector2f(55, 80));
	m_volumeImgae.setTexture    (ResourcesManagement::instance().getLevelImage(VOLUME));
}
//----------------------------------------------------------------------------
void GameWindow::initText(sf::Text& text)
{
	text.setFont(ResourcesManagement::instance().getFont());
	text.setFillColor(sf::Color().White);
	text.setScale(0.65f, 0.65f);
	text.Bold;

}
//----------------------------------------------------------------------------
void GameWindow::initPauseGameText()
{
	m_pauseGame.setPosition        (sf::Vector2f({ 0, 0 }));
	m_pauseGame.setFillColor       (sf::Color(255, 255, 255, 80));
	m_pauseGame.setOutlineThickness(3.f);
	m_pauseGame.setOutlineColor    (sf::Color().Black);
}
//----------------------------------------------------------------------------

void GameWindow::timerDesign() {
	m_timerText.setFont(ResourcesManagement::instance().getFont());
	m_timerText.setCharacterSize(25);
	m_timerText.setFillColor(sf::Color::White);
	m_timerText.setPosition(sf::Vector2f({ 25, 230 }));
}

//End Init Function's
//============================================================================


//============================================================================
//                           Draw Game Window Functions  
//============================================================================

void GameWindow::draw(sf::RenderWindow& window)
{

	window.draw(m_levelBackground);

	setText(getPlayer());
	window.draw(m_nameFigure );
	window.draw(m_imageFigure);
	window.draw(m_numOfLife  );
	if (!getPauseGame())
		setLevelTimer();

	window.draw(m_timerText);
	window.draw(m_volume   );
	window.draw(m_volumeImgae);

}
//----------------------------------------------------------------------------
//Draw transition screens between Levels, when the game is over or winning
//----------------------------------------------------------------------------
void GameWindow::drawGameStatus(sf::RenderWindow & window, const int status, const float showTime, const bool cond)

{
	sf::Sprite statusWindow;
	statusWindow.setTexture(ResourcesManagement::instance().getLevelImage(status));

	sf::Clock timeWin;

	if (status != 3) // transition screen that isnt winning level
	{
		while (timeWin.getElapsedTime().asSeconds() < showTime)
		{
			window.clear();
			window.draw(statusWindow);
			window.display();
		}
		timeWin.restart();
	}
	else          // winning level transition screen (render until user click on "next Button")
	{
		if (!cond)
		{
			window.clear();
			window.draw(statusWindow);
			window.draw(m_nextLevel);
			window.display();
		}
	}
}
//----------------------------------------------------------------------------
//Draw screen to pause the game
//----------------------------------------------------------------------------
void GameWindow::drawPauseGame(sf::RenderWindow& window)
{
	if (m_giftTimeText.getPosition().y > 65) {//Hovering print while on a gift
		m_giftTimeText.setPosition(m_giftTimeText.getPosition().x, m_giftTimeText.getPosition().y - 0.15);
		window.draw(m_giftTimeText);
	}
	if (getPauseGame()) {
		sf::Sprite statusWindow;
		statusWindow.setPosition(sf::Vector2f({ 80, 20 }));
		statusWindow.setTexture(ResourcesManagement::instance().getLevelImage(7));
		window.draw(m_pauseGame);
		window.draw(statusWindow);
	}
}
//End draw Game Window Functions
//============================================================================


//============================================================================
//                            Set Function  
//============================================================================

//----------------------------------------------------------------------------
//function to set name of cuurent player 
//----------------------------------------------------------------------------
void GameWindow::setText(const int numOfPlayer)
{
	std::string  nameFigure;

	sf::Vector2f loc;

	switch (numOfPlayer) {
	case 0:  loc = sf::Vector2f(60, 425);
		break;
	case 1: loc = sf::Vector2f(50, 425);
		break;
	case 2: loc = sf::Vector2f(60, 425);
		break;
	case 3: loc = sf::Vector2f(30, 425);
		break;
	}
	m_nameFigure.setPosition(loc);
	nameFigure = CHARACTERS_NAMES[getPlayer()];
	nameFigure.   erase     (nameFigure.size() - 4);
	m_nameFigure .setString (nameFigure);
}
//----------------------------------------------------------------------------
void GameWindow::setNextLevel()
{
	m_Level < 2 ? m_Level++ : m_Level = 0;
	this->  setLevelTexture();
	this->  resetLife    ();
	m_timer.restart      ();
	m_mute = false;
	m_volumeImgae.setTexture(ResourcesManagement::instance().getLevelImage(VOLUME));
}
//----------------------------------------------------------------------------
void GameWindow::resetLevels()
{
	m_Level = 0;
	this->  resetLife      ();
	this->  setLevelTexture();
	m_timer.restart        ();
}
//----------------------------------------------------------------------------
// present the current player operated
//----------------------------------------------------------------------------
void GameWindow::setPlayer()
{
	m_currPlayer > 2 ? m_currPlayer = 0 : m_currPlayer++;
	this->setTextureFigure();
}
//----------------------------------------------------------------------------
void GameWindow::setLevelTime(const int min)
{
	m_timeMin = min;
	m_timeSec = 1;
}
//----------------------------------------------------------------------------
void GameWindow::setTextureFigure()
{
	m_imageFigure.setTexture(ResourcesManagement::instance().getCurrPlayerImage(this->getPlayer()));
}
//----------------------------------------------------------------------------
void GameWindow::setPauseGame(const bool status)
{
	m_pause = status;
}
//----------------------------------------------------------------------------
void GameWindow::setTextLife()
{
	m_numOfLife.setString(std::to_string(getLife()));
}
//----------------------------------------------------------------------------
//update life if player loses
//----------------------------------------------------------------------------
void GameWindow::updateLife()
{
	m_Life--;
	setTextLife();
}
//----------------------------------------------------------------------------
//reset life in new game
//----------------------------------------------------------------------------
void GameWindow::resetLife()
{
	m_Life = 3;
	setTextLife();
}
//----------------------------------------------------------------------------
// set level background
//----------------------------------------------------------------------------
void GameWindow::setLevelTexture()
{
	m_levelBackground.setTexture(ResourcesManagement::instance().getLevelImage(this->getCurrLevel()));
}
//----------------------------------------------------------------------------
// function that connect between :
// random time from gift --> actual level timer.
// level timer updated according to the gift time, and
// displaying the gift time to the user. 
//----------------------------------------------------------------------------
void  GameWindow::setUpdateTimeLevel(sf::Vector2f giftloc, const int factor)
{

	m_giftTimeText.setPosition(giftloc);

	if (factor < 0)
	{
		m_giftTimeText.setString(" " + std::to_string(factor) + " SEC !!");
	}
	else {
		m_giftTimeText.setString("+ " + std::to_string(factor) + " SEC !!");
	}
	m_timeSec += factor;
	if (!getTimePassed()) {
		if (m_timeSec >= 60) {
			m_timeMin += 60;
			m_timeSec -= 60;
		}
		if (m_timeSec <= 0) {
			m_timeMin -= 60;
			m_timeSec += 60;
		}
	}
}
//----------------------------------------------------------------------------
// function that swithch between diffrent masseges of 
// Vainsh Dwarf gift, according the type of Vainsh Dwarf gift
//----------------------------------------------------------------------------
void GameWindow::setVainshDwarfMsg(const int string , sf::Vector2f giftloc)
{
	m_giftTimeText.setPosition(giftloc);
	switch (string)
	{
	case 0:
		m_giftTimeText.setString("Dwarfs Go Home!!");
		break;
	case 1:
		m_giftTimeText.setString("dwarf is added !");
		break;
	case 2:
		m_giftTimeText.setString("one dwarf Go Home");
		break;
	default:
		break;
	}
	
}
//----------------------------------------------------------------------------
//function that calculates level time and updaing it constantlly
//----------------------------------------------------------------------------
void GameWindow::setLevelTimer()
{

	if (m_timeMin < 0)
		return;

	if (m_timer.getElapsedTime().asSeconds() > 1)
	{
		m_timeSec--;
		m_timer.restart();

		if (m_timeSec < 10)
			m_timerText.setString("0" + std::to_string(m_timeMin / 60)
				+ ":" + "0" + std::to_string(m_timeSec % 60));
		else
			m_timerText.setString("0" + std::to_string(m_timeMin / 60)
				+ ":" + std::to_string(m_timeSec % 60));
	}
	if (m_timeSec == 0)
	{
		if (m_timeMin > 0)
			m_timeSec = 60;

		m_timeMin -= 60;
	}
}
//----------------------------------------------------------------------------
void GameWindow::trackingWithMouse(sf::Vector2f& location)
{
	    m_nextLevel.getGlobalBounds().contains(location) ?
		m_nextLevel.setFillColor(sf::Color(192, 192, 192, 100)) :
		m_nextLevel.setFillColor(sf::Color::Transparent);

		m_volume.getGlobalBounds().contains(location) ?
		m_volume.setFillColor(sf::Color(192, 192, 192, 70)) :
		m_volume.setFillColor(sf::Color::Transparent);
}
// End set Functions
//============================================================================


//============================================================================
//               Stop and Play Game Music Functions
//============================================================================
void GameWindow::stopGameMusic()
{
	ResourcesManagement::instance().getGameMusic(getCurrLevel()).stop();
}
//--------------------------------------------------------
void GameWindow::playGameMusic()
{
	ResourcesManagement::instance().getGameMusic(getCurrLevel()).play();
	ResourcesManagement::instance().getGameMusic(getCurrLevel()).setLoop(true);
}
//============================================================================

//============================================================================
//                            Get Function  
//============================================================================

int GameWindow::getPlayer()  const
{
	return m_currPlayer;
}
//--------------------------------------------------------
int GameWindow::getCurrLevel()  const
{
	return m_Level;
}
//--------------------------------------------------------
bool GameWindow::getTimePassed() const
{
	return (m_timeMin <= 0 && m_timeSec <= 0);
}
//--------------------------------------------------------
int GameWindow::getLife() const
{
	return m_Life;
}
//--------------------------------------------------------
bool GameWindow::getPauseGame() const
{
	return m_pause;
}
//--------------------------------------------------------
bool GameWindow::getMute() const
{
	return m_mute;
}
// End Get Functions
//============================================================================

//============================================================================
//           function to check interact with "Next" & "Mute" buttons
//============================================================================

void GameWindow::containInVolume(sf::Vector2f& mouseLocation) 
{
	if (m_volume.getGlobalBounds     ().contains(mouseLocation)) {
		if (!m_mute) {
			m_mute = true;
			m_volumeImgae.setTexture(ResourcesManagement::instance().getLevelImage(MUTE));
			stopGameMusic();
		}
		else
		{
			m_mute = false ;
			m_volumeImgae.setTexture(ResourcesManagement::instance().getLevelImage(VOLUME));
			playGameMusic();
		}
		ResourcesManagement::instance().playSound(Click);
	}

}
//--------------------------------------------------------
bool GameWindow::containInNext(sf::Vector2f& mouseLocation) const
{
	if (m_nextLevel.getGlobalBounds().contains(mouseLocation)) {
		ResourcesManagement::instance().playSound(Click);
		return true;
	}
	return false;
}
