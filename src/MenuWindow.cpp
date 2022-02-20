#include "MenuWindow.h"
//Constructor
//---------------------------------------------------------------
// sets the menu section of the game 
//---------------------------------------------------------------
MenuWindow::MenuWindow()
	:m_Icon(SPACE)
{
	this->initButtons();
}

//===============================================================
//                       Init Function's   
//===============================================================

//---------------------------------------------------------------
// funcion that create & design the back button at Help window
//---------------------------------------------------------------
void MenuWindow::setBackButton(sf::RectangleShape buttonLoaction) {

	sf::Vector2f        Loaction  ((float)35, (float)70);
	buttonLoaction.setSize        ({ 120 , 50 });
	buttonLoaction.setPosition    (Loaction);
	buttonLoaction.setOutlineColor(sf::Color().White);
	m_buttons.     push_back      (buttonLoaction);
}

//---------------------------------------------------------------
// funcion that creats all menu buttons
//---------------------------------------------------------------
void MenuWindow::initButtons()
{
	sf::RectangleShape  buttonLoaction({ 220,80 });
	for (int i = 0; i < NUM_OF_IMAGE; i++)
	{
		sf::Vector2f Loaction((float)540, (float)125 * i + 265);

		buttonLoaction.setPosition        (Loaction);
		buttonLoaction.setFillColor       (sf::Color(255, 255, 255, 0));
		buttonLoaction.setOutlineThickness(3.f);
		buttonLoaction.setOutlineColor    (sf::Color().Black);
		m_buttons.push_back               (buttonLoaction);
	}
	setBackButton(buttonLoaction);

}

//===============================================================
//                       Get functions    
//===============================================================

//---------------------------------------------------------------
sf::RectangleShape MenuWindow::getIconButton(const int index) const {
	return m_buttons[index];
}
//---------------------------------------------------------------
char MenuWindow::getIconMenu(const int index)                  const {

	return (MENU_ICONS[index]);
}
//---------------------------------------------------------------
bool MenuWindow::getStratPlay() const {

	return (m_Icon == PLAY);
}
//---------------------------------------------------------------
char MenuWindow::getCurrIcon() const {

	return m_Icon;
}

//===============================================================
//                       Set functions    
//===============================================================

//---------------------------------------------------------------
//function to declare game has begun
//---------------------------------------------------------------
void MenuWindow::setStratPlay(const char setButton)
{
	m_Icon = setButton;
}
//---------------------------------------------------------------
void MenuWindow::stopMenuMusic()
{
	ResourcesManagement::instance().getMenuMusic().stop();
}
//---------------------------------------------------------------
void MenuWindow::playMenuMusic()
{
	ResourcesManagement::instance().getMenuMusic().play();
	ResourcesManagement::instance().getMenuMusic().setLoop(true);
}

//===============================================================
//                       Utilities functions    
//===============================================================

//---------------------------------------------------------------
//function to Print the menu  
//---------------------------------------------------------------
void MenuWindow::printMenu(sf::RenderWindow & window) {

	ResourcesManagement& resource = ResourcesManagement::instance();
	switch (m_Icon)
	{
	case HELP:
	{
		m_backgroundImage.setTexture(resource.getBackgroundImage(1));
		window.draw(m_backgroundImage);
		window.draw(getIconButton(3));
		break;
	}
	case EXIT:
	{
		window.close();
		break;
	}
	default:
	{
		m_backgroundImage.setTexture(resource.getBackgroundImage(0));
		window.draw(m_backgroundImage);
		for (int i = 0; i < NUM_OF_IMAGE; i++)
		{
			window.draw(getIconButton(i));
		}
		break;
	}

	}
}
//---------------------------------------------------------------
// function that dispaly short intro when game lunched
//---------------------------------------------------------------
void MenuWindow::openingScreen(sf::RenderWindow& window) {

	sf::Clock  timeWin;
	sf::Sprite statusWindow;
	statusWindow.setTexture(ResourcesManagement::instance().getLevelImage(8));

		while (timeWin.getElapsedTime().asSeconds() < 2.5)
		{
			window.clear();
			window.draw(statusWindow);
			window.display();
		}
		timeWin.restart();
}
//---------------------------------------------------------------
// function to check if the mouse press is one of the menu 
// buttons, or the back button at help window. 
//---------------------------------------------------------------
void MenuWindow::containInMenu(sf::Vector2f& mouseLocation) {

	if (m_Icon != HELP) {					//means in menu window 
		for (int i = 0; i < NUM_OF_IMAGE; i++)
		{
			if (getIconButton(i).getGlobalBounds().contains(mouseLocation)) {
				ResourcesManagement::instance().playSound(Click);
				m_Icon = getIconMenu(i);
			}
		}
	}
	else
		containInHelpMenu(mouseLocation);		 //means in help window
}
//---------------------------------------------------------------
//function to check if the mouse press is in help window. 
//---------------------------------------------------------------
void MenuWindow::containInHelpMenu(sf::Vector2f& mouseLocation) {

	if (getIconButton(3).getGlobalBounds().contains(mouseLocation))
	{
		ResourcesManagement::instance().playSound(Click);
		m_Icon = SPACE;
	}
}
//---------------------------------------------------------------
//function that makes buttons a bit bllury for better UI. 
//---------------------------------------------------------------
void MenuWindow::trackingWithMouse(sf::Vector2f& location)
{
	for (int i = 0; i < NUM_OF_IMAGE; i++)
	{
		if (getIconButton(i).getGlobalBounds().contains(location))
		{
			m_buttons[i].setFillColor(sf::Color(192, 192, 192, 70));
			break;
		}
		else
			m_buttons[i].setFillColor(sf::Color::Transparent);
	}
	getIconButton(3).getGlobalBounds().contains(location) ?
		m_buttons[3].setFillColor(sf::Color(192, 192, 192, 70)) :
		m_buttons[3].setFillColor(sf::Color::Transparent);
}