#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"

using namespace std;

namespace sdds {

	Shape::~Shape() {}

	ostream& operator<<(ostream& os, const Shape& Ro) {
		Ro.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& Ro) {
		Ro.getSpecs(is);
		return is;
	}
}