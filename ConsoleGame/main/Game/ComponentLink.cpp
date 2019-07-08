#include "Game\ComponentLink.h"

#include <typeinfo>
#include "Game\CGameObject.h"


ComponentLink::ComponentLink(CGameObject& gameObject, MyString destiny, MyString position)
	: IComponent(gameObject)
	, m_destiny(destiny)
	, m_position(position)
{}

size_t ComponentLink::GetHash() const
{
	return typeid(ComponentLink).hash_code();
}

MyString ComponentLink::GetPosition()
{
	return m_position;
}

MyString ComponentLink::GetDestiny()
{
	return m_destiny;
}

