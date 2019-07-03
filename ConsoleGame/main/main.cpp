// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SourceFiles/Application.h"

int main()
{
	Application* application = new Application();
	application->Init();
	while (application->update());
    return 0;
}

