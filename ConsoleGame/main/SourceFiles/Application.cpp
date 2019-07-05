#include "Application.h"

#include "MyStd\MyIOStream.h"
#include "Game\ComponentRoom.h"
#include "Game\ComponentPlayer.h"
#include "Game\CGameObject.h"
#include "Game\ComponentLook.h"
#include "Game\ComponentTakeable.h"

Application::Application()
	: m_player(nullptr)
	, m_currentRoom(nullptr)
{}

bool Application::Init()
{
	InitPlayer();
	InitRooms();

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

CGameObject& Application::GetPlayer()
{
	return m_player->GetGameObject();
}

ComponentPlayer& Application::GetPlayerComponent()
{
	return *m_player;
}

CGameObject& Application::GetCurrentRoom()
{
	return m_currentRoom->GetGameObject();
}

void Application::InitPlayer()
{
	//Create player
	CGameObject* player = new CGameObject("me");

	ComponentPlayer* componentPlayer = new ComponentPlayer(*player);
	player->AddComponent(componentPlayer);

	ComponentLook* componentLookPlayer = new ComponentLook(*player, "You see yourself, you are very handsome", false);
	player->AddComponent(componentLookPlayer);

	m_gameObjects.push_back(player);
	m_player = componentPlayer;
}

void Application::InitRooms()
{
	//Create Rooms
	CGameObject* room = new CGameObject("Test");

	ComponentRoom* componentRoom = new ComponentRoom(*room);
	room->AddComponent(componentRoom);

	ComponentLook* componentLookRoom = new ComponentLook(*room, "You are in a test room", true);
	room->AddComponent(componentLookRoom);

	m_gameObjects.push_back(room);
	m_currentRoom = componentRoom;

	//Lamp
	CGameObject* lamp = new CGameObject("lamp");

	ComponentLook* componentLookObject = new ComponentLook(*lamp, "You see an oil Lamp", false);
	lamp->AddComponent(componentLookObject);

	ComponentTakeable* componentTookableObject = new ComponentTakeable(*lamp);
	lamp->AddComponent(componentTookableObject);
	
	room->AddGameObject(lamp);

	//Stone
	CGameObject* stone = new CGameObject("stone");

	ComponentLook* componentLookStone = new ComponentLook(*stone, "You see an Stone, it looks super heavy!", false);
	stone->AddComponent(componentLookStone);

	room->AddGameObject(stone);
}

