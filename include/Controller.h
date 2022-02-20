#pragma once
//------------------------- Include Section --------------------------

#include <SFML/OpenGL.hpp>
#include "MenuWindow.h"
#include "GameWindow.h"
#include "ResourcesManagement.h"
#include "DataManagement.h"

//--------------------------- Class Section --------------------------
class Controller {

public:
    //constructors & deconstroctor
     Controller                        ();
     ~Controller                       () {};
    //---------------------------------------------------------------
    //functions responsable for running the game
    //---------------------------------------------------------------
    const bool          running        () const;
    bool                getIfLiveInGame() const;
    bool                getIfToContinue() const;
    void                RunWindow      ();
    //---------------------------------------------------------------
private:
    //Prviate Function
    //---------------------------------------------------------------
    //Manage music Functions
    //---------------------------------------------------------------
    void setMusic                       (const int num);
    void setInLiveGame                  (const bool );
    void setIfToContinue                (const bool cond);
    
    //Set functions 
    //---------------------------------------------------------------
    void loadNextLevel   ();
  
  
    // Get functions 
    //---------------------------------------------------------------
    bool      getStratGame ()            const;
    sf::Event getEvent()                 const;
    
    //Game managment Functions
    //---------------------------------------------------------------
    void update          (); // updating constantlly the game
    void pollEvents      (); 
    void handleNextLevel (); 
    void handleWinnerGame();
    void handleGameOver  (const bool); 
    void gameDisqualafied();  

    void handleCloseEvent();  // closing game window
    void handleClickEvent();  // controll mouse clicks
    void handleMouseMoved();  // controll mouse hover bottuns
    void checkKeyEvent   ();  // controll input from user
    void render          ();  // display the game

    //------------------------- Members ----------------------------- 
   
    bool              m_continue;
    bool              m_liveInGame;
    sf::RenderWindow  m_window;
    sf::Event         m_event;
    MenuWindow        m_menu;
    GameWindow        m_gameWindow;
    DataManagement    m_data;

    //----------------------------------------------------------------
}; 