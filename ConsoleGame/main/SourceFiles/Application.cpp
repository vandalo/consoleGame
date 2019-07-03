#include "Application.h"

#include <MyStd/MyIOStream.h>
#include <Game/CRoom.h>
#include <conio.h>

Application::Application() :
	m_currentArg("")
{}

bool Application::Init()
{
	CRoom* room = new CRoom("Test", "This is a test");
	m_gameObjects.push_back(room);

	return true;
}

bool Application::update()
{
	CheckInput();
	for (auto& gameObject : m_gameObjects)
	{
		gameObject->Update();
	}
	return true;
}

void Application::ParseInput()
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

void Application::CheckInput()
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

	/*if (m_args.size() > 0 && m_args[0] == "quit")
		//QuitGameFlag
	{
	}*/
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

