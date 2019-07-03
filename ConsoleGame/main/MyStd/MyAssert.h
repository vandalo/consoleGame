#pragma once

#include "MyStd/MyIOStream.h"

#define ASSERT(condition, error_num, text) \
	MyAssert::assert(condition, error_num, text, __FILE__, __LINE__);

class MyAssert
{
public:
	static void assert(bool condition, int errorNum, const char* text, const char* fileName, int fileLine);
};


namespace myStdAssert
{
	static MyAssert myAssert;
}
