#include "Game\ActionGo.h"

ActionGo::ActionGo()
{}

MyVector<MyString> ActionGo::DoAction()
{
	MyVector<MyString> output;
	output.push_back(MyString("You are moving to...!"));
	return output;
}

