
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds
{
	/// <summary>
	/// The file descriptor; will be set when a file is open with
	///   `openFile`, and reset when the file is closed with `closeFile`.
	/// </summary>
	std::FILE* g_fptr = nullptr;

	bool openFile(const char* filename)
	{
		bool allGood = false;
		if (g_fptr == nullptr)
		{
			g_fptr = std::fopen(filename, "r");
			allGood = g_fptr != nullptr;
		}
		return allGood;
	}

	int noOfRecordsInFile()
	{
		int noOfRecs = -1;
		if (g_fptr != nullptr)
		{
			// we have a file open; start counting from "0"
			noOfRecs = 0;

			// get current position in the file.
			auto currentPosition = std::ftell(g_fptr);

			// go to the begining of the file
			std::fseek(g_fptr, 0, SEEK_SET);

			// read from file a character at a time, and count '\n'
			char ch{};
			while (std::fscanf(g_fptr, "%c", &ch) == 1)
			{
				noOfRecs += (ch == '\n');
			}

			// done counting, reposition the cursor to the original location
			std::fseek(g_fptr, currentPosition, SEEK_SET);
		}

		// if no file was open, the counter will have "-1",
		//  otherwise will contain the number of lines
		return noOfRecs;
	}

	void closeFile()
	{
		if (g_fptr != nullptr)
		{
			std::fclose(g_fptr);
			g_fptr = nullptr;
		}
	}



	// TODO: implement the `read` functions here
	// Implementation of the read function for employee name
	 // Read the name from the file and store it in the 'name' parameter
	 // Return true if the read was successful, false otherwise


	bool read(char* name) {

		if (std::fscanf(g_fptr, "%[^\n]\n", name) == 1) {
			return true;
		}
		else {
			return false;
		}
	}



	bool read(int& empNo) {


		if (std::fscanf(g_fptr, "%d,", &empNo) == 1) {
			return true;
		}
		else {
			return false;
		}

	}

	bool read(double& salary) {

		if (std::fscanf(g_fptr, "%lf,", &salary) == 1) {
			return true;
		}
		else {
			return false;
		}
	}



}









