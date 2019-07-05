#include "Game\ComponentLook.h"

#include <typeinfo>


ComponentLook::ComponentLook(CGameObject& gameObject, MyString info, bool recursive)
	: IComponent(gameObject)
	, m_info(info)
	, m_lookRecursive(recursive)
{}

size_t ComponentLook::GetHash() const
{
	return typeid(ComponentLook).hash_code();
}

MyString ComponentLook::GetInfo()
{
	return m_info;
}

bool ComponentLook::IsRecursive()
{
	return m_lookRecursive;
}
