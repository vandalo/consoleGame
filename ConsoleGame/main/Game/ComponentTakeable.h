#pragma once

#include "Game\IComponent.h"
#include "MyStd\MyString.h"

class ComponentTakeable : public IComponent
{
public:
	ComponentTakeable(CGameObject& gameObject);
	size_t GetHash() const override;
};
