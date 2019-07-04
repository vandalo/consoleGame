#pragma once

#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"
#include <typeinfo>

class IComponent;

class CGameObject
{
public:
	CGameObject();
	~CGameObject();
	CGameObject(MyString name, MyString info);
	virtual bool Update();
	MyString GetName();
	MyString GetInfo();
	void AddComponent(IComponent* component);

	template <class T>
	T& GetComponent();

	template <class T>
	const T& GetComponent() const;

	template <class T>
	bool HasComponent() const;

private:
	MyVector<CGameObject> m_gameObjects;
	MyVector<IComponent*> m_components;
	MyString m_name;
	MyString m_info;
};

template <class T>
T& CGameObject::GetComponent()
{
	for (auto& component : m_components)
	{
		if (component->IsComponent<T>())
		{
			return *dynamic_cast<T*>(component);
		}
	}

	ASSERT(false, 1, (MyString("The component ") + MyString(typeid(T).name()) + MyString(" does not exist")).c_str());
	return *dynamic_cast<T*>(m_components[0]);
}

template <class T>
const T& CGameObject::GetComponent() const
{
	for (const auto& component : m_components)
	{
		if (component->IsComponent<T>())
		{
			return *dynamic_cast<const T*>(component);
		}
	}

	ASSERT(false, 1, (MyString("The component ") + MyString(typeid(T).name()) + MyString(" does not exist")).c_str());
	return *dynamic_cast<const T*>(m_components[0]);
}

template <class T>
bool CGameObject::HasComponent() const
{
	for(const auto& component : m_components)
	{
		if (component->IsComponent<T>())
		{
			return true;
		}
	}
	return false;
}
