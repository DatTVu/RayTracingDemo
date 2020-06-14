#pragma once
#include "CVector3.h"
template<typename T>
inline std::ostream& operator<<(std::ostream& out, const CVector3<T>& vec)
{
	return out << vec.m_data[0] << " " << vec.m_data[1] << " " << vec.m_data[2] << " " << vec.m_data[3] << "\n";
}

template<typename T>
inline CVector3<T> operator+(const CVector3<T>& u, const CVector3<T>& v)
{
	return CVector3<T>(u.m_data[0] + v.m_data[0], u.m_data[1] + v.m_data[1], u.m_data[2] + v.m_data[2]);
}

template<typename T>
inline CVector3<T> operator-(const CVector3<T>& u, const CVector3<T>& v)
{
	return CVector3<T>(u.m_data[0] - v.m_data[0], u.m_data[1] - v.m_data[1], u.m_data[2] - v.m_data[2]);
}

template<typename T>
inline CVector3<T> operator*(T val, const CVector3<T>& vec)
{
	return CVector3<T>(val* vec.m_data[0], val * vec.m_data[1], val * vec.m_data[2]);
}

template<typename T>
inline CVector3<T> operator*(const CVector3<T>& vec, T val)
{
	return val * vec;
}

template<typename T>
inline CVector3<T> operator/(CVector3<T>& vec, T val)
{
	return ((T)1 / val) * vec;
}

template<typename T>
inline T dot(const CVector3<T>& u, const CVector3<T>& v)
{
	return	u.m_data[0] * v.m_data[0]
		+ u.m_data[1] * v.m_data[1]
		+ u.m_data[2] * v.m_data[2];
}

template<typename T>
inline CVector3<T> cross(const CVector3<T>& u, const CVector3<T>& v)
{
	return CVector3<T>(u.m_data[1]* v.m_data[2] - u.m_data[2]* v.m_data[1],
					u.m_data[2] * v.m_data[0] - u.m_data[0] * v.m_data[2],
					u.m_data[0] * v.m_data[1] - u.m_data[1] * v.m_data[0]);
}

template<typename T>
inline CVector3<T> unitvec(CVector3<T> vec)
{
	return vec / vec.length();
}