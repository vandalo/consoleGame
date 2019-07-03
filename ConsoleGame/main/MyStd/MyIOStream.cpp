#include "MyStd/MyIOStream.h"
#include <stdio.h>


IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, int outValue)
{
	printf("%d", outValue);
	return myCout;
}

IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, char outValue)
{
	switch (outValue)
	{
	case '\b':
		printf("\b");
		break;
	case '\0':
		break;
	default:
		printf("%c", outValue);
		break;
	}

	return myCout;
}

IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, const char* text)
{
	printf(text);
	return myCout;
}

IOStream::MyIOSTream& operator<<(IOStream::MyIOSTream& myCout, IOStream::MyEndl&)
{
	printf("%c", '\n');
	return myCout;
}
