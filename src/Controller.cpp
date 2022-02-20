
#include "Controller.h"

//contructor & descontructor
//-------------------------------------------------------------------------------
Controller::Controller()
	:m_window(sf::RenderWindow(sf::VideoMode(1280, 720), "SAVE THE KING")),
	m_continue(false), m_liveInGame(true),m_data(&m_gameWindow),m_event()
{}
//===============================================================================
//                                 Get Function's 
//===============================================================================
//-------------------------------------------------------------------------------
bool Controller::getStratGame() const {
	
	return (m_menu.getStratPlay());
}
//-------------------------------------------------------------------------------
sf::Event Controller::getEvent() const {
	return m_event;
}
//-------------------------------------------------------------------------------
const bool Controller::running() const
{
	return  m_window.isOpen();
}
//-------------------------------------------------------------------------------
bool Controller::getIfLiveInGame() const
{
	return m_liveInGame;
}
//-------------------------------------------------------------------------------
bool Controller::getIfToContinue() const
{
	return m_continue;
}

//===============================================================================
//                             Set Function's
//===============================================================================
//-------------------------------------------------------------------------------
void Controller::setMusic(const int num)
{
	switch (num)
	{
	case MENU: {
		m_gameWindow.stopGameMusic();

		m_menu.      playMenuMusic();
		break;
	}
	case GAME: {
		m_menu.      stopMenuMusic();

		m_gameWindow.playGameMusic();
		break;
	}
	default:
		break;
	}
}
//---------------------------------------------------------------------------------
void Controller::setInLiveGame(const bool cond)
{
	m_liveInGame = cond;
}
//---------------------------------------------------------------------------------
void Controller::setIfToContinue(const bool cond)
{
	m_continue = cond;
}
//===============================================================================
//                             Game managment Function`s
//===============================================================================

// function that runs the main loop of the game a
//-------------------------------------------------------------------------------
void Controller::RunWindow() {
	
	       setMusic     (MENU);
	m_menu.openingScreen(m_window);

	//The main loop of the game
	while (running())
	{
		pollEvents();

		if (getStratGame() && !m_gameWindow.getPauseGame())
			update();

		    render();
	}
}
//-------------------------------------------------------------------------------
// function that handles Events from user input: 
// Keyboard events, mouse movement, mouse clicks, exit game 
//-------------------------------------------------------------------------------
void Controller::pollEvents()
{

	while ( m_window.pollEvent( m_event))
	{

		switch ( m_event.type)
		{
		case CLOSE_WINDOW:
			 handleCloseEvent();
			break;

		case BUTTON_CLICKED:
			 handleClickEvent();
			break;

		case KEYBOARD_CLICK:
			 checkKeyEvent();
			break;

		case MOUSEMOVED:
			 handleMouseMoved();
			break;

		}

	}
}
//-------------------------------------------------------------------------------
// Update function 
//-------------------------------------------------------------------------------
void Controller::update()
{
	
		m_data.update(m_gameWindow.getPlayer());

		gameDisqualafied();   // function to check if player loses

		handleNextLevel();   // function to preapare next level
	
}
//-------------------------------------------------------------------------------
// Display function 
//-------------------------------------------------------------------------------
void Controller::render()
{

	m_window.clear();
	if (!getStratGame())                         // Print the main menu
	{
		m_menu.printMenu( m_window);
	}
	else
	{                                           // Print the Game window
		if (getIfLiveInGame())
		{
		m_gameWindow.draw                  (m_window);
		m_data      .drawStaticObject      (m_window);
		m_data.      drawMoveObject        (m_gameWindow.getPlayer(),m_window);
		m_gameWindow.drawPauseGame         (m_window);
		}
	}
	if (getIfLiveInGame())
		m_window.display();
}

//*********************************************************************************
// Game management functions
// == Go to the next Level                      == 
// == Game over management                      == 
// == Disqualification management of the player == 
//*********************************************************************************
//--------------------------------- handle Next Level -----------------------------
void Controller::handleNextLevel() {

	
	if      (m_data.getlevelEnd() && m_gameWindow.getCurrLevel() == 2)
		    handleWinnerGame();

	else if (m_data.getlevelEnd()) {
		    loadNextLevel();
	}

}
//--------------------------------- handle Winner Game  ---------------------------
// * If the player has completed all the Levels * 
// * Play music and also a victory screen       *
// * Back to the menu and reloading the game    *
//---------------------------------------------------------------------------------
void Controller::handleWinnerGame()
{
	ResourcesManagement& resource = ResourcesManagement::instance();
	resource.stopSound(7);

	m_gameWindow.stopGameMusic();

	resource.playSound(Winner);

	m_gameWindow.drawGameStatus( m_window, 6, 15,  getIfToContinue());

	resource.stopSound(Winner);

	handleGameOver(true);
}
//--------------------------------- handle Game Over -----------------------------
// * If the game is over by finishing the disqualifications * 
// * Playing music for a game is over                       *
// * And screen loading accordingly                         *
// * Back to the menu and reloading the game                *
//---------------------------------------------------------------------------------
void Controller::handleGameOver(const bool gameEnd) {
	ResourcesManagement& resource = ResourcesManagement::instance();

	if (m_gameWindow.getTimePassed() || gameEnd)
	{
		if (m_gameWindow.getTimePassed() || m_gameWindow.getLife() == 0)
		{
			resource.stopSound(9);
			resource.stopSound(8);

			m_gameWindow.stopGameMusic();

			resource.playSound(Lose);

			m_gameWindow.drawGameStatus( m_window, 4, 6,  getIfToContinue());
		}

		m_gameWindow.resetLevels();

		m_data.beginOfLevelFiles();

		m_data.handleResetLevel();

		m_menu.setStratPlay(SPACE);

		 setMusic(MENU);
	}
}
//-------------------------------- handle Next Level -----------------------------
// * If a player has completed the Level before the time runs out * 
// * Playing music for a Next Level                               *
// * And screen loading accordingly                               *
// * loading the  next Level                                      *
//-------------------------------------------------------------------------------
void Controller::loadNextLevel()
{
	setInLiveGame(false);
	m_data      .setlevelTime();
	m_gameWindow.stopGameMusic();
	m_gameWindow.drawGameStatus( m_window, 3, 2.75,  getIfToContinue());

	if ( getIfToContinue())
	{
		 m_gameWindow.setNextLevel  ();

		 setIfToContinue(false);

		 setInLiveGame  (true);
		 
		 m_data    .setNewLevel     ();

		 m_data    .handleResetLevel();
		 
		 m_data.setlevelTime();
		
		 setMusic          (GAME);

	}

}
//-------------------------- handle game Disqualafied -----------------------------
// * If a player failed to complete the stage in the allotted time * 
// * He has three attempts                                         *
// * Playing music for a Fail Level                                *
// * And screen loading accordingly                                *
// * reloading  the same Level                                     *
//--------------------------------------------------------------------------------
void Controller::gameDisqualafied() {


	if (m_gameWindow.getLife() == 0) {
		 handleGameOver(true);
	}

	else if (m_gameWindow.getTimePassed()) {

		
		m_gameWindow.stopGameMusic();

		 m_data.     handleResetLevel();

		ResourcesManagement::instance().playSound(strike);

		m_gameWindow.updateLife();

		m_gameWindow.drawGameStatus( m_window, 5, 4,  getIfToContinue());

		m_data.setlevelTime();
		if(!m_gameWindow.getMute())
		setMusic(GAME);
		
	}

}

//--------------------------------------------------------------------------------
//                          User input managment functions  
//--------------------------------------------------------------------------------

//-------------------------------- handleClickEvent ------------------------------
void Controller::handleClickEvent()
{
    auto location =  m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
	
	if (!getStratGame()) // mange the click in menu 
	{
		m_menu.containInMenu(location);
		if (m_menu.getStratPlay()) {
			 setMusic(GAME);
		}
	}
	else                // mange the click in game 
	{
		if (m_gameWindow.containInNext(location)) {
			 setIfToContinue(true);
		}
		m_gameWindow.containInVolume(location);
	}
}
//-------------------------------- checkKeyEvent ---------------------------------
void Controller::checkKeyEvent()
{
	if (getEvent().key.code == sf::Keyboard::Escape) // end game
	{
		 handleCloseEvent();

	}
	if (getEvent().key.code == sf::Keyboard::Space)  // pause game
	{
		if (!m_gameWindow.getPauseGame())
		{
			m_gameWindow.setPauseGame(true);
			ResourcesManagement::instance().getGameMusic(m_gameWindow.getCurrLevel()).pause();
		}
		else
		{
		m_gameWindow.setPauseGame(false);
		if(!m_gameWindow.getMute())
		ResourcesManagement::instance().getGameMusic    (m_gameWindow.getCurrLevel()).play();
		}
	}
	if (getEvent().key.code == sf::Keyboard::P)   // change player when playing
	{
		
		m_data      .setTexture();
		m_gameWindow.setPlayer ();

	}
	m_data          .setSpriteDirection(getEvent());

}
//-------------------------------- handleCloseEvent ------------------------------
void Controller::handleCloseEvent()
{
	 m_window.close();
}
//-------------------------------- handleMouseMoved ------------------------------
//mouse hovering makes the buttons bllury
//--------------------------------------------------------------------------------
void Controller::handleMouseMoved()
{
	auto mouseLocation = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));
	m_menu.      trackingWithMouse(mouseLocation);
	m_gameWindow.trackingWithMouse(mouseLocation);
}
