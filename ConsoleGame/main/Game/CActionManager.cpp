#include "CActionManager.h"
#include "MyStd\MyVector.h"
#include "MyStd\MyString.h"

namespace CActionManagerInternal
{
	const MyString LOOK("look");
	const MyString GO("go");
	const MyString NO_ACCTION("Oops! I do not know what do you mean!");
}

CActionManager::CActionManager()
{

}

const MyVector<MyString>& CActionManager::ParseAction(MyVector<MyString>& args)
{
	m_lastOutput.clear();
	if (args[0] == CActionManagerInternal::LOOK)
	{
		m_lastOutput = m_look.DoAction(args);
	}
	else if (args[0] == CActionManagerInternal::GO)
	{
		m_lastOutput = m_go.DoAction(args);
	}
	else
	{
		m_lastOutput.push_back(CActionManagerInternal::NO_ACCTION);
	}
	return m_lastOutput;
}

const MyVector<MyString>& CActionManager::GetLastActionResult() const
{
	return m_lastOutput;
}

