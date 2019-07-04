#include "Game\ComponentRoom.h"

#include <typeinfo>


ComponentRoom::ComponentRoom(CGameObject& gameObject)
	: IComponent(gameObject)
{}

size_t ComponentRoom::GetHash() const
{
	return typeid(ComponentRoom).hash_code();
}