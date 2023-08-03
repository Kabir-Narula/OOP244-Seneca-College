//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 05/30/2023(tuesday)
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Region.h"
#include "File.h"

using namespace std;

namespace sdds
{

	Region* regionRec = nullptr;

	int numOfRegion = 0;

	void sort()
	{
		for (int i = numOfRegion - 1; i > 0; --i)
			for (int j = 0; j < i; ++j)
				if (regionRec[j].population > regionRec[j + 1].population)
				{
					auto temp = regionRec[j];
					regionRec[j] = regionRec[j + 1];
					regionRec[j + 1] = temp;
				}
	}

	/// <summary>
	/// Loads from a file a collection of administrative regions; stores retrieved
	///   data into a dynamically-allocated array.  Each region will have a "Postal Code"
	///   and the number of people living there.
	bool load(const char* filename)
	{
		bool ok = true;
		if (openFile(filename))
		{
			int numOfRecord = noOfRecordsInFile();
			int newArrSize = numOfRegion + numOfRecord;

			Region* newArrReg = new Region[newArrSize];

			int i;
			if (regionRec != nullptr)
			{
				for (i = 0; i < numOfRegion; i++)
				{
					strcpy(newArrReg[i].PostalCode, regionRec[i].PostalCode);
					newArrReg[i].population = regionRec[i].population;
				}
			}

			for (int i = numOfRegion; i < newArrSize; i++)
			{
				if (!load(newArrReg[i]))
				{
					ok = false;
					break;
				}
			}

			cleanUp();

			regionRec = newArrReg;
			numOfRegion = newArrSize;

			closeFile();

		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
			ok = false;
		}
		return ok;
	}

	bool load(Region& region)
	{
		bool ok = false;
		if (read(region.PostalCode) && read(region.population))
		{
			ok = true;
		}
		return ok;
	}

	void display(const char* areaName, bool sorted)
	{
		int i, totalPopulation = 0;
		cout << "#. Postal Code -> Population" << endl;
		cout << "------------------------------" << endl;
		if (sorted)
		{
			sort();
		}
		for (i = 0; i < numOfRegion; i++)
		{
			cout << i + 1 << ". ";
			display(regionRec[i]);
			totalPopulation += regionRec[i].population;
		}
		cout << "------------------------------" << endl;
		cout << "Population of " << areaName << ": " << totalPopulation << endl;
	}

	void display(Region& region)
	{
		cout << region.PostalCode << " -> " << region.population << endl;
	}

	void cleanUp()
	{
		delete[] regionRec;
		regionRec = nullptr;
		numOfRegion = 0;
	}

}