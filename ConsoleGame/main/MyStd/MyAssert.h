#pragma once

#include "MyStd/MyIOStream.h"

#define ASSERT(error_num, text) \
	MyAssert::assert(1, text, __FILE__, __LINE__);

class MyAssert
{
public:
	static void assert(int errorNum, const char* text, const char* fileName, int fileLine);
};


namespace myStdAssert
{
	static MyAssert myAssert;
}
