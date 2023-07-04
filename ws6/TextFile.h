//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 04/07/2023(Tuesday)
//==============================================

#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>

namespace sdds {
    const char m_prefix[3] = "C_";

    class Text;

    class Line
    {
        // holds the address of the dynamically allocated Cstring
        // (to hold a line of the text file)
        char* m_value{ nullptr };

        operator const char* () const;

        Line() {}
        ~Line();

        // Dynamically allocates memory in m_value and copies
        Line& operator=(const char*);

        friend class TextFile;
        // copy and copy assignment prevention goes here
    };

    class TextFile
    {

        Line* m_textLines{ nullptr }; // This attribute should be initialized to nullptr
        char* m_filename{ nullptr };  // This attribute should be initialized to nullptr
        unsigned m_noOfLines; // to be set to the number of lines in the file
        unsigned m_pageSize;  // should be displayed on the screen before the display is paused

        void setEmpty();
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName) const;


    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile& _copy_Obj);
        TextFile& operator=(const TextFile& _copy_Obj);
        ~TextFile();

        unsigned lines() const;
        const char* name() const;
        std::ostream& view(std::ostream& ostr) const;
        std::istream& getFile(std::istream& istr);
        const char* operator[](unsigned index) const;
        operator bool() const;
    };

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);
}
#endif // !SDDS_TEXTFILE_H__
