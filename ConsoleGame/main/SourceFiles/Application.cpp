#include "Application.h"

#include "MyStd\MyIOStream.h"
#include "Game\ComponentRoom.h"
#include "Game\ComponentPlayer.h"
#include "Game\CGameObject.h"
#include "Game\ComponentLook.h"
#include "Game\ComponentTakeable.h"
#include "Game\ComponentLink.h"

Application::Application()
	: m_player(nullptr)
	, m_currentRoom(nullptr)
{}

bool Application::Init()
{
	InitPlayer();
	InitRooms();
	AddRooms();

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

ComponentRoom* Application::GetRoom(MyString roomName)
{
	for (const auto& room : m_rooms)
	{
		if (room->GetGameObject().GetName() == roomName)
		{
			return room;
		}
	}
	return nullptr;
}

void Application::SetRoom(ComponentRoom* newCurrentRoom)
{
	m_currentRoom = newCurrentRoom;
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
	////////////////////// room1 ///////////////////////////////////
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

	////////////////////// room2 ///////////////////////////////////
	CGameObject* room2 = new CGameObject("Test2");
	ComponentRoom* componentRoom2 = new ComponentRoom(*room2);
	room2->AddComponent(componentRoom2);
	ComponentLook* componentLookRoom2 = new ComponentLook(*room2, "You are in a huge room!", true);
	room2->AddComponent(componentLookRoom2);

	//Bottle
	CGameObject* bottle = new CGameObject("bottle");
	ComponentLook* componentLookBottle = new ComponentLook(*bottle, "You see an empty bottle", false);
	bottle->AddComponent(componentLookBottle);
	ComponentTakeable* componentTookableBottle = new ComponentTakeable(*bottle);
	bottle->AddComponent(componentTookableBottle);
	room2->AddGameObject(bottle);
	//Bottle
	m_gameObjects.push_back(room2);

	////////DOORS//////
	//Door
	CGameObject* door = new CGameObject("door");
	ComponentLook* componentLookDoor = new ComponentLook(*door, "You see a door. It is in the east side of the room", false);
	door->AddComponent(componentLookDoor);
	ComponentLink* componentLinkDoor = new ComponentLink(*door, "Test2", "east");
	door->AddComponent(componentLinkDoor);
	room->AddGameObject(door);

	//Door
	CGameObject* door2 = new CGameObject("door2");
	ComponentLook* componentLookDoor2 = new ComponentLook(*door2, "You see a door. It is in the west side of the room", false);
	door->AddComponent(componentLookDoor2);
	ComponentLink* componentLinkDoor2 = new ComponentLink(*door2, "Test", "west");
	door->AddComponent(componentLinkDoor2);
	room2->AddGameObject(door2);
}

void Application::AddRooms()
{
	for (const auto& gameObject : m_gameObjects)
	{
		if (gameObject->HasComponent<ComponentRoom>())
		{
			m_rooms.push_back(&gameObject->GetComponent<ComponentRoom>());
		}
	}
}

/*
struct RoomDescriptor
{
string description;
bool isRecursive;
};

struct RoomDescriptor
{
string name;
LookDescriptor lookDescriptor;
};

struct IGameObjectLoader
{
virtual void Load() = 0;
};

struct HardcodedDataLoader :public IGameObjectLoader
{
void Load() override
{
RoomDescriptor{ "room1", true };
}
};

struct JsonDataLoader :public IGameObjectLoader
{
void Load() override
{

}
};*/
