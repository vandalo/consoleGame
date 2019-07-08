#include "SourceFiles\Application.h"

#include "Game\ActionGo.h"
#include "Game\CGameObject.h"
#include "Game\ComponentLink.h"

ActionGo::ActionGo()
{}

MyVector<MyString> ActionGo::DoAction(MyVector<MyString>& args)
{
	MyVector<MyString> output;
	CGameObject& room = Application::GetInstance().GetCurrentRoom();
	ComponentLink* componentLink = nullptr;
	if (args.size() == 2)
	{
		for (CGameObject* gameObject : room.GetGameObjects())
		{
			if (gameObject->HasComponent<ComponentLink>())
			{
				componentLink = &gameObject->GetComponent<ComponentLink>();
				IOStream::cout << args[1];
				if (componentLink->GetPosition() != args[1])
				{
					componentLink = nullptr;
				}
			}
		}
	}

	if (componentLink)
	{
		MyString roomId = componentLink->GetDestiny();
		ComponentRoom* room = Application::GetInstance().GetRoom(roomId);
		Application::GetInstance().SetRoom(room);
	}
	else
	{
		output.push_back(MyString("I can not go there"));
	}

	return output;
}

