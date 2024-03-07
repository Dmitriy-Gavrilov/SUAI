#pragma once
#include <exception>

using namespace std;

class ArrayException : public exception
{
private:
	int code_error;
public:
	ArrayException(const char* msg, int code) : exception(msg)
	{
		code_error = code;
	}

	int GetCode() { return code_error; }
};

