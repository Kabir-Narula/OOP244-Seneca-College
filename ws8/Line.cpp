#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Line.h"

using namespace std;

namespace sdds {

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(2000, '\n');
	}

	void Line::draw(std::ostream& os) const {
		if (m_length && label()) {
			cout << label() << endl;
			os << setw(m_length) << setfill('=') << '=';
		}
	}
}