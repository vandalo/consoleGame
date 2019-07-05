// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SourceFiles/Application.h"
#include <windows.h>
#include "SourceFiles/Defines.h"

void CreateSingletons()
{
	Application::CreateInstance();
}

void DestroySingletons()
{
	Application::DestroyInstance();
}

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, W_WIDTH, W_HEIGTH, TRUE);

	CreateSingletons();
	Application& application = Application::GetInstance();
	application.Init();
	while (application.update());

	DestroySingletons();
    return 0;
}

