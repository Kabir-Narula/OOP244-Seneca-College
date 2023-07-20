#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include "Shape.h"

namespace sdds {

	class LblShape : public Shape {
		char* m_label = nullptr;
		void DMA(const char* label);
	protected:
		const char* label() const;
	public:
		LblShape() {};
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& Ro) = delete;
		LblShape& operator=(const LblShape& Ro) = delete;
		void getSpecs(std::istream& is);
	};
}

#endif