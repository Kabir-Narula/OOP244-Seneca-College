//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 05/23/2023(tuesday)
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#ifndef FILE_MODULE_H
#define FILE_MODULE_H


// TODO: add here the header guard to prevent multiple inclusions
//         of the header in the same module

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


	// TODO: Declare the prototypes for the read functions

	/// <summary>
	/// Reads from the file an array of characters and stores them in
	///   the parameter.  This function stops reading when `\n` is found
	///   (`\n` is extracted from file and discarded.
	/// 
	/// The file must be already open for reading with `openFile` 
	/// </summary>
	/// <param name="str">a pre-allocated array of characters where
	///   to store what is read from the file.</param>
	/// <returns>true if something was read from the file, false otherwise</returns>
	// TODO: add here the prototype of the `read` function that receives as a parameter
	//         the address of a C-string and returns a boolean value.
	bool read(char* name);

	/// <summary>
	/// Reads from the file a single integer and stores it in the parameter.
	/// 
	/// This function assumes that the integer if followed by a delimiter (`,`).
	///   The delimiter is extracted and discarded.
	/// </summary>
	/// <param name="val">the function will put here the value read.</param>
	/// <returns>true if a number is read, false otherwise.</returns>
	// TODO: add here the prototype of the `read` function that receives as a parameter
	//         a reference to an object of type `int` and returns a boolean value.
	bool read(int& empNo);

	/// <summary>
	/// Reads from the file a single floating point point number in double
	///   precision and stores it in the parameter.
	/// 
	/// This function assumes that the number if followed by a delimiter (`,`).
	///   The delimiter is extracted and discarded.
	/// </summary>
	/// <param name="val">the function will put here the value read.</param>
	/// <returns>true if a number is read, false otherwise.</returns>
	// TODO: add here the prototype of the `read` function that receives as a parameter
	//         a reference to an object of type `double` and returns a boolean value.
	bool read(double& salary);
}

#endif // !SDDS_FILE_H
