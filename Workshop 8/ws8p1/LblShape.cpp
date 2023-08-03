#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "LblShape.h"


using namespace std;

namespace sdds {

	void LblShape::DMA(const char* label) {
		if (label && label[0] != '\0') {
			delete[] m_label;
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape(const char* label) {
		DMA(label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& is) {  

		string inputSpecs;
		if (m_label != nullptr)
		{
			delete[] m_label;
			m_label = nullptr;
		}
		getline(is, inputSpecs, ',');
		m_label = new char[inputSpecs.length() + 1];
		strcpy(m_label, inputSpecs.c_str());
	}
}