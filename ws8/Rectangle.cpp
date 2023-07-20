#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Rectangle.h"

using namespace std;

namespace sdds {

	Rectangle::Rectangle(const char* label, int width, int height)
		: LblShape(label) {
		if (height > 3 && (width > signed(strlen(LblShape::label()) + 2))) {
			m_height = height;
			m_width = width;
		}
	}

	Rectangle::operator bool() const {
		return m_height && m_width;
	}

	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		is.ignore(2000, '\n');
	}

	void Rectangle::draw(std::ostream& os) const {

		if (*this) {
			int counter = 0;
			os << '+' << setw(m_width - 2) << setfill('-') << '-' << '+' << endl;
			os << '|' << left << setw(m_width - 2) << setfill(' ')
				<< label() << '|' << endl;
			while (counter != m_height - 3) {
				os << '|' << setw(m_width - 2) << setfill(' ') << ' ' << '|' << endl;
				counter++;
			}
			os << '+' << setw(m_width - 2) << setfill('-') << '-' << '+';
		}
	}
}