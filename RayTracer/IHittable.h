#ifndef HITTABLE_H
#define HITTABLE_H

#include "CRay.h"
#include "CVector3.h"
template<typename T>
struct SHitRecord
{
	CVector3<T> m_pointHit;
	CVector3<T> m_vecNormal;
	T m_t;
};

template<typename T>
class IHittable
{
	public:
		virtual bool IsHit(const CRay<T>& ray, T tmin, T tmax, SHitRecord<T>& hitRecord) const = 0;
};


#endif // !HITTABLE_H
