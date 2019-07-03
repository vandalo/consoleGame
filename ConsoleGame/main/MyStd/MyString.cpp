#include <MyStd\MyString.h>
#include <stdio.h>

MyString::MyString()
	: m_size(0)
{
	m_string.push_back('\0');
}

MyString::MyString(char* string)
	: m_size(0)
{
	m_string.push_back('\0');
	for (int i = 0; i < string[i] != '\0'; ++i)
	{
		push_back(string[i]);
	}
}

MyString::MyString(const MyString& other)
	: m_size(0)
{
	m_string.push_back('\0');
	for (int i = 0; i < other.size(); ++i)
	{
		push_back(other.m_string[i]);
	}
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
	push_back(value);
	return m_string[m_string.size() - 1];
}

char& MyString::operator=(char* value)
{
	clear();
	m_string.push_back('\0');
	for (int i = 0; value[i] != '\0'; ++i)
	{
		push_back(value[i]);
	}
	return m_string[m_string.size() - 1];
}


char& MyString::operator=(char value)
{
	clear();
	m_string.push_back('\0');
	push_back(value);
	return m_string[m_string.size() - 1];
}

char& MyString::operator=(MyString value)
{
	clear();
	m_string.push_back('\0');
	for (int i = 0; value[i] != '\0'; ++i)
	{
		push_back(value[i]);
	}
	return m_string[m_string.size() - 1];
}

void MyString::push_back(char value)
{
	if (value != '\0')
	{
		m_string[m_size] = value;
		++m_size;
	}
	m_string.push_back('\0');
}

MyString::~MyString()
{
	IOStream::cout << "Removing string..." << *this << IOStream::endl;
}

char& MyString::operator[](int pos) const
{
	return m_string[pos];
}

bool MyString::operator==(MyString value)
{
	bool eq = true;
	if (size() == value.size())
	{
		for (int i = 0; i < value.size(); ++i)
		{
			eq &= m_string[i] == value.m_string[i];
		}
	}
	else
	{
		eq = false;
	}
	return eq;
}

int MyString::size() const
{
	return m_size;
}

void MyString::pop_back()
{
	m_string.pop_back();
}

void MyString::clear()
{
	m_size = 0;
	m_string.clear();
}

IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& cout, const MyString& myString)
{
	for(int i = 0; i < myString.size(); ++i)
	{
		printf("%c", myString.m_string[i]);
	}
	return cout;
}
