#pragma once

#include "Game\IComponent.h"
#include "MyStd\MyString.h"

class ComponentLook : public IComponent
{
public:
	ComponentLook(CGameObject& gameObject, MyString info, bool recursive);
	size_t GetHash() const override;
	MyString GetInfo();
	bool IsRecursive();

private:
	MyString m_info;
	bool m_lookRecursive;
};
