#pragma once

#include <MyStd\MyVector.h>

class Application
{
public:
	Application();

	bool update();

private:
	MyVector<int> m_sceneObjects;
};