#pragma once

#include <MyStd\MyVector.h>
#include <Game\CGameObject.h>
#include <MyStd\MyString.h>

class Application
{
public:
	Application();

	bool Init();
	bool update();
	void ParseInput();
	void CheckInput();

private:
	MyVector<CGameObject*> m_gameObjects;
	MyVector<MyString> m_args;
	MyString m_currentArg;
};