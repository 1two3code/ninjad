//inputklassen kan nu; kolla om man går till höger, vänster, hoppar eller klickar
//kan även kolla musens position.
//osäker på variablerna right, left, jump, click och hur man ändar dem dock

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;

class InputHandler
{
private:
	static InputHandler input;
	InputHandler();
	~InputHandler();

	//La till dessa  för eventuell keybinding-config
	unsigned short keyRight;
	unsigned short keyLeft;
	unsigned short keyJump;

public:
	static InputHandler& getInstance();
	bool isPressRight(RenderWindow* wnd);
	bool isPressLeft(RenderWindow* wnd);
	bool isPressJump(RenderWindow* wnd);
	bool isPressEscape(RenderWindow* wnd);
	bool isPressClick(RenderWindow* wnd);

	int getMousePosX(RenderWindow* wnd);
	int getMousePosY(RenderWindow* wnd);
};

#endif
