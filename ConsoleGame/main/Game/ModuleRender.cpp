#include "ModuleRender.h"
#include <stdlib.h>

ModuleRender::ModuleRender()
{}

void ModuleRender::Render(const CGameObject& player, const MyString& input, const MyVector<MyString>& lastActionResult)
{
	CleanScreen();
	PrintScreen();
	PrintConsole(input);
	PrintOutput(lastActionResult);
}

void ModuleRender::CleanScreen()
{
	system("cls");
}

void ModuleRender::PrintScreen()
{
	IOStream::cout << "----------------------------------------------------------------------";
	for (int i = 0; i < 20; ++i)
	{
		IOStream::cout << IOStream::endl;
	}
	IOStream::cout << "----------------------------------------------------------------------" << IOStream::endl;
}

void ModuleRender::PrintConsole(const MyString& input)
{
	IOStream::cout << IOStream::endl << "> " << input << IOStream::endl;
	IOStream::cout << IOStream::endl;
	IOStream::cout << "----------------------------------------------------------------------" << IOStream::endl;
}

void ModuleRender::PrintOutput(const MyVector<MyString>& lastActionResult)
{
	for (const auto& outputLine : lastActionResult)
	{
		IOStream::cout << IOStream::endl << outputLine << IOStream::endl;
	}
	IOStream::cout << IOStream::endl;
	IOStream::cout << "----------------------------------------------------------------------" << IOStream::endl;
}

