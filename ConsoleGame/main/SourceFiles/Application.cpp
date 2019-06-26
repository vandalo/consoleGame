#include "Application.h"

#include <iostream>
#include <MyStd/MyIOStream.h>

Application::Application()
{
	m_sceneObjects.push(1);
	m_sceneObjects.push(3);
	m_sceneObjects.push(2);

	m_sceneObjects[2] = 10;

	for(const auto& elem : m_sceneObjects)
	{ 
		std::cout << elem;
	}
	std::cout << std::endl;
	std::cout << m_sceneObjects.size();

	IOStream::cout << "test" << "test2  " << 3 << IOStream::endl;
	m_sceneObjects[4] = 10;
}

bool Application::update()
{
	return true;
}

