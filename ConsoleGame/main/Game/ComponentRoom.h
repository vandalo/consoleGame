#pragma once

#include "Game\IComponent.h"
#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"

class ComponentRoom : public IComponent
{
public:
	ComponentRoom(CGameObject& gameObject);
	size_t GetHash() const override;
};