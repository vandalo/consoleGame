#include "Game\ComponentPlayer.h"

#include <typeinfo>


ComponentPlayer::ComponentPlayer(CGameObject& gameObject)
	: IComponent(gameObject)
{}

size_t ComponentPlayer::GetHash() const
{
	return typeid(ComponentPlayer).hash_code();
}

void ComponentPlayer::AddToInventory(CGameObject* object)
{
	m_inventory.push_back(object);
}

MyVector<CGameObject*>& ComponentPlayer::GetInventory()
{
	return m_inventory;
}
