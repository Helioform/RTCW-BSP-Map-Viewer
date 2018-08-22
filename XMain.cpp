#include "XMain.h"

XIllumin XIllumin::m_instance;

ATOM XIllumin::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = WS_OVERLAPPED;// CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc2;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = m_szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL XIllumin::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	m_hInst = hInstance;

	m_hWnd = CreateWindowW(m_szWindowClass, m_szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, m_width, m_height, nullptr, nullptr, hInstance, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);

	return TRUE;
}

LRESULT CALLBACK XIllumin::WndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_KEYDOWN:
	{
		
		return 0;

	}
	break;
	case WM_DESTROY:
		m_instance.CleanUp();
		delete g_pMainGameWindow;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

bool XIllumin::ParseCFGFile(const std::string & fileName)
{
	std::ifstream initFile(fileName);
	std::string in;
	std::string token="";
	std::string map("map"), fullscreen("rfullscreen"), width("rwidth"), height("rheight");

	if (initFile.is_open())
	{		
		while (getline(initFile, token))
		{
			if (token.find(map) != std::string::npos) // check if the line begins with "map"
			{
				if (token.find_first_of(' ') == 3)
				{
					m_currentMapName = token.substr(map.length()+1, token.length() - map.length()+1);
				} // map name not found
				else
				{
					initFile.close();
					return false;
				}
			}

			if (token.find(fullscreen) != std::string::npos)
			{
				std::string i = token.substr(fullscreen.length()+1, token.length() - fullscreen.length()+1);
				if (i == "0")
					m_fullScreen = false;
				else
					m_fullScreen = true;
			}

			if (token.find(width) != std::string::npos)
			{
				std::string w = token.substr(width.length() + 1, token.length() - width.length() + 1);
				m_screenWidth = atoi(w.c_str());
			}

			if (token.find(height) != std::string::npos)
			{
				std::string h = token.substr(height.length() + 1, token.length() - height.length() + 1);
				m_screenHeight = atoi(h.c_str());
			}
		}
	}
	else
	{
		FAIL_MSG_BOX("Unable to open init file.");
		return false;
	}

	initFile.close();

	return true;
}


bool XIllumin::InitGameObjects(const std::string& params)
{
	m_pTimer = new XTimer();

	m_pUICamera = new XCamera(D3DXVECTOR3(0.0f, 0.0f, 1.0f), D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, -5.0f), SCREEN_WIDTH, SCREEN_HEIGHT, 0.1f, 1000.0f);

	m_pInput = new XInput();
	m_pInput->Initialize(m_hInst, m_hWnd, m_screenWidth, m_screenHeight);
	
	if (!XD3DRenderer::GetSingletonPointer()->InitD3D(m_hWnd, m_screenWidth, m_screenHeight, m_fullScreen))
	{
		FAIL_MSG_BOX("Error initializing Direct3D.");
		return false;
	}

	XTextureManager::GetSingletonPointer()->CreateSamplerState();
	
	m_pFont = new XFont(XD3DRenderer::GetSingletonPointer(), XTextureManager::GetSingletonPointer(), 10, 2500, 20);
	if(!m_pFont->LoadFontTextureMap("Fonts/sanstransparent.png"))
	{
		FAIL_MSG_BOX("Error loading font");
		return false;
	}

	XD3DRenderer::GetSingletonPointer()->ClearScene(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));

	m_pFont->WriteText(0, 10, "Loading map...", D3DXVECTOR4(1.0, 1.0, 1.0, 1.0), m_pUICamera);

	XD3DRenderer::GetSingletonPointer()->ShowScene();

	m_pMap = new XWorldMap(XD3DRenderer::GetSingletonPointer(), XTextureManager::GetSingletonPointer());

	if (!m_pMap->LoadLightmapShader())
	{
		FAIL_MSG_BOX("Error loading lightmap shader");
		return false;
	}

	if (!m_pMap->CreateInputLayout())
	{
		FAIL_MSG_BOX("Error creating input layout");
		return false;
	}

	if (!m_pMap->Load(m_currentMapName))
	{
		FAIL_MSG_BOX("Error loading map");
		return false;
	}
	
	
	m_pMap->LoadEntities();

	m_pCollisionHandler = new CollisionSystem(m_pMap);

	return true;
}


bool XIllumin::RenderAll(const std::string& args)
{
	XD3DRenderer::GetSingletonPointer()->ClearScene(D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f));
	
	int numFaces = m_pMap->GetVisibleFaces().size();
	//m_pFont->WriteText(100, 100, "Number of triangles drawn: " + std::to_string(numFaces), D3DXVECTOR4(0.0,1.0,0.0,0.0), m_pUICamera);
	
	m_pMap->Render(m_pMap->GetPlayer()->GetCamera());

	XD3DRenderer::GetSingletonPointer()->ShowScene();
	return true;
}


bool XIllumin::GameMain(const std::string& args)
{
	m_pTimer->StartCounter();

	m_pInput->Poll();

	int mx, my;
	m_pInput->GetMouseDelta(mx, my);

	double deltaT = 0.001*m_pTimer->GetElapsedTime();
	m_pMap->GetPlayer()->GetCamera()->Pitch(my*0.01);
	m_pMap->GetPlayer()->GetCamera()->RotateAtAroundY(mx*0.01);
	m_pMap->GetPlayer()->SetVelocity(deltaT * 5*PLAYER_VELOCITY);
	
	//m_pCollisionHandler->HandlePlayerCollisions();
	
	if (m_pInput->IsKeyPressed(DIK_W))
		m_pMap->GetPlayer()->WalkForward();
	
	if (m_pInput->IsKeyPressed(DIK_S))
		m_pMap->GetPlayer()->WalkBackward();
	
	m_pMap->GetPlayer()->GetCamera()->UpdateViewMatrix();

	m_pMap->SetLeafPosition(m_pMap->FindLeaf(m_pMap->GetPlayer()->GetCamera()->Eye()));
	
	m_pMap->AddSurfacesToDraw(*m_pMap->GetPlayer()->GetCamera());

	RenderAll(" ");
	
	
	m_pTimer->CalculateElapsedTime();

	return 1;
}


void XIllumin::CleanUp()
{
	delete m_pMap;
	delete m_pTimer;
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	g_pMainGameWindow = new XIllumin();
	
	if (!g_pMainGameWindow->ParseCFGFile("Config/GameInit.txt"))
	{
		g_pMainGameWindow->FAIL_MSG_BOX("Error loading init file.");
		return FALSE;
	}

	g_pMainGameWindow->SetTitle(L"Xi Engine");
	g_pMainGameWindow->SetWindowWidth(g_pMainGameWindow->GetWidth());
	g_pMainGameWindow->SetWindowHeight(g_pMainGameWindow->GetHeight());

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	if (LoadStringW(hInstance, IDS_APP_TITLE, g_pMainGameWindow->GetWindowTitle(), MAX_LOADSTRING) == 0)
		return FALSE;

	if (LoadStringW(hInstance, IDC_WIN32PROJECT1, g_pMainGameWindow->GetWindowClass(), MAX_LOADSTRING) == 0)
		return FALSE;

	if (!g_pMainGameWindow->MyRegisterClass(hInstance))
	{
		g_pMainGameWindow->FAIL_MSG_BOX("Failed to create window.");
		return FALSE;
	}

	if (!g_pMainGameWindow->InitInstance(hInstance, nCmdShow))
	{
		g_pMainGameWindow->FAIL_MSG_BOX("Failed to create instance.");
		return FALSE;
	}
	
	ShowCursor(0);
	
	if (!g_pMainGameWindow->InitGameObjects(" "))
	{
		g_pMainGameWindow->FAIL_MSG_BOX("Failed to create game objects.");
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));
	MSG msg;
	
	
	// main game loop
	while (1)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		
		if (!g_pMainGameWindow->GameMain(" "))
				break;
	}

	return (int)msg.wParam;
}
