#include "Game\ComponentPlayer.h"

#include <typeinfo>


ComponentPlayer::ComponentPlayer(CGameObject& gameObject)
	: IComponent(gameObject)
{}

size_t ComponentPlayer::GetHash() const
{
	return typeid(ComponentPlayer).hash_code();
}