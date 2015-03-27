#include <lus.h>
#include <sstream>
#include <cctype>
#include <fstream>
#include "lus_internal_dir.h"

using namespace LUS;
using namespace Local;
using namespace std;

////////////////////////
//	Error
////////////////////////
int Error::getErrorCode()
{
	stringstream strm;
	int result, nextInt, loc=1;
	char next;
	
	strm << msg;
	strm >> result;
	do
	{
		strm >> next;
		strm.seekg(strm.tellg()-1);
		strm >> nextInt;
		result+=nextInt*pow(10, loc);
		loc++;
	}
	while(isdigit(next));
	
	return result;
}

String Error::getError()
{
	int pos = msg.find("Error Exception: ")+1;
	if(pos >= msg.size()) return "?NULL?";
	return msg.substr(pos);
}

////////////////////////
//	Vector
////////////////////////
template<typename T> T Vector<T>::distance(Vector v)
{
	return abs(x-v.x);
}

template<typename T> Vector<T> Vector<T>::absV()
{
	return Vector<T>(abs(x));
}

template<typename T> Vec2<T>& Vec2<T>::operator=(const Vector<T>& vec, T y)
{
	return Vec2<T>(vec.x, y);
}

template<typename T> Vec2< T >::operator Vector<T>()
{
	return Vector<T>(x);
}

template<typename T, t> Vec2<T>Vec2<T>:: distance(Vec2<t> v)
{
	Vec2<T> vec = Vec2<T>(x-v.x, y-v.y);
	return vec.absV2();
}

template<typename T>Vec3<T>& Vec3<T>::operator=(const Vec2<T>& vec, T z)
{
	return Vec3<T>(vec.x, vec.y, z);
}

template<typename T>Vec3< T >::operator Vec2<T>()
{
	return Vec2<T>(x, y);
}

template<typename T, t>Vec3<T> Vec3<T>::distance(Vec3<t> v)
{
	Vec3<T> vec = Vec3<T>(x-v.x, y-v.y, z-v.z);
	return vec.absV3();
}

template<typename T>Vec3<T> Vec3<T>::absV3()
{
	return Vec3<T>(abs(x),abs(y),abs(z));
}

////////////////////////
//	Coloring
////////////////////////
RGB RGB::invert()
{
	return RGB(max-r,max-g,max-b);
}

RGBA& RGBA::operator=(const RGB& rgb, unsigned short a)
{
	return RGBA(rgb.r,rgb.g,rgb.b, a);
}

operator RGBA::RGB()
{
	return RGB(r,g,b);
}

////////////////////////
//	Localization
////////////////////////
LocalManager::LocalManager(String directory): dir(Directory(directory)) {}



////////////////////////
//	Angle
////////////////////////
Degree::Degree(const Radian& rad)
{
	this = rad.toDegree();
}

Degree& Degree::operator=(const Radian& rad);
{
	return rad.toDegree();
}

Degree::operator Radian()
{
	return toRadian();
}

Radian Degree::toRadian()
{
	return Radian(ang*(M_PI/180));
}

Radian::Radian(const Degree& deg)
{
	this = deg.toRadian();
}

Degree& Radian::operator=(const Radian& rad)
{
	return rad.toRadian();
}

Radian::operator Radian()
{
	return toDegree();
}

Degree Radian::toDegree()
{
	return Degree(ang*(180/M_PI));
}