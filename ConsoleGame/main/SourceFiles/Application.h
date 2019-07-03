#pragma once

#include <MyStd\MyVector.h>
#include <Game\CGameObject.h>
#include <MyStd\MyString.h>
#include "Game\ModuleInput.h"

class Application
{
public:
	Application();

	bool Init();
	bool update();

private:
	MyVector<CGameObject*> m_gameObjects;
	ModuleInput m_moduleInput;
};