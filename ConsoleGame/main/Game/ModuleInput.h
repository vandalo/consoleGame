#pragma once
#include "MyStd\MyString.h"
#include <conio.h>

class ModuleInput
{
public:
	ModuleInput();

	bool CheckInput();
	MyVector<MyString>& GetArgs();
	MyString& GetCurrentInput();
	void ClearArgs();

private:
	void ParseInput();

	MyVector<MyString> m_args;
	MyString m_currentArg;

};
