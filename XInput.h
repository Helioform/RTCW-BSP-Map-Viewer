#pragma once
#define DIRECTINPUT_VERSION 0x0800


#include <dinput.h>

class XInput
{
protected:
	IDirectInput8* m_pDirectInput;
	IDirectInputDevice8* m_pKeyboard;
	IDirectInputDevice8* m_pMouse;
	unsigned char m_keyboardState[256];
	DIMOUSESTATE m_mouseState;

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY, m_lastMouseX, m_lastMouseY;

public:
	XInput();
	~XInput();

	bool Initialize(HINSTANCE instance, HWND wnd, int screenWidth, int screenHeight);
	bool ReadMouse();
	bool ReadKeyboard();
	bool Poll();
	bool IsKeyPressed(unsigned char key);
	void GetMousePosition(int& posX, int& posY);
	void GetLastMousePosition(int& posX, int& posY);
	void GetMouseDelta(int& posX, int& posY) {
		posX = m_mouseX - m_lastMouseX; posY = m_mouseY - m_lastMouseY;
	}
};