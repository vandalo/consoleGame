#pragma once

#include "Game\IComponent.h"

class ComponentRoom : public IComponent
{
public:
	ComponentRoom(CGameObject& gameObject);
	size_t GetHash() const override;
};