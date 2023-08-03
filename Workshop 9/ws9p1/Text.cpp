//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 27/07/2023(Monday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    //==============PRIVATE====================//
    int Text::getFileLength() const
    {
        int length = 0;
        ifstream fin(m_filename);
        while (fin)
        {
            fin.get();
            length += !!fin;
        }
        return length;
    }

    //===============PROTECTED==================//
    const char& Text::operator[](int index) const
    {
        
        return m_content[index];
    }

    //================PUBLIC====================//

    Text::Text(const char* filename)
    {
        if (filename)
        {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            m_content = nullptr;
            read();
        }
        else
        {
            m_content = nullptr;
            m_filename = nullptr;
        }
    }

    Text::Text(const Text& source) : Text(source.m_filename)
    {
        *this = source;
    }

    Text& Text::operator=(const Text& source)
    {
        if (this != &source)
        {
            delete[] m_filename;
            m_filename = nullptr;

            delete[] m_content;
            m_content = nullptr;

            if (source.m_filename)
            {
                m_filename = new char[strLen(source.m_filename) + 1];
                strCpy(m_filename, source.m_filename);
            }

            if (source.m_content)
            {
                m_content = new char[strLen(source.m_content) + 1];
                strCpy(m_content, source.m_content);
            }
        }

        return *this;
    }

    Text::~Text()
    {
        delete[] m_filename;
        m_filename = nullptr;

        delete[] m_content;
        m_content = nullptr;
    }

    void Text::read()
    {
       
        int length = getFileLength();

        if (length == 0)
        {
            m_content = nullptr;
            return;
        }

        m_content = new char[length + 1];

        ifstream f(m_filename);

        if (f.is_open())
        {
            char c;
            int i = 0;

            while (f.get(c))
            {
                m_content[i] = c;
                i++;
            }
            m_content[i] = '\0';
            f.close();
        }
        else
        {
            delete[] m_content;
            m_content = nullptr;
        }
    }

    void Text::write(std::ostream& os) const
    {
       
        if (m_content != nullptr)
        {
            os << m_content;
        }
    }

    //===============HELPERFUNC===============//
    ostream& operator<<(ostream& os, const Text& text)
    {
        text.write(os);
        return os;
    }
}
