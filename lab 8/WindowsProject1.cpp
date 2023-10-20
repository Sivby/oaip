// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100
//Рисование дома из ЛР4
void drawHome(HDC hdc) {
    //крыша
    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);

    //дом
    LineTo(hdc, 400, 525);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 150, 350);
    LineTo(hdc, 400, 350);

    //окно
    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 225, 400);

    //рама
    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);
    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);
}

//Рисование автомобиля из ЛР5
void drawCar(HDC hdc) {

    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(128, 0, 0));
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

    hBrush = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 128, 0));
    SelectObject(hdc, hBrush);

    Ellipse(hdc, 225, 225, 275, 275);
}


//Рисование дерева из ЛР7
void drawTree(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 200, 0));
    SelectObject(hdc, hPen);

    int x1 = 0, y1 = 250;
    int x2 = 100, y2 = 250;

    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 -= 10;
    } while (x1 <= 100);

    x1 = 100;
    y1 = 50;
    do {
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        x1 += 5;
        y1 += 10;
    } while (x1 <= 200);
}

//Рисование забора
void drawFence(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    int x = 0;
    do {
        MoveToEx(hdc, 600+x, 200, NULL);
        LineTo(hdc, 600 + x, 260);
        LineTo(hdc, 580 + x, 260);
        LineTo(hdc, 580 + x, 200);
        LineTo(hdc, 590 + x, 180);
        LineTo(hdc, 600 + x, 200);
        x+=20;
    } while (x < 140);
}

//Рисование дерева 2
void drawTree2(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 150, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 75, 350, NULL);
    LineTo(hdc, 75, 525);
    MoveToEx(hdc, 75, 375, NULL);

    LineTo(hdc, 62, 362);
    MoveToEx(hdc, 75, 400, NULL);
    LineTo(hdc, 100, 375);
    MoveToEx(hdc, 75, 425, NULL);
    LineTo(hdc, 40, 390);
    MoveToEx(hdc, 75, 450, NULL);
    LineTo(hdc, 120, 420);
    MoveToEx(hdc, 75, 475, NULL);
    LineTo(hdc, 25, 435);
    MoveToEx(hdc, 75, 500, NULL);
    LineTo(hdc, 125, 462);
}


//Рисование скамейки
void drawBench(HDC hdc) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(250, 0, 250));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 650, 500, NULL);
    LineTo(hdc, 700, 475);
    LineTo(hdc, 850, 475);
    LineTo(hdc, 800, 500);
    LineTo(hdc, 650, 500);
    MoveToEx(hdc, 700, 475, NULL);
    LineTo(hdc, 700, 425);
    LineTo(hdc, 850, 425);
    LineTo(hdc, 850, 525);
    MoveToEx(hdc, 800, 500, NULL);
    LineTo(hdc, 800, 550);
    MoveToEx(hdc, 700, 500, NULL);
    LineTo(hdc, 700, 525);
    MoveToEx(hdc, 650, 500, NULL);
    LineTo(hdc, 650, 550);
}



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
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            
            //Рисование дома
            drawHome(hdc);

            //Рисование автомобиля
            drawCar(hdc);

            //Рисование дерева
            drawTree(hdc);

            //Рисование забора
            drawFence(hdc);

            //Рисование дерева 2
            drawTree2(hdc);

            //Рисование скамейки
            drawBench(hdc);

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
