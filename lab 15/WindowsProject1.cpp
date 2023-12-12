// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject1.h"
#include "Images.h"

#define MAX_LOADSTRING 100
#define NUM_IM_A 9
#define NUM_IM_B 20

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна


struct Image {
    int x;
    int y;
    int vx;
    int vy;
};

struct Image im1 = { 100, 200, 10, 0 };

typedef struct Image IMAGE;

IMAGE im2 = { 400,200, -10, 0 };

IMAGE im3 = { 250, 50, 0, 10 };

IMAGE im4 = { 250, 350, 0, -10 };

IMAGE im5 = { 250, 200, 0, 0};

IMAGE imA[NUM_IM_A] = {
    {700, 300, 10, 0},
    {700, 300, 9, 4},
    {700, 300, 7, 7},
    {700, 300, 4, 9},
    {700, 300, 0, 10},
    {700, 300, -4, 9},
    {700, 300, -7, 7},
    {700, 300, -9, 4},
    {700, 300, -10, 0}
};

IMAGE imB[NUM_IM_B] = {
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300},
    {900, 300}
};



// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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


    case WM_CREATE:
    {
        SetTimer(hWnd, 1, 500, 0);
        break;
    }

    case WM_TIMER:
    {
        im1.x += im1.vx;
        im1.y += im1.vy;

        im2.x += im2.vx;
        im2.y += im2.vy;

        im3.x += im3.vx;
        im3.y += im3.vy;

        im4.x += im4.vx;
        im4.y += im4.vy;

        int dx5 = rand() % 21 - 10;
        int dy5 = rand() % 21 - 10;

        im5.x += dx5;
        im5.y += dy5;

        InvalidateRect(hWnd, NULL, TRUE);

        int i = 0;
        while (i < NUM_IM_A) {
            imA[i].x += imA[i].vx;
            imA[i].y += imA[i].vy;

            i += 1;
        }


        int j = 0;
        while (j < NUM_IM_B) {
            int ax7 = rand() % 21 - 10;
            int ay7 = rand() % 21 - 10;
            imB[j].x += ax7;
            imB[j].y += ay7;

            j += 1;
        }


        break;
    }

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...

            Image0(hdc, im1.x, im1.y, RGB(128,128,0));
            Image1(hdc, im2.x, im2.y, RGB(128, 128, 0));
            Image2(hdc, im3.x, im3.y, RGB(128, 128, 0));
            Image3(hdc, im4.x, im4.y, RGB(128, 128, 0));
            Image3(hdc, im5.x, im5.y, RGB(128, 128, 0));

            int i = 0;
            while (i < NUM_IM_A) {
                Image3(hdc, imA[i].x, imA[i].y, RGB(255, 0, 255));
                i += 1;
            }

            int j = 0;
            while (j < NUM_IM_B) {
                Image2(hdc, imB[j].x, imB[j].y, RGB(0, 255, 255));
                j += 1;
            }

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
