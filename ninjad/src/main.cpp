#include <iostream>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"

using namespace sf;

int main(int argc, char**argv)
{
	sf::Window wind(sf::VideoMode(800, 600, 32), "ASDF");
	wind.Display();

	std::cin.get();
	return 0;
}
//ASDF