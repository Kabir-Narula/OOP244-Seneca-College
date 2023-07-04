//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 04/07/2023(Tuesday)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
    // ==================== Line Class ====================
    Line::operator const char* () const
    {
        // Returns the address held in the m_value attribute.
        return (const char*)m_value;
    }

    Line::~Line()
    {
        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }
    }

    Line& Line::operator=(const char* lineValue)
    {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    // ==================== TextFile Class ====================
    // ============ private member function ============

    void TextFile::setEmpty()
    {
        // deletes the m_textLines dynamic array and sets is to nullptr
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        // deletes the m_filename dynamic Cstring and sets is to nullptr
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }

        // m_noOfLines attribute to zero
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy)
    {
        if (isCopy) {
            // dynamically allocates m_filename and copies fname argument with a prefix
            m_filename = new char[strLen(m_prefix) + strLen(fname) + 1];
            strCpy(m_filename, m_prefix);
            strCat(m_filename, fname);
        }
        else {
            // dynamically allocates m_filename and copies the fname
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines()
    {
        ifstream readfile(m_filename);
        char read_Char;

        if (readfile.is_open()) {
            while (readfile) {
                // read the file, character by character
                readfile.get(read_Char);

                // accumulates the number of newlines in the m_noOfLines attribute
                if (read_Char == '\n')
                    m_noOfLines++;
            }
            // increase by one, in case, the last line does not have a new line at the end
            m_noOfLines++;
        }
        else {
            // delete the m_filename and set it to nullptr
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText()
    {
        if (m_filename != nullptr) {
            // Make sure m_textLine is deleted before this to prevent memory leak
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            // dynamically allocate an array of Lines with the size kept in m_noOfLines
            m_textLines = new Line[m_noOfLines];

            // ifstream using the file name m_filename to read the lines of the text file
            ifstream readfile(m_filename);
            string _eachLine;
            unsigned count = 0;

            if (readfile.is_open()) {
                // In a loop reads each line into the string object
                while (getline(readfile, _eachLine)) {
                    m_textLines[count].m_value = new char[strLen(_eachLine.c_str()) + 1];
                    strCpy(m_textLines[count].m_value, _eachLine.c_str());
                    count++;
                }
            }

            // make sure to update the value of m_noOfline to the actual number of lines read
            m_noOfLines = count;
        }
    }

    void TextFile::saveAs(const char* fileName) const
    {
        // Saves the content of the TextFile under a new name
        ofstream out(fileName);

        // write them in the opened file adding a new line to the end of each line
        for (unsigned i = 0; i < m_noOfLines; i++)
            out << m_textLines[i] << endl;
    }

    // ============ public member function ============
    TextFile::TextFile(unsigned pageSize)
    {
        // Creates an empty TextFile
        setEmpty();
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned pageSize)
    {

        setEmpty();
        // Initializes the m_pageSize attribute using the pageSize argument
        m_pageSize = pageSize;

        if (filename != nullptr && filename[0] != '\0') {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);

            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& src)
    {
        setEmpty();
        this->m_pageSize = src.m_pageSize;

        // Saves the content of the incoming TextFile under the file name of the current TextFile
        if (this != &src)
        {
            if (src.m_textLines && src.m_noOfLines > 0) {
                // Sets the file-name to the name of the incoming TextFile object
                setFilename(src.m_filename, true);

                this->m_noOfLines = src.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                unsigned i = 0;
                while (i < m_noOfLines) {
                    m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
                    i++;
                }

                saveAs(m_filename);
            }
        }
    }

    TextFile& TextFile::operator=(const TextFile& src)
    {
        if (this != &src) {
            // deallocate the dynamic array of Text and sets the pointer to null
            if (m_textLines != nullptr) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }

            // Saves the content of the incoming TextFile under the current filename
            if (src.m_textLines && src.m_noOfLines > 0) {
                this->m_noOfLines = src.m_noOfLines;
                m_textLines = new Line[m_noOfLines];

                unsigned i = 0;
                while (i < m_noOfLines) {
                    m_textLines[i].m_value = new char[strLen(src.m_textLines[i].m_value) + 1];
                    strCpy(m_textLines[i].m_value, src.m_textLines[i].m_value);
                    i++;
                }

                saveAs(m_filename);
            }
        }

        return *this;
    }

    TextFile::~TextFile()
    {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    unsigned TextFile::lines() const
    {
        return m_noOfLines;
    }

    const char* TextFile::name() const
    {
        return m_filename;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const
    {
        if (m_filename != nullptr && m_filename[0] != '\0') {
            ostr << m_filename << endl;

            ostr.fill('=');
            ostr.width(strLen(m_filename));
            ostr << '=' << endl;

            unsigned i = 0;

            // loops through the lines and print them one by line
            while (i < m_noOfLines && i < m_pageSize) {
                ostr << m_textLines[i] << endl;
                i++;
            }

            if (i < m_noOfLines) {
                do {
                    ostr << "Hit ENTER to continue...";
                    char x;
                    cin.get(x);

                    for (unsigned j = 0; j < m_pageSize && i < m_noOfLines; j++) {
                        ostr << m_textLines[i] << endl;
                        i++;
                    }
                } while (i < m_noOfLines);
            }
        }

        return ostr;
    }

    std::istream& TextFile::getFile(std::istream& istr)
    {
        string _input;
        // Receives a filename from istr to set the file name of the TextFile
        istr >> _input;

        m_filename = new char[strLen(_input.c_str()) + 1];
        strCpy(m_filename, _input.c_str());
        istr.ignore(32767, '\n');

        // sets the number of lines and loads the Text
        setNoOfLines();
        loadText();

        return istr;
    }

    const char* TextFile::operator[](unsigned index) const
    {
        if (m_filename != nullptr && m_filename[0] != '\0') {
            if (index >= m_noOfLines)
                index -= m_noOfLines;
        }

        return m_textLines[index].m_value;
    }

    TextFile::operator bool() const
    {
        bool result = false;

        if (m_textLines != nullptr)
            result = true;

        return result;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text)
    {
        text.view(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, TextFile& text)
    {
        text.getFile(istr);
        return istr;
    }
}