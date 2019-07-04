#pragma once
#include "MyStd\MyString.h"
#include "CGameObject.h"

class ModuleRender
{
public:
	ModuleRender();
	void Render(const CGameObject& player, const MyString& input, const MyVector<MyString>& lastResultOutput);

private:
	void CleanScreen();
	void PrintScreen();
	void PrintConsole(const MyString& input);
	void PrintOutput(const MyVector<MyString>& lastResultOutput);
};