#pragma once

#include "MyStd\MyVector.h"
#include "MyStd\MyIOStream.h"

class MyString
{
public:
	MyString();
	~MyString();
	MyString(char* string);
	MyString(const char* string);
	MyString(const MyString& string);

	char& operator[](int pos) const;
	char& operator+=(char* value);
	char& operator+=(char value);
	char& operator=(char* value);
	char& operator=(char value);
	char& operator=(MyString value);
	bool operator==(MyString value);
	MyString& operator+(MyString value);

	int size() const;
	void push_back(char value);
	void pop_back();

	friend IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& cout, const MyString& myString);
	const char* c_str() const;

private:
	void clear();

	int m_size;
	MyVector<char> m_string;
};