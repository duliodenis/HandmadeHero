/***
* win32_handmade.cpp - Win32 Hand Made Hero Game
*
* Created by Dulio Denis on 11/18/14.
*       Copyright (c) ddApps. All rights reserved.
*
* Purpose:
*       This is the Windows 32 bit version of the hand made game engine.
*
*******************************************************************************/

#include <windows.h>

LRESULT CALLBACK MainWindowCallback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam) {
	LRESULT Result = 0;
	switch(Message) {
		case WM_SIZE: {
			OutputDebugStringA("WM_SIZE\n");
			break;
		}

		case WM_DESTROY: {
			OutputDebugStringA("WM_DESTROY\n");
			break;
		}

		case WM_CLOSE: {
			OutputDebugStringA("WM_CLOSE\n");
			break;
		}

		case WM_ACTIVATEAPP: {
			OutputDebugStringA("WM_ACTIVATEAPP\n");
			break;
		}

		case WM_PAINT: {
			PAINTSTRUCT Paint;
			HDC DeviceContext = BeginPaint(Window, &Paint);
			int X = Paint.rcPaint.left;
			int Y = Paint.rcPaint.top;
			int Height = Paint.rcPaint.bottom - Paint.rcPaint.top;
			int Width = Paint.rcPaint.right - Paint.rcPaint.left;
			PatBlt(DeviceContext, X, Y, Width, Height, BLACKNESS);
			EndPaint(Window, &Paint);
			break;
		}

		default: {
			// OutputDebugStringA("Other Window Message\n");
			Result = DefWindowProc(Window, Message, WParam, LParam);
			break;
		}
	}
	return(Result);
}

int CALLBACK 
WinMain(HINSTANCE Instance,
        HINSTANCE PrevInstance,
        LPSTR CommandLine,
        int ShowCode)
{
	WNDCLASS WindowClass = {};
	// (dd): research if we still need these styles
	WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	WindowClass.lpfnWndProc = MainWindowCallback;
	WindowClass.hInstance = Instance;
	WindowClass.lpszClassName = "HandmadeHeroWindowClass";

	if (RegisterClass(&WindowClass)) {
		HWND WindowHandle = CreateWindowEx(0, WindowClass.lpszClassName, "Handmade Hero", 
			WS_OVERLAPPEDWINDOW|WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 0, 0, Instance, 0);
		if (WindowHandle) {
			for(;;) {
				MSG Message;
				BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
				if (MessageResult > 0) {
					TranslateMessage(&Message);
					DispatchMessage(&Message);
				} else {
					break;
				}
			}
		} else {
			// (dd): Log out Create Window error
		}
	} else {
		// (dd): Log out RegisterClass for Window error
	}

	return(0);
}
