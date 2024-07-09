#include <windows.h>
#include <math.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "msimg32.lib")

// Define M_PI if not defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Global variables
HINSTANCE hInst;
HWND hWndMain;

// Forward declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;

    // Register the window class
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW, WndProc, 0, 0,
                        hInstance, NULL, LoadCursor(NULL, IDC_ARROW), (HBRUSH)(COLOR_WINDOW + 1),
                        NULL, TEXT("WindowApp"), NULL };
    RegisterClassEx(&wcex);

    // Create the window
    hWndMain = CreateWindow(TEXT("WindowApp"), TEXT("Star Shape"), WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
    if (!hWndMain) {
        return FALSE;
    }

    // Show and update the window
    ShowWindow(hWndMain, nCmdShow);
    UpdateWindow(hWndMain);

    // Message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

void DrawStar(HDC hdc, int x, int y, int size) {
    POINT star[10];
    double angle = -M_PI / 2; // Start at the top of the star
    double step = M_PI / 5;   // 36 degrees in radians

    for (int i = 0; i < 10; i++) {
        double r = (i % 2 == 0) ? size : size / 2.5; // Outer and inner points
        star[i].x = (LONG)(x + r * cos(angle));
        star[i].y = (LONG)(y + r * sin(angle));
        angle += step;
    }

    Polygon(hdc, star, 10);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // Define gradient rectangle
        RECT gradientRect;
        GetClientRect(hWnd, &gradientRect);

        // Define gradient colors
        COLORREF colorStart = RGB(0, 0, 128);   // Dark blue
        COLORREF colorEnd = RGB(173, 216, 230); // Light blue

        // Fill the gradient background
        TRIVERTEX vert[2] = {
            { 0, 0, (USHORT)GetRValue(colorStart) << 8, (USHORT)GetGValue(colorStart) << 8, (USHORT)GetBValue(colorStart) << 8, 0 },
            { gradientRect.right, gradientRect.bottom, (USHORT)GetRValue(colorEnd) << 8, (USHORT)GetGValue(colorEnd) << 8, (USHORT)GetBValue(colorEnd) << 8, 0 }
        };
        GRADIENT_RECT gRect = { 0, 1 };
        GradientFill(hdc, vert, 2, &gRect, 1, GRADIENT_FILL_RECT_V);

        // Draw a star in the center filled with red color
        int centerX = gradientRect.right / 2;
        int centerY = gradientRect.bottom / 2;
        int starSize = 100;

        HBRUSH hRedBrush = CreateSolidBrush(RGB(255, 0, 0)); // Red color
        HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hRedBrush);
        DrawStar(hdc, centerX, centerY, starSize);
        SelectObject(hdc, hOldBrush);
        DeleteObject(hRedBrush);

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
