#pragma once

#include "Game\IComponent.h"
#include "MyStd\MyVector.h"

class CGameObject;

class ComponentPlayer : public IComponent
{
public:
	ComponentPlayer(CGameObject& gameObject);
	size_t GetHash() const override;

	void AddToInventory(CGameObject* object);
	MyVector<CGameObject*>& GetInventory();

private:
	MyVector<CGameObject*> m_inventory;
};