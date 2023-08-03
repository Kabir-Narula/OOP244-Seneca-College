//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 05/30/2023(tuesday)
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.


#ifndef REGION_H
#define REGION_H
#define POSTAL_CODE_SIZE 3

namespace sdds
{
	/// <summary>
	/// A custom type storing information about a single region.
	/// </summary>
	struct Region
	{
		char PostalCode[POSTAL_CODE_SIZE + 1];
		int population;
	};

	/// <summary>
	/// Loads from a file a collection of administrative regions; stores retrieved
	///   data into a dynamically-allocated array.  Each region will have a "Postal Code"
	///   and the number of people living there.
	/// </summary>
	/// <param name="filename">the file containing data.</param>
	/// <returns>true if the data was successfully loaded, false otherwise.</returns>
	bool load(const char* filename);


	bool load(Region& region);

	/// <summary>
	/// Prints to screen the collection of regions loaded from a file.
	/// </summary>
	/// <param name="areaName">the name of administrative area where those regions
	///    are located (i.e., the city, province, country, etc.)</param>
	/// <param name="sorted">optional parameter to specify if the regions should
	///   be sorted based on the population or not. The default value is `false`.</param>
	void display(const char* areaName, bool sorted = false);

	void display(Region& region);

	/// <summary>
	/// Deallocated all the dynamic memory used by the program.
	/// </summary>
	void cleanUp();

}

#endif // REGION_H
