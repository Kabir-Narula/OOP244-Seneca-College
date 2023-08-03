//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 27/07/2023(Monday)
//==============================================
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"

namespace sdds
{
    class HtmlText : public Text
    {
        char* m_title;

    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        HtmlText(const HtmlText& source);
        HtmlText& operator=(const HtmlText& source);
        ~HtmlText();
        virtual void write(std::ostream& os) const override;
    };
} // namespace sdds

#endif // !SDDS_HTMLTEXT_H__
