#include "CGameObject.h"
#include "MyStd\MyString.h"
#include "MyStd\MyLog.h"

CGameObject::CGameObject()
{}

CGameObject::CGameObject(MyString name, MyString info) :
	m_name(name)
	, m_info(info)
{}

CGameObject::~CGameObject()
{
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

