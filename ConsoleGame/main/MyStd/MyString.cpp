#include <MyStd\MyString.h>
#include <stdio.h>

MyString::MyString()
{

}

MyString::MyString(char* string)
{
	for (int i = 0; i < string[i] != '\0'; ++i)
	{
		m_string.push_back(string[i]);
	}
}

MyString::MyString(const MyString& other)
{
	for (int i = 0; i < other.m_string[i] != '\0'; ++i)
	{
		m_string.push_back(other.m_string[i]);
	}
}

MyString::~MyString()
{
	IOStream::cout << "Removing string..." << *this << IOStream::endl;
}

char& MyString::operator[](int pos) const
{
	return m_string[pos];
}

char& MyString::operator+=(char* value)
{
	for (int i = 0; i < sizeof(value); ++i)
	{
		m_string.push_back(value[i]);
	}
	return m_string[m_string.size() - 1];
}

char& MyString::operator+=(char value)
{
	m_string.push_back(value);
	return m_string[m_string.size() - 1];
}

int MyString::size() const
{
	return m_string.size();
}

IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& cout, const MyString& myString)
{
	for(int i = 0; i < myString.size(); ++i)
	{
		printf("%c", myString.m_string[i]);
	}
	return cout;
}

