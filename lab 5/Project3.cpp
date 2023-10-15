// Project3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Project3.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

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
    LoadStringW(hInstance, IDC_PROJECT3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJECT3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECT3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJECT3);
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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...

            HPEN hPen;
            hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
            SelectObject(hdc, hPen);

            HBRUSH hBrush;
            hBrush = CreateSolidBrush(RGB(255, 128, 67));
            SelectObject(hdc, hBrush);

            Rectangle(hdc, 50, 200, 300, 250);

            MoveToEx(hdc, 100, 200, NULL);
            LineTo(hdc, 150, 150);
            LineTo(hdc, 250, 150);
            LineTo(hdc, 300, 200);

            hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 128));
            SelectObject(hdc, hPen);

            hBrush = CreateHatchBrush(HS_FDIAGONAL, RGB(255, 0, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 75, 225, 125, 275);

            hPen = CreatePen(PS_SOLID, 7, RGB(0, 128, 0));
            SelectObject(hdc, hPen);
            hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 255, 0));
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 225, 225, 275, 275);

            hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 128)); //Снеговик
            hBrush = CreateSolidBrush(RGB(230, 230, 230));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 400, 200, 500, 275);
            Ellipse(hdc, 410, 170, 490, 230);
            Ellipse(hdc, 425, 120, 475, 170);

            hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 410, 200, NULL);
            LineTo(hdc, 390, 205);
            LineTo(hdc, 380, 190);

            MoveToEx(hdc, 490, 200, NULL);
            LineTo(hdc, 510, 195);
            LineTo(hdc, 520, 180);

            hBrush = CreateSolidBrush(RGB(230, 0, 0));
            hPen = CreatePen(PS_SOLID, 3, RGB(200, 0, 0));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 435, 160, 465, 175);

            hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 440, 135, NULL);
            LineTo(hdc, 440, 136);
            MoveToEx(hdc, 460, 135, NULL);
            LineTo(hdc, 460, 136);

            MoveToEx(hdc, 450, 183, NULL);
            LineTo(hdc, 450, 183);
            MoveToEx(hdc, 450, 197, NULL);
            LineTo(hdc, 450, 197);
            MoveToEx(hdc, 450, 211, NULL);
            LineTo(hdc, 450, 211);
            
            hPen = CreatePen(PS_SOLID, 7, RGB(225, 117, 4));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 450, 140, NULL);
            LineTo(hdc, 461, 145);

            hPen = CreatePen(PS_SOLID, 7, RGB(0, 0, 0)); //Велосипед
            hBrush = CreateSolidBrush(RGB(50, 50, 50));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 550, 225, 600, 275);
            Ellipse(hdc, 640, 225, 690, 275);

            hPen = CreatePen(PS_SOLID, 6, RGB(0, 236, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 575, 250, NULL);
            LineTo(hdc, 610, 255);
            MoveToEx(hdc, 575, 250, NULL);
            LineTo(hdc, 600, 220);
            LineTo(hdc, 610, 255);
            
            hPen = CreatePen(PS_SOLID, 6, RGB(0, 236, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 665, 250, NULL);
            LineTo(hdc, 645, 210);
            LineTo(hdc, 610, 255);
            MoveToEx(hdc, 645, 210, NULL);
            LineTo(hdc, 600, 220);

            hPen = CreatePen(PS_SOLID, 6, RGB(0, 0, 0));
            SelectObject(hdc, hPen);
            MoveToEx(hdc, 600, 220, NULL);
            LineTo(hdc, 597, 213);
            MoveToEx(hdc, 590, 213, NULL);
            LineTo(hdc, 605, 213);
            MoveToEx(hdc, 645, 210, NULL);
            LineTo(hdc, 640, 200);
            LineTo(hdc, 625, 200);
            MoveToEx(hdc, 640, 200, NULL);
            LineTo(hdc, 645, 190);

            
            MoveToEx(hdc, 750, 275, NULL); //Дерево

            hPen = CreatePen(PS_SOLID, 6, RGB(80, 25, 0));
            hBrush = CreateSolidBrush(RGB(100, 30, 0));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Rectangle(hdc, 750, 230, 770, 275);
            hPen = CreatePen(PS_SOLID, 6, RGB(30, 100, 30));
            hBrush = CreateSolidBrush(RGB(50, 140, 0));
            SelectObject(hdc, hPen);
            SelectObject(hdc, hBrush);
            Ellipse(hdc, 730, 120, 790, 245);




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
