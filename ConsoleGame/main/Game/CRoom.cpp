#include "Game\CRoom.h"
#include "MyStd\MyString.h"

CRoom::CRoom(MyString name, MyString info) : CGameObject(name, info)
{}

CRoom::~CRoom()
{
	IOStream::cout << "Removing room " << GetName() << IOStream::endl;
}

