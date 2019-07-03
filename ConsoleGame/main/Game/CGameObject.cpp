#include "CGameObject.h"
#include "MyStd\MyString.h"

CGameObject::CGameObject()
{}

CGameObject::CGameObject(MyString name, MyString info) :
	m_name(name)
	, m_info(info)
{}

CGameObject::~CGameObject()
{
	IOStream::cout << "Removing gameObject: " << GetName() << IOStream::endl;
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

