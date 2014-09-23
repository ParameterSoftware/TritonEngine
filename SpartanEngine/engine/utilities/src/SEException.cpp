#include "SEException.h"

template<typedef T>
SEException::SEException(const std::string msg)
{
	msg_ = msg;
}

std::string SEException::what()
{
	return msg_;
}

/*SEException::~SEUExcpetion() {}

std::string SEException::what()
{
	return msg_;
}

std::string SEException::getMessage()
{
	return msg_;
}

std::string SEException::operator<<(T& all)
{
	return msg_;
}*/
