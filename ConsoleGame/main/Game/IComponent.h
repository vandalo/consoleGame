#pragma once

class CGameObject;

class IComponent
{
public:
	IComponent(CGameObject& gameObject);
	virtual size_t GetHash() const = 0;

	template<class T>
	bool IsComponent() const
	{
		return GetHash() == typeid(T).hash_code();
	}

	virtual void Update();
	CGameObject& GetGameObject();

private:
	CGameObject& m_gameObject;

};