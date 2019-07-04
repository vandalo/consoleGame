#include "ModuleInput.h"

namespace ModuleInputInternal
{
	const MyString QUIT("quit");
}

ModuleInput::ModuleInput(){}

void ModuleInput::ParseInput()
{
	for (int i = 0; i < m_currentArg.size(); ++i) {
		MyString token = "";
		while (m_currentArg[i] != ' ' && i < m_currentArg.size()) {
			token += m_currentArg[i];
			++i;
		}
		m_args.push_back(token);
	}
}

void ModuleInput::ClearArgs()
{
	m_args.clear();
	m_currentArg = "";
	//IOStream::cout << IOStream::endl << "> ";
}

bool ModuleInput::CheckInput()
{
	bool isKbHit = false;
	if (_kbhit() != 0)
	{
		char key = _getch();
		isKbHit = (key != '\0');
		if (key == '\b') // backspace
		{
			if (m_currentArg.size() > 0)
			{
				m_currentArg.pop_back();
			}
		}
		else if (key != '\r') // return
		{
			m_currentArg += key;
		}
		else {
			ParseInput();
		}
	}
	return isKbHit;
}

MyVector<MyString>& ModuleInput::GetArgs()
{
	return m_args;
}

MyString& ModuleInput::GetCurrentInput()
{
	return m_currentArg;
}
