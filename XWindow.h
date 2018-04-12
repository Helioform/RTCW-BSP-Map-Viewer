#pragma once

#include <windows.h>
#include "HelperFunctions.h"
#include "resource.h"
#include "XD3D.h"

#define MAX_LOADSTRING 100

class XWindow
{
protected:
	HINSTANCE	m_hInst;                                
	WCHAR		m_szTitle[MAX_LOADSTRING];                 
	WCHAR		m_szWindowClass[MAX_LOADSTRING];        
	HWND		m_hWnd;
	int			m_height, m_width;

public:
	XWindow() {}
	XWindow(WCHAR* title, int width, int height);
	~XWindow() {}

	HWND GetWindowHandle() { return m_hWnd; }
	WCHAR* GetWindowTitle() { return m_szTitle; }
	WCHAR* GetWindowClass() { return m_szWindowClass; }
	void SetWindowWidth(int w) {
		m_width = w;
	}

	void SetWindowHeight(int h) {
		m_height = h;
	}

	void SetTitle(WCHAR* title) {
		memcpy(m_szTitle, title, sizeof(title));
	}

	void FAIL_MSG_BOX(LPWSTR msg) { MessageBox(m_hWnd, msg, L"Error", MB_OK); }

	static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	virtual ATOM MyRegisterClass(HINSTANCE hInstance);
	virtual int InitInstance(HINSTANCE, int);
};
	
