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
	//CheckInput();
	for (auto& gameObject : m_gameObjects)
	{
		gameObject->Update();
	}
	return true;
}

/*void ParseInput(const MyString& line, MyVector<MyString>& arguments)
{
	for (unsigned int i = 0; i < line.size(); ++i) {
		MyString token = "";
		while (line[i] != ' ' && i < line.size()) {
			token += line[i];
			++i;
		}
		arguments.push_back(token);
	}
}*/

void Application::CheckInput()
{
	if (_kbhit() != 0)
	{
		char key = _getch();
		if (key == '\b') // backspace
		{
			/*if (sizeof(m_currentArg)/sizeof(char) > 0)
			{
				m_currentArg[]
			}*/
		}
		else if (key != '\r') // return
		{
			/*player_input += key;
			cout << key;*/
		}
		else {
			/*cout << "\n";
			ParseInput(player_input, args);*/
		}
	}
}

