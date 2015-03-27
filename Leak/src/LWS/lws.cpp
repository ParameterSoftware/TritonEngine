#include <lws.h>

using namespace LWS::Util;

Vector Vec2::operator+(Vector v)
{
	Vec2 result;
	if(Vec2 vec = dynamic_cast<Vec2>(v))
	{
		result(x+vec.x, y+vec.y);
	}	
	return result;
}

Vector Vec2::operator-(Vector v)
{
	Vec2 result;
	if(Vec2 vec = dynamic_cast<Vec2>(v))
	{
		result(x-vec.x, y-vec.y);
	}	
	return result;
}

Vector Vec2::operator*(Vector v)
{
	Vec2 result;
	if(Vec2 vec = dynamic_cast<Vec2>(v))
	{
		result(x*vec.x, y*vec.y);
	}	
	return result;
}

Vector Vec2::operator/(Vector v)
{
	Vec2 result;
	if(Vec2 vec = dynamic_cast<Vec2>(v))
	{
		result(x/vec.x, y/vec.y);
	}	
	return result;
}
Vector Vec2::operator%(Vector v)
{
	Vec2 result;
	if(Vec2 vec = dynamic_cast<Vec2>(v))
	{
		result(x%vec.x, y%vec.y);
	}	
	return result;
}

template<typename T>Vec2<T> Vec2::distance(Vec2 v)
{
	Vec2 vec = this-v;
	return vec.absoulte();
}

template<typename T>Vec2<T> Vec2::absoulte()
{
	return Vec2(abs(x), abs(y));
}





