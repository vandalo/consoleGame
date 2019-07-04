#pragma once

#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"
#include "Game\ModuleInput.h"
#include "Game\CActionManager.h"
#include "Game\ModuleRender.h"

class ComponentPlayer;
class CGameObject;

class Application
{
public:
	Application();

	bool Init();
	bool update();

private:
	ComponentPlayer* m_player;
	CGameObject* m_currentRoom;
	MyVector<CGameObject*> m_gameObjects;
	CActionManager m_actionManager;
	ModuleInput m_moduleInput;
	ModuleRender m_moduleRender;
};