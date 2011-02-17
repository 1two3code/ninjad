#include"InputHandler.h"



InputHandler::InputHandler()
{
	
	/*right = sf::Key::D;
	left = sf::Key::A;
	jump = sf::Key::Space;
	click = sf::Mouse::Left;*/
}

InputHandler::~InputHandler()
{
}

InputHandler InputHandler::input;

InputHandler& InputHandler::getInstance()
{
	return input;
}

bool InputHandler::isPressRight(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::D);
}

bool InputHandler::isPressLeft(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::A);
}

bool InputHandler::isPressJump(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::Space);
}

bool InputHandler::isPressClick(RenderWindow* wnd)
{
	return wnd->GetInput().IsMouseButtonDown(sf::Mouse::Left);
}

int InputHandler::getMousePosX(RenderWindow* wnd)
{
	return wnd->GetInput().GetMouseX();
}

int InputHandler::getMousePosY(RenderWindow* wnd)
{
	return wnd->GetInput().GetMouseY();
}