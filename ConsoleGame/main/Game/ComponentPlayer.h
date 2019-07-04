#pragma once

#include "Game\IComponent.h"

class ComponentPlayer : public IComponent
{
public:
	ComponentPlayer(CGameObject& gameObject);
	size_t GetHash() const override;
};