#pragma once

namespace IOStream
{
	class MyEndl
	{};

	class MyIOSTream
	{
	};

	static MyIOSTream cout;
	static MyEndl endl;
};

IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, int outValue);
IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, const char* text);
void operator<<(IOStream::MyIOSTream& myCout, IOStream::MyEndl&);