#include "Application.h"

#include "MyStd/MyIOStream.h"
#include "Game/CRoom.h"


Application::Application(){}

bool Application::Init()
{
	CRoom* room = new CRoom("Test", "This is a test");
	m_gameObjects.push_back(room);

	return true;
}

bool Application::update()
{
	m_moduleInput.CheckInput();
	if (m_moduleInput.Quit())
	{
		return false;
	}

	for (auto& gameObject : m_gameObjects)
	{
		if (m_moduleInput.GetArgs().size() > 0)
		{

		}
		gameObject->Update();
	}
	
	return true;
}

