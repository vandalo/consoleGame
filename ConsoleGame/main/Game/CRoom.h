#pragma once

#include <Game\CGameObject.h>
#include "MyStd\MyString.h"

class CRoom : public CGameObject
{
public:
	CRoom(MyString name, MyString info);
	~CRoom();
};