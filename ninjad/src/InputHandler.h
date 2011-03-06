//inputklassen kan nu; kolla om man g�r till h�ger, v�nster, hoppar eller klickar
//kan �ven kolla musens position.
//os�ker p� variablerna right, left, jump, click och hur man �ndar dem dock

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

	//La till dessa  f�r eventuell keybinding-config
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
