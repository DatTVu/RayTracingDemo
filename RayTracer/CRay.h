#ifndef RAY_H
#define RAY_H

#include "CVector3.h"

template<typename T>
class CRay
{
	public:
		CRay() {}
		CRay(const CVector3<T>& pointOrigin, const CVector3<T>& vDirection)
			: m_pointOrigin(pointOrigin), m_vecDirection(vDirection) {}

		CVector3<T> GetOrigin() const { return m_pointOrigin; }
		CVector3<T> GetDirection() const { return m_vecDirection; }
		CVector3<T> GetPointAt(T val) const
		{
			return m_pointOrigin + val * m_vecDirection;
		}
	public:
		CVector3<T> m_pointOrigin;
		CVector3<T> m_vecDirection;

};

#endif // !RAY_H

