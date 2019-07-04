#pragma once
#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"
#include "Game\IAction.h"

class ActionLook : public IAction
{
public:
	ActionLook();
	MyVector<MyString> DoAction();

};