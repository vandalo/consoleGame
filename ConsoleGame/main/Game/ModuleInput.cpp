#include "ModuleInput.h"

namespace ModuleInputInternal
{
	const MyString QUIT("quit");
}

ModuleInput::ModuleInput()
	:m_exit(false)
{}

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

void ModuleInput::CheckInput()
{
	if (_kbhit() != 0)
	{
		char key = _getch();
		if (key == '\b') // backspace
		{
			if (m_currentArg.size() > 0)
			{
				m_currentArg.pop_back();
				IOStream::cout << '\b';
				IOStream::cout << " ";
				IOStream::cout << '\b';
			}
		}
		else if (key != '\r') // return
		{
			m_currentArg += key;
			IOStream::cout << key;
		}
		else {
			IOStream::cout << "\n";
			ParseInput();
		}
	}

	if (m_args.size() > 0 && m_args[0] == ModuleInputInternal::QUIT)
	{
		m_exit = true;
	}
	if (m_args.size() > 0)
	{
		//Read Command
		/*if (ReadComand(args) == false)
		{
		cout << "NoCommand\n";
		}
		*/
		m_args.clear();
		m_currentArg = "";
		IOStream::cout << IOStream::endl << "> ";
	}
}

MyVector<MyString>& ModuleInput::GetArgs()
{
	return m_args;
}

bool ModuleInput::Quit()
{
	return m_exit;
}
