#include "CGameObject.h"
#include "MyStd\MyString.h"
#include "MyStd\MyLog.h"
#include "Game\IComponent.h"

CGameObject::CGameObject()
{}

CGameObject::CGameObject(MyString name) :
	m_name(name)
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

void CGameObject::AddComponent(IComponent* component)
{
	m_components.push_back(component);
}

void CGameObject::AddGameObject(CGameObject* object)
{
	m_gameObjects.push_back(object);
}

CGameObject* CGameObject::Find(MyString name)
{
	for (const auto& object : m_gameObjects)
	{
		if (object->GetName() == name)
		{
			return object;
		}
	}
	return nullptr;
}

MyVector<CGameObject*> CGameObject::GetGameObjects()
{
	return m_gameObjects;
}

