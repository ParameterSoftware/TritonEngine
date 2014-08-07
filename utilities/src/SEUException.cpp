#include "SEUExcpetion.h"

SEUException::SEUException(const std::string& msg)
{
	msg_ = msg;
}

SEUException::~SEUException() {}

string SEUException::what()
{
	return msg_;
}

string SEUException::getMessage()
{
	return msg_;
}

string SEUEXception::operator <<(T& all)
{
	return msg_;
}
