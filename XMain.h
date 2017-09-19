#pragma once

#include "XPlayer.h"
#include "XWindow.h"
#include "XD3D.h"
#include "XInput.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

class XIllumin : public XWindow
{
protected:
	// player object
	std::vector<XEntity*> m_pEntities;
	int m_numEntities;

	// The direct3d app object
	XD3DRenderer* m_pD3D;
	// The geometry to render
	XGeomObject* m_pGeom;
	XCamera* m_pUICamera;
	XWorldMap* m_pMap;
	XInput* m_pInput;
	XTextureManager* m_pTextureManager;
	std::string m_currentMapName;

public:
	XIllumin() { }
	XIllumin(WCHAR* title, int width, int height) : XWindow(title, width, height) { m_numEntities = 0; m_pD3D = nullptr; m_pMap = nullptr; }
	~XIllumin() { if (m_pD3D) delete m_pD3D; if (m_pMap) delete m_pMap; }

	bool ParseInitFile(const std::string& fileName);
	bool ParseEntities(void);
	bool InitD3D(const std::string& params);
	bool GameMain(const std::string& args);
	void CleanUp();
	bool RenderAll(const std::string& params);

};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow);