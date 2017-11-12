#include "XMain.h"

bool XIllumin::ParseInitFile(const std::string & fileName)
{
	std::ifstream initFile(fileName);
	std::string in;
	std::string token="";

	if (initFile.is_open())
	{		
		while (getline(initFile, token))
		{
			if (token.find_first_of("map") == 0) // check if the line begins with "map"
			{
				if (token.find_first_of(' ') == 3)
				{
					m_currentMapName = token.substr(4, token.length() - 4);
				} // map name not found
				else
				{
					initFile.close();
					return false;
				}
			}
		}
	}
	else
	{
		FAIL_MSG_BOX(L"Unable to open init file.");
		return false;
	}

	initFile.close();

	return true;
}

bool XIllumin::ParseEntities(void)
{
	m_numEntities = 0;
	std::string ents = std::string(m_pMap->GetEntities().ents);

	int pos;
	std::istringstream entStream(ents);
	std::string line;
	bool playerPosFound = false;
	int entDataPos = 0;
	std::string entClassName, entName;
	int x=0, y=0, z=0;
	
	while (std::getline(entStream, line))
	{	
		if (line == "{")
		{
			while (line != "}")
			{	
				std::getline(entStream, line);

				if ((entDataPos = line.find("\"classname\"")) != std::string::npos)
				{
					entName = line.substr(std::string("\"classname\" ").length() + 1, line.length() - 1);
				}
				else if ((entDataPos = line.find("\"origin\"")) != std::string::npos)
				{
					std::string entPosLine = line.substr(std::string("\"origin\" ").length() + 1, line.length() - 1);

					std::stringstream entPos(entPosLine);
					entPos >> x;
					entPos >> y;
					entPos >> z;
				}
				else if ((entDataPos = line.find("\"model\"")) != std::string::npos)
				{
					
				}
			}
		}
				
		if (entName == "info_player_start\"" || entName == "info_player_deathmatch\"")
		{
			m_playerEntityIndex = m_numEntities;
			m_pEntities.push_back(new XPlayer(entName, D3DXVECTOR3(x, z, y), D3DXVECTOR3(0, 0, 1), SCREEN_WIDTH, SCREEN_HEIGHT, 90, 0.1, 10000));
		}
		else
		{		
			m_pEntities.push_back(new XEntity(entName, D3DXVECTOR3(x, z, y), D3DXVECTOR3(0, 0, 1), SCREEN_WIDTH, SCREEN_HEIGHT, 90, 0.1, 10000));
		}

		m_numEntities++;	
	}

	return playerPosFound;
}

bool XIllumin::InitGameObjects(const std::string& params)
{
	m_pD3D = new XD3DRenderer();
	m_pTimer = new XTimer();

	m_pUICamera = new XCamera(D3DXVECTOR3(0.0f, 0.0f, 1.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), SCREEN_WIDTH, SCREEN_HEIGHT, 0.1f, 10000.0f);

	m_pInput = new XInput();
	m_pInput->Initialize(m_hInst, m_hWnd, m_width, m_height);

	if (!m_pD3D->CreateD3DDevice(m_hWnd, m_width, m_height, false))
	{
		FAIL_MSG_BOX(L"Error initializing Direct3D");
		return false;
	}

	if (!m_pD3D->CreateDepthBuffer())
	{
		FAIL_MSG_BOX(L"Error creating depth buffer");
		return false;
	}

	if (!m_pD3D->CreateRenderTargetView())
	{
		FAIL_MSG_BOX(L"Error creating target view");
		return false;
	}
	if (!m_pD3D->CreateDepthStencilView())
	{
		FAIL_MSG_BOX(L"Error depth stencil");
		return false;
	}

	m_pTextureManager = new XTextureManager(m_pD3D->GetD3DDevice(), m_pD3D->GetDeviceContext());

	m_pMap = new XWorldMap(m_pD3D->GetDeviceContext(), m_pD3D->GetD3DDevice(), m_pTextureManager);

	if (!m_pMap->LoadLightmapShader())
	{
		FAIL_MSG_BOX(L"Error loading lightmap shader");
		return false;
	}

	if (!m_pMap->CreateInputLayout())
	{
		FAIL_MSG_BOX(L"Error creating input layout");
		return false;
	}

	m_pTextureManager->CreateSamplerState();
	
	if (!m_pMap->Load(m_currentMapName))
	{
		FAIL_MSG_BOX(L"Error loading map");
		return false;
	}

	ParseEntities();

	return true;
}


bool XIllumin::RenderAll(const std::string& args)
{
	m_pD3D->ClearScene(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));

	if (!m_pD3D->Render(m_pMap, GetPlayer()->GetCamera()))
		return false;

	m_pD3D->ShowScene();
	return true;
}


bool XIllumin::GameMain(const std::string& args)
{
	m_pTimer->StartCounter();

	m_pInput->Poll();

	int mx, my;
	m_pInput->GetMouseDelta(mx, my);

	double deltaT = 0.001*m_pTimer->GetElapsedTime();
	GetPlayer()->GetCamera()->Pitch(my*0.01);
	GetPlayer()->GetCamera()->RotateAtAroundY(mx*0.01);

	if (m_pInput->IsKeyPressed(DIK_Q))
		GetPlayer()->GetCamera()->Pitch(deltaT);
	if(m_pInput->IsKeyPressed(DIK_C))
		GetPlayer()->GetCamera()->Pitch(-deltaT);
	if (m_pInput->IsKeyPressed(DIK_W))
		GetPlayer()->GetCamera()->Move(100*deltaT);
	if (m_pInput->IsKeyPressed(DIK_S))
		GetPlayer()->GetCamera()->Move(-100*deltaT);
	if (m_pInput->IsKeyPressed(DIK_A))
		GetPlayer()->GetCamera()->RotateAtAroundY(deltaT);
	if (m_pInput->IsKeyPressed(DIK_D))
		GetPlayer()->GetCamera()->RotateAtAroundY(-deltaT);

	GetPlayer()->GetCamera()->UpdateViewMatrix();

	m_pMap->AddSurfacesToDraw(*GetPlayer()->GetCamera());

	RenderAll(" ");

	m_pTimer->CalculateElapsedTIme();

	return 1;
}


void XIllumin::CleanUp()
{
	delete m_pD3D;
	delete m_pMap;
	delete m_pTimer;
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	XIllumin* pMainGameWindow = new XIllumin(L"X3DEngine", 800, 600);
	
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	if (LoadStringW(hInstance, IDS_APP_TITLE, pMainGameWindow->GetWindowTitle(), MAX_LOADSTRING) == 0)
		return FALSE;

	if (LoadStringW(hInstance, IDC_WIN32PROJECT1, pMainGameWindow->GetWindowClass(), MAX_LOADSTRING) == 0)
		return FALSE;

	pMainGameWindow->MyRegisterClass(hInstance);

	if (!pMainGameWindow->InitInstance(hInstance, nCmdShow))
		return FALSE;
	
	ShowCursor(0);
	

	if (!pMainGameWindow->ParseInitFile("Config/GameInit.txt"))
	{
		pMainGameWindow->FAIL_MSG_BOX(L"Error loading init file.");
		return FALSE;
	}
	
	pMainGameWindow->InitGameObjects(" ");

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));
	MSG msg;
	
	
	
	while (1)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				pMainGameWindow->CleanUp();
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		
		if (!pMainGameWindow->GameMain(" "))
				break;
	}

	return (int)msg.wParam;
}
