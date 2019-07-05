#include "SourceFiles\Application.h"

#include "ActionTake.h"
#include "CGameObject.h"
#include "Game\ComponentRoom.h"
#include "ComponentTakeable.h"
#include "ComponentPlayer.h"

namespace ActionTakeInternal
{
	const MyString DEFAULT("What should I take...?");
	const MyString OBJECT_NOT_FIND("I don not see any ");
	const MyString OBJECT_NOT_TACKABLE("I can not take the ");
	const MyString OBJECT_ADD_FIRST("You have added ");
	const MyString OBJECT_ADD_SECOND(" to your inventory!");
}

ActionTake::ActionTake(){}

MyVector<MyString> ActionTake::DoAction(MyVector<MyString>& args)
{
	MyVector<MyString> output;

	CGameObject& room = Application::GetInstance().GetCurrentRoom();
	if (args.size() == 1)
	{
		output.push_back(ActionTakeInternal::DEFAULT);
	}
	else
	{
		CGameObject* object = room.Find(args[1]);
		if (object)
		{
			if (object->HasComponent<ComponentTakeable>())
			{
				Take(object);
				output.push_back(MyString(ActionTakeInternal::OBJECT_ADD_FIRST) + args[1] + MyString(ActionTakeInternal::OBJECT_ADD_SECOND));
			}
			else
			{
				output.push_back(MyString(ActionTakeInternal::OBJECT_NOT_TACKABLE) + args[1]);
			}
		}
		else
		{
			output.push_back(MyString(ActionTakeInternal::OBJECT_NOT_FIND) + args[1]);
		}
	}
	return output;
}

void ActionTake::Take(CGameObject* object)
{
	ComponentPlayer& player = Application::GetInstance().GetPlayerComponent();
	player.AddToInventory(object);

	CGameObject& room = Application::GetInstance().GetCurrentRoom();
	room.RemoveGameObject(object);
}

