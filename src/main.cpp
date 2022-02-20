#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <thread>
#include <cstdlib>
#include <iostream>
#include <time.h>


int main()
{
	srand(time(NULL));
	Controller window;
	window.RunWindow();

	EXIT_SUCCESS;
}
