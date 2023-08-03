#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {

	class Line : public LblShape {
		int m_length = 0;
	public:
		Line() : LblShape() {}
		Line(const char* label, const int length) :
			LblShape(label), m_length{ length } {}
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}

#endif