#pragma once

#include <MyStd\MyVector.h>
#include "MyStd\MyString.h"

class CGameObject
{
public:
	CGameObject();
	~CGameObject();
	CGameObject(MyString name, MyString info);
	virtual bool Update();
	MyString GetName();
	MyString GetInfo();

private:
	MyVector<CGameObject> m_gameObjects;
	MyString m_name;
	MyString m_info;
};