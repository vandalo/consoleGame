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
	T* push_back(T newObject);
	void pop_back();

	T* begin();
	T* end();
	T& operator[](int pos);

private:
	void resize();

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
	m_realSize(1)
	, m_size(0)
{
	m_vector = new T[m_realSize];
}

template <class T>
MyVector<T>::~MyVector()
{
	delete[] m_vector;
}

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
T* MyVector<T>::push_back(T newObject)
{
	if (m_size >= m_realSize)
	{
		resize();
	}
	m_vector[m_size] = newObject;
	++m_size;
	return &m_vector[m_size];
}

template <class T>
void MyVector<T>::pop_back()
{
	if (m_size > 0)
	{
		--m_size;
	}
	else
	{
		ASSERT(1, "MyVector was empty");
	}
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

template <class T>
void MyVector<T>::resize()
{
	T* new_vector = new T[m_realSize * 2];
	for (int i = 0; i < m_realSize; ++i)
	{
		new_vector[i] = m_vector[i];
	}
	delete[] m_vector;
	m_realSize *= 2;
	m_vector = new_vector;
}
