#include "SourceFiles/Defines.h"
#include "MyStd/MyLog.h"
#include <stdlib.h>

void MyLog::log( int logLevel, const char* text, const char* fileName, int fileLine)
{
	if (logLevel <= LOG_LEVEL)
	{
		IOStream::cout << "LOG:" << text << IOStream::endl;
		if (LOG_VERBOSE)
		{
			IOStream::cout << "File: " << fileName << " - Line:" << fileLine << IOStream::endl;
		}
	}
}

void MyLog::log(int logLevel, MyString text, const char* fileName, int fileLine)
{
	if (logLevel <= LOG_LEVEL)
	{
		IOStream::cout << "LOG:" << text << IOStream::endl;
		if (LOG_VERBOSE)
		{
			IOStream::cout << "File: " << fileName << " - Line:" << fileLine << IOStream::endl;
		}
	}
}
