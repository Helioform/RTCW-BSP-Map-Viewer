// Game.cpp : Defines the entry point for the application.
//
#include <windowsx.h>

#include "Game.h"
#include "../Library/Graphics/D3D11GraphicsAPI.h"
#include "../Library/Graphics/Shader.h"
#include "../Library/Scene.h"
#include <chrono>

#include <fstream>

using namespace Helios;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND hWnd;
const int WindowHeight = 600;
const int WindowWidth = 800;
std::unique_ptr<Scene> scene;
uint32_t mouseX=0, mouseY=0;
bool gameStarted = false;
enum class GAME_STATE
{
    MENU,
    GAME
};

GAME_STATE state = GAME_STATE::MENU;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAME));
    
    scene = std::make_unique<Scene>(hWnd, 800, 600, false);
    
    


    MSG msg;

    // Main message loop:
    while (1)
    {
        GetMessageW(&msg, nullptr, PM_REMOVE, 0);
        if (msg.message == WM_QUIT)
            break;

        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        if (state == GAME_STATE::MENU)
        {
            if(gameStarted)
                state = GAME_STATE::GAME;
        }
        else if (state == GAME_STATE::GAME)
        {
            // save current time
            const auto start{ std::chrono::steady_clock::now() };

            scene->ClearScreen();


            RECT r;

            GetWindowRect(hWnd, &r);
            InvalidateRect(hWnd, &r, false);
            /* scene->GetCamera()->UpdateViewMatrix();
             scene->SetCameraConstantBufferParams();*/

            scene->Update(0.001f);


            scene->PresentToScreen();

            // save frame end time
            const auto end{ std::chrono::steady_clock::now() };

            const std::chrono::duration<double> elapsed_seconds{ end - start };

            // const double fps = 1.0 / elapsed_seconds;

            // scene->SetMousePos(mouseX, mouseY);

            /* MousePosition ms = scene->CalculateMouseDelta();


             }
             scene->SetLastMousePos(mouseX, mouseY);*/
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, WindowWidth, WindowHeight, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
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
            RECT r;
            r.left = 0;
            r.right = 800;
            r.bottom = 600;
            r.top = 0;
            
                // TODO: Add any drawing code that uses hdc here...
            DrawTextA(hdc, "Click to Play",13, &r, DT_CENTER);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_MOUSEMOVE:
       /* mouseX = GET_X_LPARAM(lParam);
        mouseY = GET_Y_LPARAM(lParam);*/
        break;

    case WM_LBUTTONDOWN:
        gameStarted = true;
        break;
    case WM_KEYDOWN:

        // WASD movement
        // W
        if (wParam == 0x57) {
            scene->MovePlayer(0.26f);
       
       
        }

        // A
        if (wParam == 0x41) {
            scene->RotatePlayer(-0.01);
         
          
        }
        //D
        if (wParam == 0x44) {
            scene->RotatePlayer(0.01);
     
       
        }

        //S
        if (wParam == 0x53) {
            scene->MovePlayer(-0.16f);
      
            
        }

        return 0;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
