//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 27/07/2023(Monday)
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Text.h"
#include "cstring.h"
#include "HtmlText.h"

namespace sdds
{
    HtmlText::HtmlText(const char* filename, const char* title) : Text(filename)
    {
        m_title = nullptr;
        if (title != nullptr)
        {
            m_title = new char[strLen(title) + 1];
            strCpy(m_title, title);
        }
    }

    HtmlText::HtmlText(const HtmlText& source) : HtmlText(source.m_title)
    {
        *this = source;
    }

    HtmlText& HtmlText::operator=(const HtmlText& source)
    {
        if (this != &source)
        {
            if (source.m_title)
            {
                Text::operator=(source);
                delete[] m_title;
                m_title = nullptr;
                m_title = new char[strLen(source.m_title) + 1];
                strCpy(m_title, source.m_title);
            }
        }
        return *this;
    }

    HtmlText::~HtmlText()
    {
        delete[] m_title;
        m_title = nullptr;
    }

    void HtmlText::write(std::ostream& os) const
    {
        bool those = false;
        int these = 0;
        os << "<html><head><title>";

        if (m_title != nullptr)
            os << m_title;
        else
            os << "No Title";

        os << "</title></head>\n<body>\n";

        if (m_title != nullptr)
            os << "<h1>" << m_title << "</h1>\n";

        while ((*this)[these] != '\0')
        {
            char c = (*this)[these];
            switch (c)
            {
            case ' ':
                if (those)
                    os << "&nbsp;";
                else
                {
                    those = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                those = false;
                break;
            case '>':
                os << "&gt;";
                those = false;
                break;
            case '\n':
                os << "<br />\n";
                those = false;
                break;
            default:
                those = false;
                os << c;
            }
            these++;
        }

        os << "</body>\n</html>";
    }
} // namespace sdds
