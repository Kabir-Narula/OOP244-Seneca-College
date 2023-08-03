//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 05/30/2023(tuesday)
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.


#ifndef FILE_H
#define FILE_H

namespace sdds
{
	/// <summary>
	/// Opens the file specified as parameter for reading.
	///   If the file is already opened, this function does nothing
	///   and returns false.
	/// </summary>
	/// <param name="filename">The name of the file to open. Must not be null.</param>
	/// <returns>true if the files was opened, false otherwise.</returns>
	bool openFile(const char* filename);

	/// <summary>
	/// Close the file that was previously opened with `openFile`.
	///   If no file is opened, this function does nothing.
	/// </summary>
	void closeFile();

	/// <summary>
	/// Counts how many records (lines) are in the file (a record is a line in the file).
	/// 
	/// The file must be already open for reading with `openFile`.
	/// 
	/// When the function finishes, the reading cursor will be positioned
	///   in the same place as it was found (the function has no side effects).
	/// </summary>
	/// <returns>the number of records (lines) in the file, or -1
	///   if no file is open.</returns>
	int noOfRecordsInFile();

	/// <summary>
	/// Reads from the file an array of characters and stores them in
	///   the parameter.
	/// 
	/// The file must be already open for reading with `openFile` 
	/// </summary>
	/// <param name="str">a pre-allocated array of characters where
	///   to store what is read from the file.</param>
	/// <returns>true if something was read from the file, false otherwise</returns>
	// TODO: add here the prototype of the `read` function that receives as a parameter
	//         the address of a C-string and returns a boolean value.
	bool read(char* str);

	bool read(int& value);

}

#endif // FILE_H