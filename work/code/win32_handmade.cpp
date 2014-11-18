/***
* win32_handmade.cpp - Win32 Hand Made Hero Game
*
*       Copyright (c) ddApps. All rights reserved.
*
* Purpose:
*       This is the Windows 32 bit version of the hand made game engine.
*
*******************************************************************************/

#include <windows.h>

int CALLBACK 
WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow)
{
	MessageBox(0, "This is Handmade Hero", "Handmade Hero",
  	         MB_OK | MB_ICONINFORMATION);
	
	return(0);
}
