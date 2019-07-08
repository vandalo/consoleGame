#pragma once

#include "Game\IComponent.h"
#include "MyStd\MyVector.h"
#include "Game\CGameObject.h"


class ComponentPlayer : public IComponent
{
public:
	ComponentPlayer(CGameObject& gameObject);
	size_t GetHash() const override;

	void AddToInventory(CGameObject* object);
	CGameObject& GetInventory();

private:
	CGameObject m_inventory;
};