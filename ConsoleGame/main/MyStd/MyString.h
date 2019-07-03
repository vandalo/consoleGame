#pragma once

#include <MyStd\MyVector.h>
#include <MyStd\MyIOStream.h>

class MyString
{
public:
	MyString();
	~MyString();
	MyString(char* string);
	MyString(const MyString& string);

	char& operator[](int pos) const;
	char& operator+=(char* value);
	char& operator+=(char value);

	int size() const;
	void pop_back();

	friend IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& cout, const MyString& myString);

private:
	int m_size;
	MyVector<char> m_string;
};