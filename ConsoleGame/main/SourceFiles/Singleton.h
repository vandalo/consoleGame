#pragma once

template <class T>
class Singleton
{
public:
	Singleton();
	static T& GetInstance();
	static void CreateInstance();
	static void DestroyInstance();

private:
	static T* instance;
};

template <class T>
void Singleton<T>::DestroyInstance()
{
	delete instance;
}

template <class T>
void Singleton<T>::CreateInstance()
{
	instance = new T();
}

template<class T>
T* Singleton<T>::instance = nullptr;

template <class T>
T& Singleton<T>::GetInstance()
{
	return *instance;
}

template <class T>
Singleton<T>::Singleton(){}
