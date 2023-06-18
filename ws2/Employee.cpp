


#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"

using namespace std;

namespace sdds
{
	/// <summary>
	/// The address of a dynamically-allocated array of
	///   objects of type `Employee`.
	/// </summary>
	Employee* g_employees = nullptr;

	/// <summary>
	/// The number of `Employee` object in the array `g_employees`.
	/// </summary>
	int g_noOfEmployees = 0;

	void sort()
	{
		for (int i = g_noOfEmployees - 1; i > 0; --i)
			for (int j = 0; j < i; ++j)
				if (g_employees[j].m_empNo > g_employees[j + 1].m_empNo)
				{
					auto temp = g_employees[j];
					g_employees[j] = g_employees[j + 1];
					g_employees[j + 1] = temp;
				}
	}



	// TODO: add here the prototype of the `load` function that receives as a parameter
	//         the address of an unmodifiable C-string and returns a boolean value.
	bool load(const char* filename)
	{
		bool ok = true;
		if (openFile(filename))
		{
			/* TODO: Finish the implementation
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*
			* - use `noOfRecordsInFile` to find out how many records are in the file
			* - calculate the size of the new array
			*     (`g_noOfEmployees` + number of records in the file)
			* - create a new array of the new size
			* - iterate over old array (`g_employees`) and copy each Employee
			*     into the new array (allocate dynamic memory for the name of each employee)
			* - iterate over records in the file, and load one employee at a time
			*     (use `load(Employee&)` to load a single employee, pass to
			*     this function an element of the new array ready to receive data).
			* - deallocate the memory used by the old array (use `deallocateMemory`)
			* - update `g_employees` to point to the new array
			*     and `g_noOfEmployees` to store the size of the new array.
			* - close the file
			*
			* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
			*/
			int noOfRecords = noOfRecordsInFile();

			// Calculate the size of the new array
			int newSize = g_noOfEmployees + noOfRecords;

			// Create a new array of the new size
			Employee* newEmployees = new Employee[newSize];

			// Iterate over the old array and copy each Employee into the new array
			for (int i = 0; i < g_noOfEmployees; ++i)
			{
				newEmployees[i].m_empNo = g_employees[i].m_empNo;
				newEmployees[i].m_salary = g_employees[i].m_salary;

				newEmployees[i].m_name = new char[strlen(g_employees[i].m_name) + 1];
				strcpy(newEmployees[i].m_name, g_employees[i].m_name);

			}

			// Iterate over records in the file and load one employee at a time
			for (int i = g_noOfEmployees; i < newSize; ++i)
			{
				if (load(newEmployees[i]) == false)
				{
					ok = false;
					break;
				}
			}

			// Deallocate the memory used by the old array
			deallocateMemory();

			// Update `g_employees` to point to the new array
			g_employees = newEmployees;

			// Update `g_noOfEmployees` to store the size of the new array
			g_noOfEmployees = newSize;

			// Close the file
			closeFile();

		}
		else
		{
			cout << "Could not open data file: " << filename << endl;
			ok = false;
		}
		return ok;
	}



	// TODO: add here the prototype of the `load` function that receives as a parameter
	//         a **reference** to to an object of type `Employee`. The function should
	//         return a boolean value.
	bool load(Employee& emp)
	{
		bool ok = false;
		char name[128];
		/* TODO: Finish the implementation
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* - use the `read` functions to load from file the number,
		*     the salary, and the name of an employee (the order of
		*     reads is important). Read the name into the local variable `name`
		*     defined above.
		* - if all reads are successful, store the read data into the
		*     parameter (don't forget to allocate memory
		*     for the `m_name` attribute; allocate an extra character for `\0`).
		* - set the `ok` flag to true if all reads were successfull
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
		{
			//delete[] emp.m_name;
			emp.m_name = new char[strlen(name) + 1];
			strcpy(emp.m_name, name);
			ok = true;
		}

		return ok;
	}



	// TODO: add here the prototype of the `display` function that receives a parameter
	//         of type `bool`.  Do not put the default value for the parameter here.
	//         The function doesn't return anything.
	void display(bool sortArray)
	{

		/* TODO: Implement the `display` function here
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* - see the format of the output in the sample provided
		* - print the header text (see the expected output)
		* - if the parameter is `true`, call the function `sort`
		* - iterate over the array `g_employees`, and call the other overload of `display`
		*     for each object in the array.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/

		cout << "Employee Salary Report" << endl;
		cout << "no- Empno, Name, Salary" << endl;
		cout << "-----------------------" << endl;

		if (sortArray)
		{
			sort();
		}

		for (int i = 0; i < g_noOfEmployees; ++i)
		{
			cout << i + 1 << "- ";
			display(g_employees[i]);
		}

	}



	// TODO: Implement the `display` overload function here. This overload should
	//         print to screen the information about a single employee received as
	//         parameter.

	void display(const Employee& emp)
	{
		cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;

	}





	/* TODO: Implement the `deallocateMemory` function here
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* - iterate over the array `g_employees` and delete the name of each emplyee
	* - delete the array of employees
	* - set the `g_employees` to null
	* - set the number of employees to 0
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/

	void deallocateMemory()
	{
		if (g_employees != nullptr)
		{
			for (int i = 0; i < g_noOfEmployees; ++i)
			{
				delete[] g_employees[i].m_name;
			}

			delete[] g_employees;
			g_employees = nullptr;
			g_noOfEmployees = 0;
		}
	}

}















