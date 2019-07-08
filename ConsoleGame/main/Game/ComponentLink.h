#pragma once

#include "Game\IComponent.h"
#include "MyStd\MyString.h"

class ComponentLink : public IComponent
{
public:
	ComponentLink(CGameObject& gameObject, MyString destiny, MyString position);
	size_t GetHash() const override;

	MyString GetPosition();
	MyString GetDestiny();

private:
	MyString m_destiny;
	MyString m_position;
};