#pragma once

#include "MyStd\MyString.h"
#include "MyStd\MyVector.h"
#include "Game\ActionLook.h"
#include "Game\ActionGo.h"
#include "Game\ActionTake.h"

class CActionManager
{
public:
	CActionManager();
	const MyVector<MyString>& ParseAction(MyVector<MyString>& args);
	const MyVector<MyString>& GetLastActionResult() const;

private:

	MyVector<MyString> m_lastOutput;

	ActionLook m_look;
	ActionGo m_go;
	ActionTake m_take;
};