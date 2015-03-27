#include "Exception.h"

using namespace std;

template<typedef T>
Exception::Exception(const std::string msg)
{
	msg_ = msg;
}

string Exception::what()
{
	return msg_;
}

Exception::~Excpetion() {}

string Exception::what()
{
	return msg_;
}

string Exception::getMessage()
{
	return msg_;
}

string Exception::operator<<(T& all)
{
	return msg_;
}
