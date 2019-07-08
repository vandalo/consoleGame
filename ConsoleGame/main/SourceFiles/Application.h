#pragma once

#include "SourceFiles\Singleton.h"

#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"
#include "Game\ModuleInput.h"
#include "Game\CActionManager.h"
#include "Game\ModuleRender.h"

class ComponentPlayer;
class CGameObject;
class ComponentRoom;

class Application : public Singleton<Application>
{
public:
	Application();

	bool Init();
	bool update();
	CGameObject& GetPlayer();
	ComponentPlayer& GetPlayerComponent();
	CGameObject& GetCurrentRoom();
	ComponentRoom* GetRoom(MyString roomName);
	void SetRoom(ComponentRoom* newCurrentRoom);

private:
	void InitPlayer();
	void InitRooms();
	void AddRooms();

	ComponentPlayer* m_player;
	ComponentRoom* m_currentRoom;
	MyVector<ComponentRoom*> m_rooms;
	MyVector<CGameObject*> m_gameObjects;
	CActionManager m_actionManager;
	ModuleInput m_moduleInput;
	ModuleRender m_moduleRender;
};