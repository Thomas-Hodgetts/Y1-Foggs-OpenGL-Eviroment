#include <iostream>
#include "HelloGL.h"


int main(int argc, char* argv[])
{
	HelloGL* game = new HelloGL(argc, argv); //creates a new instance of our game
	return 0; // assumes a successful exit of our game
}