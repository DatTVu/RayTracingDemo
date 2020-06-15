#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

template <class T>
class CVector3
{
public: 
	CVector3() : m_data{ 0, 0, 0 } {};

	CVector3(T x, T y, T z) : m_data{ x, y, z} {};

	T x() const { return m_data[0]; }

	T y() const { return m_data[1]; }

	T z() const { return m_data[2]; }

	CVector3 operator-() const { return CVector3(-m_data[0], -m_data[1], -m_data[2]); }

	T operator[](int i) const 
	{
		_ASSERT(i <= 2);
		return m_data[i];
	}

	T& operator[](int i)
	{
		_ASSERT(i <= 2);
		return m_data[i];
	}

	CVector3& operator+= (const CVector3& vec)
	{
		m_data[0] += vec.m_data[0];
		m_data[1] += vec.m_data[1];
		m_data[2] += vec.m_data[2];
		return *this;
	}

	CVector3& operator*= (const T t)
	{
		m_data[0] *= t;
		m_data[1] *= t;
		m_data[2] *= t;
		return *this;
	}

	CVector3 operator/=(const T t)
	{
		return *this *= (T)1 / t;
	}

	T length() const
	{
		return std::sqrt(length_squared());
	}

	T length_squared() const
	{
		return m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2];
	}
public:
	T m_data[3];
};
#endif // !VEC3_H



