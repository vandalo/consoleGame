#include "Game\IComponent.h"

IComponent::IComponent(CGameObject& gameObject)
	: m_gameObject(gameObject)
{}

void IComponent::Update()
{

}

CGameObject& IComponent::GetGameObject()
{
	return m_gameObject;
}

