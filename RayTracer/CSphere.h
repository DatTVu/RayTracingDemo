#ifndef SPHERE_H
#define SPHERE_H

#include "IHittable.h"
#include "CVector3.h"
#include "Ultilities.h"
template<typename T>
class CSphere : public IHittable<T>
{
	public:
		CSphere() {}
		CSphere(CVector3<T> center, T radius) : m_pointCenter(center) , m_radius(radius){}
		virtual bool IsHit(const CRay<T> &ray, T tmin, T tmax, SHitRecord<T> &hitRecord) const override;

	public:
		CVector3<T> m_pointCenter;
		T m_radius;
};
//template<typename T>
template<typename T>
bool CSphere<T>::IsHit(const CRay<T>& ray, T tmin, T tmax, SHitRecord<T>& hitRecord) const
{
	CVector3<T> originCenter_ = ray.GetOrigin() - m_pointCenter;
	T a = ray.GetDirection().length_squared();
	T half_b = dot(originCenter_, ray.GetDirection());
	T c = originCenter_.length_squared() - m_radius * m_radius;
	T discriminant_ = half_b * half_b - a * c;

	if (discriminant_ > 0)
	{
		T root = std::sqrt(discriminant_);
		T temp = (-half_b - root) / a;
		if (temp < tmax && temp > tmin)
		{
			hitRecord.m_t = temp;
			hitRecord.m_pointHit = ray.GetPointAt(hitRecord.t);
			hitRecord.m_vecNormal = (hitRecord.m_pointHit - m_pointCenter) / m_radius;
			return true;
		}
		temp = (-half_b + root) / a;
		if (temp < tmax && temp > tmin)
		{
			hitRecord.m_t = temp;
			hitRecord.m_pointHit = ray.GetPointAt(hitRecord.t);
			hitRecord.m_vecNormal = (hitRecord.m_pointHit - m_pointCenter) / m_radius;
			return true;
		}
	}
	return false;
}

#endif // !SPHERE_H
