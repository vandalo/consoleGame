#pragma once
#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"
#include "Game\IAction.h"

class ActionGo : public IAction
{
public:
	ActionGo();
	MyVector<MyString> DoAction();

};