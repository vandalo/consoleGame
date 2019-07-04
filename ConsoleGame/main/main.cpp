// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SourceFiles/Application.h"
#include <windows.h>
#include "SourceFiles/Defines.h"

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, W_WIDTH, W_HEIGTH, TRUE);

	Application* application = new Application();
	application->Init();
	while (application->update());
    return 0;
}

