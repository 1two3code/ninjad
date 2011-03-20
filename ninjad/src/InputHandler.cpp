#include"InputHandler.h"



InputHandler::InputHandler()
{	
	/*right = sf::Key::D;
	left = sf::Key::A;
	jump = sf::Key::Space;
	click = sf::Mouse::Left;*/

	keyRight = 100;
	keyLeft = 97;
	keyJump = 277;
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
	return wnd->GetInput().IsKeyDown((sf::Key::Code)keyRight);
}

bool InputHandler::isPressLeft(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown((sf::Key::Code)keyLeft);
}

bool InputHandler::isPressJump(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown((sf::Key::Code)keyJump);
}

bool InputHandler::isPressEscape(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::Escape);
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

bool InputHandler::isPress1(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::Num1);
}

bool InputHandler::isPress2(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::Num2);
}

bool InputHandler::isPress3(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::Num3);
}

bool InputHandler::isPress4(RenderWindow* wnd)
{
	return wnd->GetInput().IsKeyDown(sf::Key::Num4);
}