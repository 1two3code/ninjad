#include "include\SFML\Graphics.hpp"
#include "include\SFML\Window.hpp"
#include <iostream>
#include "Animation.h"


int main()
{
	Animation anim("blocks.png", 6, 32, 32, 3);
	sf::RenderWindow wnd(sf::VideoMode(300, 300, 32), "Animation");
	sf::Sprite sprite;
	wnd.Show(true);
	sf::Event currEvent;
	std::string filename;
	int frames, sizeX, sizeY;
	while(wnd.IsOpened())
	{

		while(wnd.GetEvent(currEvent))
		{
			if((currEvent.Type == sf::Event::KeyReleased) && (currEvent.Key.Code == sf::Key::PageDown))
			{
				anim.IncreaseDelay();
				std::cout << "Delaying...\n";
			}
			if((currEvent.Type == sf::Event::KeyReleased) && (currEvent.Key.Code == sf::Key::PageUp))
			{
				anim.DecreaseDelay();
				std::cout << "Advancing...\n";
			}
			if((currEvent.Type == sf::Event::KeyReleased) && (currEvent.Key.Code == sf::Key::Return))
			{
				std::cout << "Current delay: " << anim.frameDelay << "\n";
			}
			if((currEvent.Type == sf::Event::KeyReleased) && (currEvent.Key.Code == sf::Key::Space))
			{
				std::cout << "Load File: ";
				std::getline(std::cin, filename);
				std::cout << "\n# of Frames: ";
				std::cin >> frames; std::cin.ignore();
				std::cout << "\nSize X: ";
				std::cin >> sizeX; std::cin.ignore();
				std::cout << "\nSize Y: ";
				std::cin >> sizeY; std::cin.ignore();
				anim.Load(filename, frames, sizeX, sizeY);
			}
			if(((currEvent.Type == sf::Event::KeyReleased) && (currEvent.Key.Code == sf::Key::Escape)) || (currEvent.Type == sf::Event::Closed))
			{
				wnd.Close();
			}
		}

		sf::Sleep(0.017f);
		wnd.Clear(sf::Color::White);
		anim.Update();
		sprite.SetPosition(0,0);
		sprite = anim.sprite;
		wnd.Draw(sprite);
		wnd.Display();
	}
	return 0;
}