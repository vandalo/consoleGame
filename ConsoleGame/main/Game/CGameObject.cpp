#include "CGameObject.h"
#include "MyStd\MyString.h"
#include "MyStd\MyLog.h"
#include "Game\IComponent.h"

CGameObject::CGameObject()
{}

CGameObject::CGameObject(MyString name, MyString info) :
	m_name(name)
	, m_info(info)
{}

CGameObject::~CGameObject()
{
	for (const auto& component : m_components)
	{
		delete component;
	}

	LOG(2, "Destroy gameObject...");
}

bool CGameObject::Update()
{
	return true;
}

MyString CGameObject::GetName()
{
	return m_name;
}

MyString CGameObject::GetInfo()
{
	return m_info;
}

void CGameObject::AddComponent(IComponent* component)
{
	m_components.push_back(component);
}

