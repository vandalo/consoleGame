#pragma once
#include "IAction.h"
#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"

class CGameObject;

class ActionTake : public IAction
{
public:
	ActionTake();
	MyVector<MyString> DoAction(MyVector<MyString>& args);

private:
	void Take(CGameObject* object);
};
