#pragma once

#include <MyStd/MyAssert.h>

template <class T>
class MyVector
{
public:
	MyVector();
	~MyVector();
	MyVector(const MyVector& other);
	void operator=(const MyVector& other);

	MyVector(int size, T defaultValue);
	int size() const;
	T* push_back(T newObject);
	void pop_back();
	void clear();

	T* begin();
	T* end();
	T& operator[](int pos) const;

private:
	void resize();

	void copyDataFromOther(const MyVector& other);

	int m_realSize;
	int m_size;
	T* m_vector = nullptr;
};

template <class T>
void MyVector<T>::clear()
{
	m_size = 0;
}

template <class T>
void MyVector<T>::copyDataFromOther(const MyVector& other)
{
	ASSERT(m_vector == nullptr, 1, "Only call this function in constructors")
	m_vector = new T[other.m_realSize];
	for (int i = 0; i < other.m_realSize; ++i)
	{
		m_vector[i] = other.m_vector[i];
	}
}

template <class T>
void MyVector<T>::operator=(const MyVector& other)
{
	m_realSize = other.m_realSize;
	m_size = other.m_size;
	copyDataFromOther(other);
}

template <class T>
T& MyVector<T>::operator[](int pos) const
{
	if (pos <= m_size)
	{
		return m_vector[pos];
	}
	ASSERT(false, 1, "MyVector out of memory");
	return m_vector[pos];
}

template <class T>
MyVector<T>::MyVector() : 
	m_realSize(0)
	, m_size(0)
{
	m_vector = new T[m_realSize];
}


template <class T>
MyVector<T>::MyVector(const MyVector& other) 
	: m_realSize(other.m_realSize)
	, m_size(other.m_size)
{
	copyDataFromOther(other);
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
int MyVector<T>::size() const
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
		ASSERT(false, 1, "MyVector was empty");
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
	if (m_realSize == 0)
	{
		m_realSize = 1;
	}
	T* new_vector = new T[m_realSize * 2];
	for (int i = 0; i < m_realSize; ++i)
	{
		new_vector[i] = m_vector[i];
	}
	delete[] m_vector;
	m_realSize *= 2;
	m_vector = new_vector;
}
