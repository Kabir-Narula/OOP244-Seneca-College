

#define _CRT_SECURE_NO_WARNINGS
#ifndef EMPLOYEE_H
#define EMPLOYEE_H


// TODO: add here the header guard to prevent multiple inclusions
//         of the header in the same module

namespace sdds
{
	/// <summary>
	/// A structure that encapsulates some information about a
	///   single employee.
	/// 
	/// The name of the employee is a dynamically-allocated array
	///   of characters. It requires that the programmer manages
	///   the memory (allocation and deallocation).
	/// </summary>
	struct Employee
	{
		char* m_name;
		int m_empNo;
		double m_salary;
	};

	/// <summary>
	/// Sorts ascendingly the collection of `Employee` objects
	///   based on the employee numbers.
	/// </summary>
	void sort();

	/// <summary>
	/// Loads from a file a collection of employees. Each employee record
	///   in the file is stored on a single line in the format:
	///   `EMPLOYEE_NUMBER,SALARY,NAME_OF_THE_EMPLOYEE\n`
	/// 
	/// This function will open the file, and close it when finished reading.
	/// 
	/// If the program has a collection of employees already loaded, this
	///   function will append the records found in the file to the existing
	///   collection.
	/// 
	/// This function will allocate EXACTLY the amount of memory
	///   needed to store the collection of employees.
	/// 
	/// The collection of employees is a dynamically-allocated array
	///   of objects of type `Employee`.  This function resize the array
	///   to accomodate the new records from the file.
	/// </summary>
	/// <param name="filename">the file containing the collection of employees</param>
	/// <returns>true if the data was loaded successully, false otherwise.</returns>
	// TODO: add here the prototype of the `load` function that receives as a parameter
	//         the address of an unmodifiable C-string and returns a boolean value.
	bool load(const char* filename);

	/// <summary>
	/// Load from the file information about a single employee, and
	///   store it in the parameter.
	/// 
	/// The file must be already opened before this function is called.
	/// </summary>
	/// <param name="theEmployee">the object to populate with data extracted
	///   from the file.</param>
	/// <returns>true if data was successfuly extracted, false otherwise.</returns>
	// TODO: add here the prototype of the `load` function that receives as a parameter
	//         a **reference** to to an object of type `Employee`. The function should
	//         return a boolean value.

	bool load(Employee& emp);

	/// <summary>
	/// Print to screen the information about a single employee, in the format
	///   `EMPLOYEE_NUMBER: EMPLOYEE_NAME, EMPLOYEE_SALARY`
	/// 
	/// This function assumes that the parameter contains correct data.
	/// </summary>
	/// <param name="theEmployee">the employee to print to screen.</param>
	// TODO: add here the prototype of the `display` function that receives as a parameter
	//         an **unmodiafiable reference** to an object of type `Employee`. The function
	//         doesn't return anything.
	void display(const Employee& emp);

	/// <summary>
	/// Prints to screen the entire collection of employees.
	/// </summary>
	/// <param name="shouldSort">If `true`, the collection is sorted before
	///   printing; if `false` the collection is printed as it is.
	/// 
	/// This parameter is optional, with `true` as the default value.
	/// </param>
	// TODO: add here the prototype of the `display` function that receives a parameter
	//         of type `bool`.  The parameter is optional, with the default value `true`.
	//         The function doesn't return anything.
	void display(bool sortArray = true);

	/// <summary>
	/// Deallocate all the dynamic memory used by the collection of employees.
	/// </summary>
	// TODO: add here the prototype of the `deallocateMemory` function.  The function
	//         receives no parameters and doesn't return anything.
	void deallocateMemory();
}
#endif  // EMPLOYEE_H



