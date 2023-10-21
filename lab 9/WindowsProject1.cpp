// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "WindowsProject1.h"

#define MAX_LOADSTRING 100


//Рисование лого Санты
void StClausAuto(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 200, 0));
    SelectObject(hdc, hPen);
    //верхний треугольник
    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y); 
    LineTo(hdc, 10 + x, 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    //средний треугольник
    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    //нижний треугольник
    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 0 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);
}

//Рисование грузовика
void drawTruck(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    SelectObject(hdc, hPen);

    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, 0 + y, 100 + x, 50 + y);

    hPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    SelectObject(hdc, hPen);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);
}

//Рисование пяти грузовиков по углам и в центре
void drawTrucks1(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 310, 310);
    drawTruck(hdc, 160, 160);
}

//Рисование грузовиков 2
void drawTrucks2(HDC hdc) {
    int x1 = 20;
    do {
        drawTruck(hdc, x1, 10);
        x1 += 120;
    } while (x1 < 740);
}

//Рисование грузовиков 3
void drawTrucks3(HDC hdc) {
    int y1 = 20;
    do {
        drawTruck(hdc, 10, y1);
        y1 += 80;
    } while (y1 < 500);
}

//Рисование грузовиков 4
void drawTrucks4(HDC hdc) {
    int x1 = 20, y1 = 20;
    do {
        drawTruck(hdc, x1, y1);
        x1 += 120;
        y1 += 80;
    } while (y1 < 500);
}

//Рисование снеговика
void SnowWoman(HDC hdc, int x, int y) {
    //Тело
    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    //Руки
    MoveToEx(hdc, 12+x, 30+y, NULL);
    LineTo(hdc, 0+x, 40+y);
    MoveToEx(hdc, 48 + x, 30 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);

    //Метла
    MoveToEx(hdc, 40 + x, 120 + y, NULL);
    LineTo(hdc, 70 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 64 + x, 0 + y);
    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 76 + x, 0 + y);
}

//Задача 3.3
void drawSnowWomen1(HDC hdc) {
    SnowWoman(hdc, 10, 10);
    SnowWoman(hdc, 10, 310);
    SnowWoman(hdc, 310, 10);
    SnowWoman(hdc, 310, 310);
    SnowWoman(hdc, 160, 160);

}

//Задача 3.4
void drawSnowWomen2(HDC hdc) {
    int x1 = 20;
    do {
        SnowWoman(hdc, x1, 10);
        x1 += 120;
    } while (x1 < 740);
}

//Задача 3.5
void drawSnowWomen3(HDC hdc) {
    int y1 = 0;
    do {
        SnowWoman(hdc, 10, y1);
        y1 += 130;
    } while (y1 < 500);
}

//Задача 3.6
void drawSnowWomen4(HDC hdc) {
    int y1 = 0, x1 = 20;
    do {
        SnowWoman(hdc, x1, y1);
        x1 += 120;
        y1 += 130;
    } while (y1 < 500);
}

//Рисование логотипа авто
void  drawReno(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
    SelectObject(hdc, hPen);
    MoveToEx(hdc, 40 + x, 0 + y, NULL);
    LineTo(hdc, 60 + x, 40 + y);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 20 + x, 80 + y);
    LineTo(hdc, 40 + x, 40 + y);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 40 + x, 0 + y);
    LineTo(hdc, 20 + x, 0 + y);
    LineTo(hdc, 0 + x, 40 + y);
    LineTo(hdc, 20 + x, 80 + y);
    MoveToEx(hdc, 30 + x, 60 + y, NULL);
    LineTo(hdc, 20 + x, 40 + y);
    LineTo(hdc, 30 + x, 20 + y);
}

//Задача 5.1
void drawRenos1(HDC hdc) {
    drawReno(hdc, 10, 10);
    drawReno(hdc, 10, 310);
    drawReno(hdc, 310, 10);
    drawReno(hdc, 310, 310);
    drawReno(hdc, 160, 160);

}

//Задача 5.2
void drawRenos2(HDC hdc) {
    int x1 = 0;
    do {
        drawReno(hdc, x1, 10);
        x1 += 80;
    } while (x1 < 640);
}

//Задача 5.3
void drawRenos3(HDC hdc) {
    int y1 = 0;
    do {
        drawReno(hdc, 10, y1);
        y1 += 90;
    } while (y1 < 360);
}

//Задача 5.4
void drawRenos4(HDC hdc) {
    int y1 = 0, x1 = 20;
    do {
        drawReno(hdc, x1, y1);
        x1 += 60;
        y1 += 90;
    } while (y1 < 360);
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

            //Задача 1.1
            /*StClausAuto(hdc, 0, 0);
            StClausAuto(hdc, 200, 200);
            StClausAuto(hdc, 100, 100);
            StClausAuto(hdc, 0, 200);
            StClausAuto(hdc, 200, 0);*/

            //Задача 1.2
            /*int x = 0;
            do {
                StClausAuto(hdc, x, 0);
                x += 50;
            } while (x < 400);*/

            //Задача 1.3
            /*int y = 0;
            do {
                StClausAuto(hdc, 0, y);
                y += 90;
            } while (y < 300);*/

            //Задача 1.4
            /*int x = 0, y = 0;
            do {
                StClausAuto(hdc, x, y);
                x += 50;
                y += 90;
            } while (x < 200);*/

            //Задача 2.1
            /*drawTruck(hdc, 50, 50);
            drawTruck(hdc, 200, 200);*/

            //Задача 2.2
            //drawTrucks1(hdc);

            //Задача 2.3
            //drawTrucks2(hdc);

            //Задача 2.4
            //drawTrucks3(hdc);

            //Задача 2.5
            //drawTrucks4(hdc);

            //Задача 3.1
            //SnowWoman(hdc, 0, 0);

            //Задача 3.3
            //drawSnowWomen1(hdc);

            //Задача 3.4
            //drawSnowWomen2(hdc);

            //Задача 3.5
            //drawSnowWomen3(hdc);

            //Задача 3.6
            //drawSnowWomen4(hdc);

            //Задача 4
            //drawReno(hdc,0,0);

            //Задача 5.1
            //drawRenos1(hdc);

            //Задача 5.2
            //drawRenos2(hdc);

            //Задача 5.3
            //drawRenos3(hdc);

            //Задача 5.4
            //drawRenos4(hdc);

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
