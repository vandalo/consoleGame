#pragma once
#include "MyStd\MyString.h"
#include <conio.h>

class ModuleInput
{
public:
	ModuleInput();

	void CheckInput();
	MyVector<MyString>& GetArgs();
	bool Quit();

private:
	void ParseInput();

	bool m_exit;
	MyVector<MyString> m_args;
	MyString m_currentArg;
};
