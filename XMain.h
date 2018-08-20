#pragma once

#include "XPlayer.h"
#include "XWindow.h"
#include "XD3D.h"
#include "XInput.h"
#include "XTimer.h"
#include "CollisionSystem.h"
#include "XFont.h"

class XIllumin : public XWindow
{

private:
	static XIllumin		m_instance;

protected:
	XFont*				m_pFont;
	XTimer*				m_pTimer;
	XGeomObject*		m_pGeom;
	XCamera*			m_pUICamera;
	XWorldMap*			m_pMap;
	CollisionSystem*	m_pCollisionHandler;
	XInput*				m_pInput;
	std::string			m_currentMapName;
	bool				m_fullScreen;
	int					m_screenWidth;
	int					m_screenHeight;
public:
	XIllumin() { }
	XIllumin(WCHAR* title, int width, int height) : XWindow(title, width, height)
	{
		m_pMap = nullptr; m_pTimer = nullptr; m_pCollisionHandler = nullptr; m_pFont = nullptr;
	}

	~XIllumin()
	{
		if (m_pMap) delete m_pMap;
		if (m_pTimer) delete m_pTimer;
		if (m_pCollisionHandler) delete m_pCollisionHandler;
		if (m_pFont) delete m_pFont;
	}

	void SetHeight(int h) {
		m_screenHeight = h;
	}

	void SetWidth(int w) {
		m_screenWidth = w;
	}

	int GetHeight() {
		return m_screenHeight;
	}

	int GetWidth() {
		return m_screenWidth;
	}
	
	ATOM MyRegisterClass(HINSTANCE hInstance);
	int InitInstance(HINSTANCE, int);
	static LRESULT CALLBACK WndProc2(HWND, UINT, WPARAM, LPARAM);
	bool ParseCFGFile(const std::string& fileName);
	bool InitGameObjects(const std::string& params);
	bool GameMain(const std::string& args);
	void CleanUp();
	void SwitchToFullscreen() {
		
	}
	bool RenderAll(const std::string& params);

};

XIllumin* g_pMainGameWindow;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow);