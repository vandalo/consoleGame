#include "Game\ComponentTakeable.h"

#include <typeinfo>


ComponentTakeable::ComponentTakeable(CGameObject& gameObject)
	: IComponent(gameObject)
{}

size_t ComponentTakeable::GetHash() const
{
	return typeid(ComponentTakeable).hash_code();
}