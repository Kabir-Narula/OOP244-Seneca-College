#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include <iostream>
#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width = 0;
		int m_height = 0;
	public:
		Rectangle() : LblShape() {}
		Rectangle(const char* label, int width, int height);
		operator bool() const;
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif