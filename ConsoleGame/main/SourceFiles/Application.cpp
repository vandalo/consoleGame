#include "Application.h"

#include "MyStd\MyIOStream.h"
#include "Game\ComponentRoom.h"
#include "Game\ComponentPlayer.h"
#include "Game\CGameObject.h"

Application::Application()
	: m_player(nullptr)
{}

bool Application::Init()
{
	//Create player
	CGameObject* player = new CGameObject("Me", "You see yourself, you are very handsome");
	ComponentPlayer* componentPlayer = new ComponentPlayer(*player);
	player->AddComponent(componentPlayer);
	m_gameObjects.push_back(player);
	m_player = componentPlayer;

	CGameObject* room = new CGameObject("Test", "This is a test");
	room->AddComponent(new ComponentRoom(*room));
	m_gameObjects.push_back(room);
	m_currentRoom = room;

	m_moduleRender.Render(m_player->GetGameObject(), m_moduleInput.GetCurrentInput(), m_actionManager.GetLastActionResult());
	return true;
}

bool Application::update()
{
	bool hasInput = m_moduleInput.CheckInput();

	//When we press intro, we set the arguments so then we will do the game loop
	if (m_moduleInput.GetArgs().size() > 0)
	{
		m_actionManager.ParseAction(m_moduleInput.GetArgs());

		for (auto& gameObject : m_gameObjects)
		{
			gameObject->Update();
		}
		m_moduleInput.ClearArgs();
	}

	if (hasInput)
	{
		m_moduleRender.Render(m_player->GetGameObject(), m_moduleInput.GetCurrentInput(), m_actionManager.GetLastActionResult());
	}

	return true;
}

