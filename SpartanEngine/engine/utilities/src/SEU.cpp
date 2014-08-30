#include "SEU.h"

int seuConvertToInt(char obj)
{
	int result = obj - '0';
	return result;
}

char seuConvertToChar(int obj)
{
	int iresult = obj + '0';
	char result = iresult;
	return result;
}


