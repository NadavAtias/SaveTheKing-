#include "Board.h"
#include "DataManagement.h"
//Constructor
//---------------------------------------------------------------
// build game board
//---------------------------------------------------------------
Board::Board()
	:m_levelsFile("levels.txt"), m_Board(sf::Vector2f(1043, 680))
{
	this->setNewLevel();
	this->designBoard();
}
//---------------------------------------------------------------
Board::~Board()
{
	m_levelsFile.close();
}
//---------------------------------------------------------------
// design game board
//---------------------------------------------------------------
void Board::designBoard()
{
	m_Board.setFillColor       (sf::Color(255, 255, 255, 50));
	
	m_Board.setOutlineThickness(3.f);
	
	m_Board.setOutlineColor    (sf::Color().Black);
	
	m_Board.setPosition        (205, 20);
}

//---------------------------------------------------------------
// function that builds the unique_ptr vector by inserting all
// static game characters to the vector. all for easy access to
// all static figures of the game.
//---------------------------------------------------------------
void Board::initCharacters(DataManagement& data)
{

	for (auto row = 0; row < getLevelRows().size(); ++row)
	{
		for (auto col = 0; col < getLevelRows()[row].size(); ++col)
		{
			if (validFigure(getChar(row, col)))
			{
				data.updateCharactersGame(getChar(row, col), calcBoardLocation(row, col));
			}
		}
	}
}

//===============================================================
//                   Get functions 
//===============================================================
//---------------------------------------------------------------
int Board::getTimeLevel() const{
	return m_timeLevel;
}
//---------------------------------------------------------------
// function return a single row from levels txt file
//---------------------------------------------------------------
std::vector<std::string> Board::getLevelRows() const {
	return m_levelrows;
}
//---------------------------------------------------------------
char Board::getChar(const int x , const int y ) const {
	return m_levelrows[x][y];
}
//===============================================================

//===============================================================
//                   Set functions 
//===============================================================

//---------------------------------------------------------------
// function that loads the next level in txt file
//---------------------------------------------------------------
bool Board::setNewLevel() {
	m_levelrows.clear(); //deletes the board game
	if (m_levelsFile.eof()) return (m_levelsFile.eof());

	std::string number; // for saving the level time
	std::getline(m_levelsFile, number);

	for (auto line = std::string(); std::getline(m_levelsFile, line) &&
		(line.compare("\0") != 0);) {
		m_levelrows.push_back(line);
	}

	m_timeLevel = std::stoi(number);
	return (false);
}
//===============================================================

//=============================================================== 
//                   Utilities functions 
//===============================================================

//---------------------------------------------------------------
// function to draw the game board
//---------------------------------------------------------------
void Board::drawBoard(sf::RenderWindow & window)
{
	window.draw(m_Board);
}

//---------------------------------------------------------------
// function that return to start of file
//---------------------------------------------------------------
void  Board::beginOfLevelFiles()
{
	m_levelsFile.seekg(0, m_levelsFile.beg);
	this->setNewLevel();
}

//---------------------------------------------------------------
// function check if a certain figure is static figure or not
//---------------------------------------------------------------
bool Board::validFigure(const char figure) const {

	return(figure != SPACE);
}

//---------------------------------------------------------------
// function that calaulates all object required position on the
// game board.
//---------------------------------------------------------------
sf::Vector2f Board::calcBoardLocation(const int x, const int y)
{
	return sf::Vector2f((float)(205 + (35 * 1.3) * y), (float)(20 + (35 * 1.3) * x));
}

