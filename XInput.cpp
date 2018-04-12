
#include "XInput.h"

XInput::XInput()
{
	m_pDirectInput = nullptr;
	m_pKeyboard = nullptr;
	m_pMouse = nullptr;
}

XInput::~XInput()
{

}

bool XInput::Initialize(HINSTANCE instance, HWND wnd, int screenWidth, int screenHeight)
{
	HRESULT hr;
	m_screenWidth = screenWidth;
	m_screenHeight = screenHeight;
	m_mouseX = screenWidth/2;
	m_mouseY = screenHeight/2;

	hr = DirectInput8Create(instance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDirectInput, NULL);
	
	if (FAILED(hr))
		return false;

	hr =  m_pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pKeyboard, NULL);
	
	if (FAILED(hr))
		return false;


	
	hr = m_pKeyboard->SetDataFormat(&c_dfDIKeyboard);
	
	if (FAILED(hr))
		return false;
	
		
	hr = m_pKeyboard->SetCooperativeLevel(wnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	
	if (FAILED(hr))
		return false;
	
		
	hr = m_pKeyboard->Acquire();
	
	if (FAILED(hr))
		return false;
	
		
	hr = m_pDirectInput->CreateDevice(GUID_SysMouse, &m_pMouse, NULL);
	
	if (FAILED(hr))
		return false;

	
	hr = m_pMouse->SetDataFormat(&c_dfDIMouse);
	
	if (FAILED(hr))
		return false;
	
	hr = m_pMouse->SetCooperativeLevel(wnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	
	if (FAILED(hr))
		return false;
	
	
	hr = m_pMouse->Acquire();
	
	if (FAILED(hr))
		return false;

	return true;
}



bool XInput::ReadMouse()
{
	HRESULT hr;

	// Read the mouse device.
	hr = m_pMouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	
	if (FAILED(hr))
	{
		// If the mouse lost focus or was not acquired then try to get control back.
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
			m_pMouse->Acquire();
		else
			return false;
	}

	return true;
}

bool XInput::ReadKeyboard()
{
	HRESULT hr;

	// Read the keyboard device.
	hr = m_pKeyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);

	if (FAILED(hr))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
			m_pKeyboard->Acquire();
		else
			return false;
	}

	return true;
}

bool XInput::Poll()
{
	if (!ReadMouse())
		return false;
	if (!ReadKeyboard())
		return false;
	m_lastMouseX = m_mouseX;
	m_lastMouseY = m_mouseY;
	
	m_mouseX += m_mouseState.lX;
	m_mouseY += m_mouseState.lY;

	// Ensure the mouse location doesn't exceed the screen width or height.
	if (m_mouseX < 0) { m_mouseX = 0; }
	if (m_mouseY < 0) { m_mouseY = 0; }

	if (m_mouseX > m_screenWidth) { m_mouseX = m_screenWidth; }
	if (m_mouseY > m_screenHeight) { m_mouseY = m_screenHeight; }

	return true;
}

bool XInput::IsKeyPressed(unsigned char key)
{
	return(m_keyboardState[key] & 0x80);
}

void XInput::GetMousePosition(int & posX, int & posY)
{
	posX = m_mouseX;
	posY = m_mouseY;
}

void XInput::GetLastMousePosition(int & posX, int & posY)
{
	posX = m_lastMouseX;
	posY = m_lastMouseY;
}
