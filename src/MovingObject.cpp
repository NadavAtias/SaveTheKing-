#include "MovingObject.h"
//contructor 
//-----------------------------------------------------------------------
MovingObject::MovingObject(const int characterSymbol,const sf::Vector2f loc)
	:GameObject(characterSymbol, loc)
{
	this->setMovingTextureRect();
}
//============================================================================
//                           Movment Functions   
//============================================================================

//-------------------------- * Move Function * -------------------------------
void MovingObject::move(sf::Time deltaTime ,const sf::Vector2f)
{
	setOldPostion();
	if (inBoardLimit(getPositionWithOffset(deltaTime))) {
		setMove(this->dircetion(deltaTime));
	}
}

//-------------------------- * Move Back Function * -------------------------
void MovingObject::moveBack()
{
	setPosition(getOldPosition());
}

//-------------------------- * Board Limit Function * ------------------------
bool MovingObject::inBoardLimit(sf::Vector2f nextLoc) {

	sf::RectangleShape board;
	board.setSize(sf::Vector2f({ 1015,623 }));
	board.setPosition(sf::Vector2f({ 200,20 }));

	return (board.getGlobalBounds().contains(nextLoc));
}
//-------------------------- * dircetion Function * -------------------------
sf::Vector2f MovingObject::dircetion(sf::Time deltaTime) const
{
	return (dirFromKey() * (float)ShapeSpeed * deltaTime.asSeconds());
}

//============================================================================
//                             Set Function's   
//============================================================================

void MovingObject::setSpriteImageDirection(const sf::Event event)
{
	static int Spriteframe_y = 0;
	static int Spriteframe_x = 0;
	if (event.key.code == sf::Keyboard::Up)
		Spriteframe_y = Up;

	else if (event.key.code == sf::Keyboard::Down)
		Spriteframe_y = Down;

	else if (event.key.code == sf::Keyboard::Right)
		Spriteframe_y = Right;

	else if (event.key.code == sf::Keyboard::Left)
		Spriteframe_y = Left;


	Spriteframe_x++;
	if (Spriteframe_x * 32 >= SPRITE_SHEET_WIDTH) {
		Spriteframe_x = 0;
	}
	
	setSpriteFrameRow(Spriteframe_y);
	setSpriteFrameCol(Spriteframe_x);
	
}
//-----------------------------------------------------------------------
sf::Vector2f MovingObject::dirFromKey()  const
{
	static const std::initializer_list<std::pair<sf::Keyboard::Key, sf::Vector2f>> keyToVectorMapping =
	{
		{ sf::Keyboard::Right , {  1, 0  }  },
		{ sf::Keyboard::Left , {  -1, 0 }  },
		{ sf::Keyboard::Up   , { 0, -1  }  },
		{ sf::Keyboard::Down , { 0, 1   }  },
	};

	for (const auto& pair : keyToVectorMapping)
	{
		if (sf::Keyboard::isKeyPressed(pair.first))
		{
			return pair.second;
		}
	}

	return { 0, 0 };
}
//-----------------------------------------------------------------------
void MovingObject::setTextureRectDefualt() {

	setSpriteFrameRow(1);
	setSpriteFrameCol(Down);
	setTextureRect(sf::IntRect(1 * 32, Down * 32, 32, 32));
}
//---------------------------------------------------------------
void MovingObject::setOldPostion() {
	m_oldPostion = getPosition();
}

//-----------------------------------------------------------------------
void MovingObject::setMovingTextureRect(){
	setTextureRect(sf::IntRect(getSpriteFrame().x * 32, getSpriteFrame().y * 32, 32, 32));
}

//============================================================================
//                             Get Function's   
//============================================================================


sf::Vector2f MovingObject::getPositionWithOffset(sf::Time deltaTime)
{
	return this->getPosition() + this->dircetion(deltaTime);
}
//---------------------------------------------------------------
sf::Vector2f MovingObject::getOldPosition() const
{
	return m_oldPostion;
}

//============================================================================
//                         Handle Collision Function's   
//============================================================================


// Wall with any move object 
//-----------------------------------------------------------------------
void MovingObject::handleCollision(Wall&)
{
	this->moveBack();
}

// Ork with any move object Except from Warrior
//-----------------------------------------------------------------------
void MovingObject::handleCollision(Ork&)
{
	this->moveBack();
}

// Fire with any move object Except from Mage
//-----------------------------------------------------------------------
void MovingObject::handleCollision(Fire&)
{
	this->moveBack();
}

// Key with any move object Except from Thief
//---------------------------------------------------------------
void MovingObject::handleCollision(Key&)
{
	
}

// Gate with any move object Except from Thief
//---------------------------------------------------------------
void MovingObject::handleCollision(Gate&)
{
	this->moveBack();
}

// Throne with any move object Except from King
//---------------------------------------------------------------
void MovingObject::handleCollision(Throne&)
{
	this->moveBack();
}

// GiftTime with any move object Except from Mage
//---------------------------------------------------------------
void MovingObject::handleCollision(GiftTime& gameObject)
{
	gameObject.SetDisposed(true);
	ResourcesManagement::instance().playSound(OpenGift);
}

// GiftTime with any move object Except from Mage
//---------------------------------------------------------------
void MovingObject::handleCollision(GiftDwarf& gameObject)
{
	gameObject.SetDisposed(true);
	ResourcesManagement::instance().playSound(OpenGift);
}
// Teleport with any move object Except from Mage
//---------------------------------------------------------------
void MovingObject::handleCollision(Teleport& gameObject)
{
	gameObject.setLockTeleport(false);
	gameObject.getPairdTeleport  ()->setLockTeleport(false);
	this->     setPosition       (gameObject.getPairdTeleport()->getPosition());
	ResourcesManagement::instance().playSound(TeleportS);

}
