#include "MyStd/MyAssert.h"
#include <stdlib.h>

void MyAssert::assert(int errorNum, const char* text, const char* fileName, int fileLine)
{
	IOStream::cout << IOStream::endl;
	IOStream::cout << "Error(" << errorNum << ") - " << text << IOStream::endl;
	IOStream::cout << "File: " << fileName << " - Line:" << fileLine << IOStream::endl;
	exit(0);
}
