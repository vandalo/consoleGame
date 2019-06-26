#include "MyStd/MyIOStream.h"
#include <stdio.h>


IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, int outValue)
{
	printf("%d", outValue);
	return myCout;
}

IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, const char* text)
{
	printf(text);
	return myCout;
}

void operator<<(IOStream::MyIOSTream& myCout, IOStream::MyEndl&)
{
	printf("%c", '\n');
}
