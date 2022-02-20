#pragma once

#include "StaticObject.h"

class Teleport : public StaticObject {

public:
	  Teleport (const sf::Vector2f);
	 ~Teleport () {}
	// Handle Collision functions 
	//---------------------------------------------------------------
	void handleCollision(GameObject&) override;
	

   // set functions
   //---------------------------------------------------------------  
	void           setLockTeleport   (const bool);
	void           setPairdTeleport  (const Teleport*);

	// get functions
	//---------------------------------------------------------------   
	bool           getLockTeleport   () const;
	Teleport*      getPairdTeleport  () const;

private:
	bool                                  m_lockTeleport;
	Teleport *                            m_pairedTeleport;
};

