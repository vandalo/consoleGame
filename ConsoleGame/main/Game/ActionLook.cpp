#include "SourceFiles\Application.h"

#include "Game\ActionLook.h"
#include "Game\CGameObject.h"
#include "Game\ComponentRoom.h"
#include "Game\ComponentLook.h"
#include "Game\ComponentPlayer.h"

namespace ActionLookInternal
{
	const MyString RECURSIVE("recursive");
	const MyString LOOK_ME_INPUT("me");
	const MyString LOOK_ME_OUTPUT("You see yourself! You are super pretty!");
	const MyString LOOK_DEFAULT("Eing?");
}

ActionLook::ActionLook()
{}

MyVector<MyString> ActionLook::DoAction(MyVector<MyString>& args)
{
	CGameObject* object = GetObjectToLook(args);

	MyVector<MyString> output;
	if (object && object->HasComponent<ComponentLook>())
	{
		ComponentLook& lookComponent = object->GetComponent<ComponentLook>();
		MyString lookText;
		if (args[0] == ActionLookInternal::RECURSIVE)
		{
			lookText = " -";
		}
		output.push_back(lookText + lookComponent.GetInfo());
		if (lookComponent.IsRecursive())
		{
			for (const auto& gameObject : lookComponent.GetGameObject().GetGameObjects())
			{
				MyVector<MyString> lookInput;
				lookInput.push_back(ActionLookInternal::RECURSIVE);
				lookInput.push_back(gameObject->GetName());
				output += DoAction(lookInput);
			}
		}
	}
	else
	{
		output.push_back(ActionLookInternal::LOOK_DEFAULT);
	}

	return output;
}

CGameObject* ActionLook::GetObjectToLook(MyVector<MyString>& args)
{
	CGameObject& room = Application::GetInstance().GetCurrentRoom();
	CGameObject* object = nullptr;

	if (args.size() > 1)
	{
		if (args[1] == ActionLookInternal::LOOK_ME_INPUT)
		{
			object = &Application::GetInstance().GetPlayer();
		}
		else
		{
			object = room.Find(args[1]);
		}
	}
	else
	{
		object = &room;
	}
	return object;
}

