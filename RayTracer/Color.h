#ifndef COLOR_H
#define COLOR_H

#include "CVector3.h"

#include <iostream>

template<typename T>
void write_color(std::ostream& out, CVector3<T> pixelColor)
{
	out << static_cast<int> (255.999 * pixelColor.x()) << ' '
		<< static_cast<int> (255.999 * pixelColor.y()) << ' '
		<< static_cast<int> (255.999 * pixelColor.z()) << '\n';
}		

#endif
