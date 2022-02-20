#include "DataManagement.h"

//contructor & descontructor
//-------------------------------------------------------------------------------
DataManagement::DataManagement( GameWindow* gameWindowPtr)
	:m_levelEnd(false), m_p2GameWindow(gameWindowPtr)
{
	reSizeMovingObject		    ();
	m_gameBoard.initCharacters  (*this);
	pairTeleport                ();
	setlevelTime				();
}
//-------------------------------------------------------------------------------
void DataManagement::reSizeMovingObject() {
	m_movingObject.resize(NUM_OF_PLAYER);
}
//===============================================================================
//                            Get Function's 
//===============================================================================

bool DataManagement::getlevelEnd() const {
	return m_levelEnd;
}

//===============================================================================
//                            Set Function's 
//===============================================================================

void DataManagement::setlevelEnd(const bool status) {
	m_levelEnd = status;
}

//-------------------------------------------------------------------------------
void DataManagement::setTexture() {
	m_movingObject[m_p2GameWindow->getPlayer()]->setTextureRectDefualt();
}

//-------------------------------------------------------------------------------
void DataManagement::setSpriteDirection(sf::Event event) {
	m_movingObject[m_p2GameWindow->getPlayer()]->setSpriteImageDirection(event);
}

//-------------------------------------------------------------------------------
void DataManagement::setlevelTime() {
	m_p2GameWindow->setLevelTime(m_gameBoard.getTimeLevel());
}

//-------------------------------------------------------------------------------
void DataManagement::update(const int currPlayer) {
	const auto deltaTime = m_gameClock.restart(); //Move by Clock
	
	moveObject(currPlayer, deltaTime);

	//handle Collision only for current player

	handleCollisions(*m_movingObject[currPlayer] , false);

	for (int i = 4; i < m_movingObject.size(); i++)
	{
		//handle Collision for Dwarf's
		handleCollisions(*m_movingObject[i],true);
	}
	updateStaticVector();


}
//-------------------------------------------------------------------------------
void DataManagement::moveObject(const int currPlayer, sf::Time deltaTime) {
	
	//Move update only for current player
	m_movingObject[currPlayer]->move(deltaTime, m_movingObject[currPlayer]->getPosition());   
	
	for (int i = 4; i < m_movingObject.size(); i++) 
	{
		//Move update for Dwarf() , Move as long as there is no collision
		m_movingObject[i]->     move(deltaTime, m_movingObject[currPlayer]->getPosition());  
									             
	}
}

//===============================================================================
//                            Print Function's 
//===============================================================================

//-------------------------------------------------------------------------------
void DataManagement::drawMoveObject(const int currPlayer,sf::RenderWindow& window) {

	for (int i = 0; i < m_movingObject.size(); ++i) {
		if (currPlayer == i) {
			m_movingObject[i]->setMovingTextureRect();
		}
		m_movingObject[i]->    draw(window);
	}
}
//-------------------------------------------------------------------------------
void DataManagement::drawStaticObject(sf::RenderWindow& window) {
	m_gameBoard.    drawBoard        (window);
	for (int i = 0; i < m_staticObject.size(); ++i) {
		if (m_staticObject[i]->getSpriteSheet()) {
			m_staticObject[i]->setTextureStaticRect();
		}
		    m_staticObject[i]->draw(window);
	}
}

//===============================================================================
//                            Collisions Function's 
//===============================================================================

//-------------------------------------------------------------------------------
// * Collision test of the current player and dwarf's * 
// * With all the objects in the game     *
//-------------------------------------------------------------------------------
void DataManagement::handleCollisions(MovingObject& gameObject,const bool dwarf)
{

	for (auto& movable : m_movingObject)
	{
		if (gameObject.checkCollision(*movable))
		{
			if (&gameObject != &(*movable))
				if (dwarf)
				movable->handleCollision(gameObject);
				else
				gameObject.moveBack     ();
		}
	}
	handleCollisionsStatic(gameObject);
}
//-------------------------------------------------------------------------------
// * Collision testing of the Moving object * 
// * With all the objects in the game       *
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
void DataManagement::handleCollisionsStatic(MovingObject& gameObject)
{

	for (auto& unmovable : m_staticObject)
	{
		if (typeid (Dwarf) != (typeid(gameObject))) {
			handleTeleportCollision(unmovable);
		}
		 if (gameObject.checkCollision(*unmovable))
		{
			unmovable->handleCollision(gameObject);
		}
	}

}
//---------------------------------------------------------------------------------
// * Check if one of the static objects or dwarfs needs to be deleted *
//---------------------------------------------------------------------------------
void DataManagement::updateStaticVector()
{
	for (auto& unmovable : m_staticObject)
	{
		if (unmovable->isDisposed()) {
			orkDisposed(*unmovable);      //A key appears in place of the ork

			giftTimeDisposed(unmovable);  //A gift that adds or detracts from time

			GiftDwarfDisposed(*unmovable);

			gameEnd (*unmovable);		 //Check if the king ascended the throne
		}
	}

	eraseDwarf       ();
	eraseStaticObject();

}
//--------------------------------------------------------------------------------
// * This function passes over the vector of the movingObject and *
// *              And deletes according to the flag               *
//--------------------------------------------------------------------------------
void DataManagement::eraseDwarf() {

	//Erases all elements that isDisposed() is true
	std::erase_if(m_movingObject, [](auto& movable)
		{
			return movable->isDisposed();
		});

}
//--------------------------------------------------------------------------------
// * This function passes over the vector of the staticObject and *
// * When a collision occurs that requires the object to disappear* 
// * the flag lights up And deletes according to the flag         *

//--------------------------------------------------------------------------------
void DataManagement::eraseStaticObject() {

	//Erases all elements that isDisposed() is true

	std::erase_if(m_staticObject, [](auto& unmovable)
		{
			return unmovable->isDisposed();
		});
}
//----------------------------- handle Teleport   --------------------------------
void DataManagement::handleTeleportCollision(std::unique_ptr <StaticObject>& unmovable)
{
	
		if (typeid (Teleport) == (typeid(*unmovable)))
		{
			Teleport* obj = static_cast<Teleport*>(unmovable.get());

			if (!obj->getLockTeleport() && notCollisionWithTeleport(obj->getPairdTeleport()) && notCollisionWithTeleport(obj))
				obj->setLockTeleport(true);
		
		}	
}
//-------------------------------------------------------------------------------
bool DataManagement::notCollisionWithTeleport(Teleport * pairedTeleport) {

	for (int i = 0; i < 4; i++)
	{
		if (m_movingObject[i]->checkCollision(*pairedTeleport)) {
			return false;
		}
	}
	return true;
}
//-------------------------------- ork Disposed -----------------------------------
void DataManagement::orkDisposed(StaticObject& unmovable)
{
	if (typeid (Ork) == (typeid(unmovable)))
	{
		updateCharactersGame(KEY, unmovable.getPosition());
	}
}
//--------------------------------GiftDwarfVanish Disposed-------------------------
void DataManagement::GiftDwarfDisposed(StaticObject& unmovable)
{
	if (typeid (GiftDwarf) == (typeid(unmovable))) {
		randomGiftDwarf(unmovable.getPosition());
	}
}
//------------------------------------- gameEnd -----------------------------------
void DataManagement::gameEnd(StaticObject& unmovable)
{
	if (typeid (Throne) == (typeid(unmovable))) {
		setlevelEnd(true);
	}
}
//--------------------------------gift Time Disposed-------------------------------
void DataManagement::giftTimeDisposed(std::unique_ptr <StaticObject>& unmovable)
{
	if (typeid (GiftTime) == (typeid(*unmovable))) {

		int factor = static_cast<GiftTime*>(unmovable.get())->giftRandomaizer();

		m_p2GameWindow->setUpdateTimeLevel(unmovable->getPosition(), factor);
	}
}
//------------------------------------ Vanish Dwarfs ------------------------------
void DataManagement::VanishDwarfs(const bool Vanish_one)
{
	bool breakLoop = false;
	for (auto& movable : m_movingObject)
	{
		if (typeid (DumbDwarf) == (typeid(*movable)) || typeid (SmartDwarf) == (typeid(*movable)))
		{
			if (Vanish_one)
			{
				breakLoop = true;
			}
			movable->SetDisposed(true);
		}
		if (breakLoop)
			break;
	}
}
//--------------------------------GiftDwarfVanish Disposed-------------------------
void DataManagement::randomGiftDwarf(sf::Vector2f location) {
	int gift = rand() % (3) ;

	switch (gift)
	{
	case 0:
		VanishDwarfs(false);
	    m_p2GameWindow->setVainshDwarfMsg(0, location);
		break;
	case 1:
		updateCharactersGame(DWARF, location);
		m_p2GameWindow->setVainshDwarfMsg(1, location);
		break;
	case 2:
		VanishDwarfs(true);
		m_p2GameWindow->setVainshDwarfMsg(2, location);
		break;
	default:
		break;
	}
}
//                         End of Collisions Function's
//=================================================================================


//===============================================================================
//                            Seting  Levels  Function's 
//===============================================================================

//-------------------------------- handle Reset Level ----------------------------
void DataManagement::handleResetLevel()
{
	setlevelEnd(false);

	m_movingObject.clear();

	m_staticObject.clear();
	
	reSizeMovingObject();
	
    m_gameBoard.initCharacters(*this);

	pairTeleport();
}
//-------------------------------------------------------------------------------
void DataManagement::setNewLevel() {
	m_gameBoard.setNewLevel();
}
//index set to begining Of Level Files
//-------------------------------------------------------------------------------
void DataManagement::beginOfLevelFiles() {
	m_gameBoard.beginOfLevelFiles();
}
//-------------------------* update Characters Game *----------------------------
//The function gets positioned on a character board, 
//character and "pushes" the relevant object.
//-------------------------------------------------------------------------------
void DataManagement::updateCharactersGame(const char figure,  sf::Vector2f location)
{
	
	switch (figure)
	{
	case KING: 
		m_movingObject[King_INDX]    = std::make_unique <King>(location);
		break;
	case THIEF:
		m_movingObject[Thief_INDX]   = std::make_unique <Thief>(location);
		break;
	case MAGE:
		m_movingObject[Mage_INDX]    = std::make_unique <Mage>(location);
		break;
	case WARRIOR:
		m_movingObject[Warrior_INDX] = std::make_unique <Warrior>(location);
		break;
	case DWARF:
		randomizeDwarf(location);
		break;
	case ORK:
		m_staticObject.push_back(std::make_unique <Ork>(location));
		break;
	case GATE:
		m_staticObject.push_back(std::make_unique <Gate>(location));
		break;
	case WALL:
		m_staticObject.push_back(std::make_unique <Wall>(location));
		break;
	case TELPORT:
		m_staticObject.push_back(std::make_unique <Teleport>(location));
		break;
	case KEY:
		m_staticObject.push_back(std::make_unique <Key>(location));
		break;
	case FIRE:
		m_staticObject.push_back(std::make_unique <Fire>(location));
		break;
	case THRONE:
		m_staticObject.push_back(std::make_unique <Throne>(location));
		break;
	case GIFT:
		m_staticObject.push_back(std::make_unique <GiftTime>(location));
		break;
	case GIFTDWARF:
		m_staticObject.push_back(std::make_unique <GiftDwarf>(location));
		break;
	default:break;
	}
	
}
//------------------------------------------------------------------
void DataManagement::randomizeDwarf( sf::Vector2f location) {
	
	static int random = 0 ;

	if(random < 3 )
	{
	   m_movingObject.push_back(std::make_unique <DumbDwarf>(location));
	   random++;
	}
	else
	{
		m_movingObject.push_back(std::make_unique  <SmartDwarf>(location));
		random = 0;
	}
}

//===============================================================================
//                            Teleport menagment Function's 
//===============================================================================


// ------------------------ * Pair Teleport * ----------------------
//This function and the auxiliary functions below it are,
// responsible for the playfulness of the teleport
//------------------------------------------------------------------
void DataManagement::pairTeleport()
{
	__int64 j = 0;
	std::vector<int> indexTeleport = findTeleportIndex();
	
	if (indexTeleport.size() == 2)
		setPairTeleport(indexTeleport[0], indexTeleport[1]); // if we have 2 teleport
	
	for (int i = 0; i < (indexTeleport.size() / 2); ++i )
	{
		j = (__int64)i * 2;
		if (i % 2 == 0)
		{
	    if((size_t)j + 2 < indexTeleport.size())
	    setPairTeleport(indexTeleport[j], indexTeleport[(j + 2)]);
		}
	else 
		{
		setPairTeleport(indexTeleport[(j - 1)], indexTeleport[(j + 1)]);
	    }
	}
	if ((indexTeleport.size() / 2) % 2 != 0) {
		setPairTeleport(indexTeleport[(indexTeleport.size() - 2 )], indexTeleport[(indexTeleport.size() - 1)]);
	}
}
// ------------------ * find Teleport Index * ----------------------
//This function calculates the locations of the teleports 
//and returns a vector that contains them
//------------------------------------------------------------------
std::vector<int> DataManagement::findTeleportIndex() {
	std::vector<int> indexTeleport;
	for (auto i = 0; i < m_staticObject.size(); ++i)
	{
		if (typeid (Teleport) == (typeid(*m_staticObject[i])))
		{
			indexTeleport.push_back(i);
		}
	}
	return indexTeleport;
}
// ------------------ * set Pair Teleport * ------------------------
//This function connects between Teleport's
//In Each class has a type member Teleport * 
//And through it the connection is made.
//------------------------------------------------------------------
void DataManagement::setPairTeleport(const int location1 , const int location2) {

	static_cast <Teleport*>(m_staticObject[location1].get())->setPairdTeleport(static_cast<Teleport*>(m_staticObject[location2].get()));
	static_cast <Teleport*>(m_staticObject[location2].get())->setPairdTeleport(static_cast<Teleport*>(m_staticObject[location1].get()));

}