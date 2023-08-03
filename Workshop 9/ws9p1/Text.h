//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 27/07/2023(Monday)
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds
{
    class Text
    {
    private:
        char* m_filename;
        char* m_content;
        int getFileLength() const; // Code provided in Text.cpp

    protected:
        const char& operator[](int index) const;

    public:
        Text(const char* filename = nullptr);

        //! The Rule of three
        
        Text(const Text& source);
        Text& operator=(const Text& source);
        ~Text();
        void read();
        virtual void write(std::ostream& os) const;
    };
    // prototype of insertion overload into ostream goes here
    std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif
