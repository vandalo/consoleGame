#include "Game\ActionLook.h"

ActionLook::ActionLook()
{}

MyVector<MyString> ActionLook::DoAction()
{
	MyVector<MyString> output;
	output.push_back(MyString("You are looking!"));
	return output;
}

