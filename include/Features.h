#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <SFML/OpenGL.hpp>

#include <vector>
#include <memory>
#include <iostream>
#include <fstream>  

enum gameBoard
{
    GATE = 35,
    FIRE = 42,
    ORK = 33,
    KEY = 70,
    TELPORT = 88,
    WALL = 61,
    THRONE = 64,
    GIFT = 36, 
    GIFTDWARF = 126, 
};

enum gameCharacters
{
    WARRIOR = 87,
    KING = 75,
    MAGE = 77,
    THIEF = 84,
    DWARF = 94,
};

enum gameMenu
{
    PLAY    = 80,
    HELP    = 72,
    EXIT    = 69,
    SPACE   = 32,
};

enum Directions
{
    Down, Left, Right, Up

};



enum CharactersIndex
{
    King_INDX, Thief_INDX, Mage_INDX, Warrior_INDX
};

enum SoundEffects
{
    Click, Walk, PutFire, KillOrk, OpenGate, TeleportS , GrabKey , Win, OpenGift , Lose, strike, Winner
};

const int NUM_OF_PLAYER = 4;
const int DUMB_DFARF = 0;
const int SMART_DFARF = 1;

//EVENTS AND MOVEMENT
//events
//------------------------------------------------------
const auto CLOSE_WINDOW   = sf::Event::Closed;
const auto BUTTON_CLICKED = sf::Event::MouseButtonReleased;
const auto MOUSEMOVED     = sf::Event::MouseMoved;
const auto KEYBOARD_CLICK = sf::Event::KeyPressed;
// const for calculations
//------------------------------------------------------
const int          DISTANCE_X = 0;
const int          DISTANCE_Y = 170;
const int          SPRITE_SHEET_WIDTH = 96;
constexpr auto     ShapeSize = 50.f;
constexpr auto     ShapeSpeed = ShapeSize * 2.5;

// const for utilities
//------------------------------------------------------
const int          MUTE   = 10;
const int          VOLUME = 9;
const int          MENU = 1;
const int          GAME = 2;
const int          NUM_OF_LEVEL = 3;
const int		   NUM_OF_IMAGE = 3;
const int		   NUM_OF_MAIN_CHAR = 4;
const int		   NUM_OF_GAME_CHAR = 14;
const int		   SIZE_SQUARE = 64;
const int          MUSIC =        3;
const int          SOUNDEFFECTS = 12;

// const for file's name
//------------------------------------------------------
const char        MENU_ICONS[] = { 'P', 'H', 'E' , 'B' , 'V' };

const std::string CHARACTERS_NAMES[] = { "King.png", "Thief.png", "Mage.png",
                                         "Warrior.png", "Ork.png", "Teleport.png",
                                         "Fire.png","Wall.jpg","Key.png","Gate.png",
                                         "Throne.png","Gift.png","DumbDwarf.png" ,"SmartDwarf.png" };

const std::string LEVEL_MUSIC     [] = { "level1.wav" ,"level2.wav" , "level3.wav"};

const std::string LEVEL_IMAGES    [] =  { "level1.png" ,"level2.png" , "level3.png" ,"levelUp.png","GameOver.jpeg","Strike.png","winMsg.png","pauseGame.png","introduction.png","volume.png","mute.png" };

const std::string CUUR_PLAYER     [] = { "King1.png", "Thief1.png", "Mage1.png", "1Warrior.png" };

const std::string MENU_FILE_IMAGE [] = { "MenuBackground.png" , "HelpBackground.png"  };

const std::string SOUND_EFFECTS   [] = { "Click.wav" , "Walk.wav" ,  "PutFire.wav",  "KillOrk.wav", "OpenGate.wav","Teleport.wav" ,"GrabKey.wav","Win.wav",
                                         "OpenGift.wav","Lose.wav",  "Disqualafied.wav","Winner.wav"};

