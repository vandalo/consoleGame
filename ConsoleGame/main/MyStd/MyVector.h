#pragma once

#include <MyStd/MyAssert.h>

template <class T>
class MyVector
{
public:
	MyVector();
	~MyVector();

	MyVector(int size, T defaultValue);
	int size();
	T* push(T newObject);

	T* begin();
	T* end();
	T& operator[](int pos);

private:
	int m_realSize;
	int m_size;
	T* m_vector;
};

template <class T>
T& MyVector<T>::operator[](int pos)
{
	if (pos <= m_size)
	{
		return m_vector[pos];
	}
	ASSERT(1, "MyVector out of memory");
	return m_vector[pos];
}

template <class T>
MyVector<T>::MyVector() : 
	m_realSize(64)
	, m_size(0)
{
	m_vector = new T [m_realSize];
}

template <class T>
MyVector<T>::~MyVector()
{}

template <class T>
MyVector<T>::MyVector(int size, T defaultValue) :
	m_realSize(size)
	, m_size(size)
{
	m_vector = new T[m_realSize] { defaultValue };
}

template <class T>
int MyVector<T>::size()
{
	return m_size;
}

template <class T>
T* MyVector<T>::push(T newObject)
{
	m_vector[m_size] = newObject;
	++m_size;
	return &m_vector[m_size];
}

template <class T>
T* MyVector<T>::begin()
{
	return &m_vector[0];
}

template <class T>
T* MyVector<T>::end()
{
	return &m_vector[m_size];
}
