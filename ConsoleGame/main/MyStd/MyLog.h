#pragma once

#include "MyStd/MyIOStream.h"
#include "MyString.h"

#define LOG(logLevel, text) \
	MyLog::log(logLevel, text, __FILE__, __LINE__);

class MyLog
{
public:
	static void log(int logLevel, const char* text, const char* fileName, int fileLine);
	static void log(int logLevel, MyString text, const char* fileName, int fileLine);
};


namespace myStdLog
{
	static MyLog myLog;
}
