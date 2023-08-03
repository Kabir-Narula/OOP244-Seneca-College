//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 15/06/2023(Thursday)
//==============================================
#ifndef SDDS_ACCOUNT_H
#define SDDS_ACCOUNT_H

namespace sdds
{
	class Account
	{
		const int WIDTH_NAME = 10;
		const int WIDTH_NUM = 8;
		const int WIDTH_BAL = 10;


		/// <summary>
/// The holder's name of the account.
///   **Valid value**: any string with at least one character.
/// </summary>
// TODO: declare the `m_holderName` attribute as a statically-allocated
//         C-string of 100 characters.
		char m_holderName[100];

		/// <summary>
		/// The account number.
		///   **Valid number**: any integer with exactly 6 digits.
		/// </summary>
		// TODO: declare the `m_number` attribute as an integer.
		int m_number;

		/// <summary>
		/// The balance of the account.
		/// </summary>
		// TODO: declare the `m_balance` attribute as a floating point number in
		//         double precision.
		double m_balance;

	public:
		/// <summary>
/// Creates a new empty account.
/// </summary>
/* TODO: define the default constructor
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Account()
*
* - sets the attributes to default values:
*   - all numbers to 0
*   - the name to the empty string
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
		Account();

		/// <summary>
		/// Creates a new account and stores the values of the parameters into the
		///   attributes of the current instance.
		/// </summary>
		/// <param name="name">The holder's name of the account.</param>
		/// <param name="number">The account number.</param>
		/// <param name="balance">The balance of the account.  This parameter is
		///   optional with a default value 0.</param>
		/* TODO: define the custom constructor
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* Account(name, number, balance)
		*
		* - set object to the default state using the default constructor
		* - if the name is valid
		*   - store name in the attribute
		* - if the name is valid AND the number is valid
		*   - store name and number into the attributes
		*
		* **HINT**: you can use delegated constructors to set the object to default
		*             state with the default constructor.  See the
		*             *"Delegating Constructor"* section in the documentation:
		*             https://en.cppreference.com/w/cpp/language/constructor
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account(const char* name, int number, double balance = 0);

		/// <summary>
		/// Print to screen the information stored in the current instance.
		///  (this function is fully provided)
		/// </summary>
		void display() const;

		/// <summary>
		/// Return the holder's name.
		/// </summary>
		/* TODO: define conversion-to-string query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator const char*()
		*
		* - this conversion operator cannot be used in automatic conversions.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		operator const char* () const;

		/// <summary>
		/// Return the account number,
		/// </summary>
		/* TODO: define conversion-to-int query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator int()
		*
		* - this conversion operator cannot be used in automatic conversions.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		operator int() const;

		/// <summary>
		/// Return the account balance.
		/// </summary>
		/* TODO: define conversion-to-double query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator double()
		*
		* - this conversion operator cannot be used in automatic conversions.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		operator double() const;

		/// <summary>
		/// Checks if the account is valid or not. Returns `true` if
		///   the account is valid, `false` otherwise.
		/// </summary>
		/* TODO: define conversion-to-bool query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator bool()
		*
		* - if the holder's name is not empty string and the account number is more than 0
		*     return true, false otherwise.
		* - this conversion operator cannot be used in automatic conversions.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		operator bool() const;


		/// <summary>
		/// Checks if the account is valid or not. Returns `true` if
		///   the account is NOT valid, `false` otherwise.
		/// </summary>
		/* TODO: define the negation operator query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator!()
		*
		* - return the opposite of conversion-to-bool operator.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		bool operator!() const;


		/// <summary>
		/// Sets the holder's name to the parameter, if the parameter is not null and not empty.
		/// 
		///   If the parameter is not valid, this function does nothing.
		/// </summary>
		/// <param name="name">The new holder name, as a C-string.</param>
		/// <returns>A reference to the current instance.</returns>
		/* TODO: define the assignment operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator=(name)
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account& operator=(const char* name);

		/// <summary>
		/// Sets the account number to the value of the parameter only if there is
		///   no account number already set and there is a name on the account.
		/// 
		///   If the parameter is not a valid account number, this function does nothing.
		/// </summary>
		/// <param name="number">The account new number as an integer.</param>
		/// <returns>A reference to the current instance.</returns>
		/* TODO: define the assignment operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator=(number)
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account& operator=(int number);

		/// <summary>
		/// Sets the balance to the value of the parameter only if the account is valid.
		/// </summary>
		/// <param name="balance">The new balance as a floating point number in double
		///   precision.</param>
		/// <returns>A reference to the current instance.</returns>
		/* TODO: define the assignment operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator=(balance)
		*
		* - use conversion-to-bool operator to check if the account is valid.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account& operator=(double balance);


		/// <summary>
		/// Add the balances of the two accounts together and return the result as a
		///   floating point number in double precision.
		/// 
		/// If any of the accounts are not valid this function returns 0.
		/// 
		/// This overload enables expressions "Account + Account".
		/// </summary>
		/// <param name="acc">A constant reference to an `Account` object.</param>
		/// <returns>The sum of balances of the two accounts or 0 if any account is
		/// invalid, as floating point number in double precision.</returns>
		/* TODO: define the addition operator as a query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator+(acc)
		*
		* - use conversion-to-bool operator to check if the accounts are valid.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		double operator+(const Account& acc) const;


		/// <summary>
		/// Add the balance of the current account to the value of the parameter and
		///   return the result as a floating point number in double precision.
		/// 
		/// If the current instance is not a valid account this function returns 0.
		/// 
		/// This overload enables expressions "Account + double".
		/// </summary>
		/// <param name="amount">A floating point number in double precision.</param>
		/// <returns>The sum of amount and balance from the current account as
		///   a floating point number in double precision, or 0 if the account is
		///   not valid.</returns>
		/* TODO: define the addition operator as a query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator+(amount)
		*
		* - use conversion-to-bool operator to check if the account is valid.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		double operator+(double amount) const;


		/// <summary>
		/// Adds 1000 to the balance if the account is valid.
		/// </summary>
		/// <returns>A reference to the current object.</returns>
		/* TODO: define the prefix increment operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator++()
		*
		* - use conversion-to-bool operator to check if the account is valid.
		* - if current account is valid, add 1000 to the balance
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account& operator++();


		/// <summary>
		/// Adds 1000 to the balance if the account is valid.
		/// </summary>
		/// <returns>A constant object of `Account` type.</returns>
		/* TODO: define the postfix increment operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator++(int)
		*
		* - create a local `Account` object. Copy into it the content from the current
		*     instance: localObject = *this;
		* - use the prefix increment operator to add 1000 to the balance of
		*     current instance: ++(*this)
		* - return the local object.
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account operator++(int);


		/// <summary>
		/// Add the parameter to the balance of the current account if the current
		///   instance is a valid account.
		/// </summary>
		/// <param name="amount">The amount to add as a floating point number
		///   in double precision.</param>
		/// <returns>A reference to the current object.</returns>
		/* TODO: define the addition-assignment operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator+=(amount)
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account& operator+=(double amount);


		/// <summary>
		/// Checks if the account number is the same as the parameter.
		/// 
		/// If the current account is valid, return `true` if the account has the same
		///   number as the parameter, `false` otherwise.
		/// </summary>
		/// <param name="number">The integer to check against the account number.</param>
		/// <returns>A Boolean value.</returns>
		/* TODO: define the comparison operator as a query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator==(number)
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		bool operator==(int number) const;

		// return true if it's the same name
		/// <summary>
		/// Checks if the account holder is the same as the parameter.
		/// 
		/// If the current account is valid, return `true` if the account has the same
		///   holder as the parameter, `false` otherwise.
		/// </summary>
		/// <param name="name">A C-string to check against the account holder.</param>
		/// <returns>A Boolean value.</returns>
		/* TODO: define the comparison operator as a query
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator==(name)
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		bool operator==(const char* name)const;

		/// <summary>
		/// If both instances are valid, transfer balance from parameter into
		///   current instance.
		/// </summary>
		/// <param name="acc">A reference to the account to take balance from.</param>
		/// <returns>A reference to the current instance.</returns>
		/* TODO: define the insertion operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator<<(acc)
		*
		* - if both instances are valid (use the conversion-to-bool operator)
		*   - take the balance from the parameter and add it to the current instance
		*   - set the balance of the parameter to 0
		* - return current instance
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account& operator<<(Account& acc);

		// transfer balance from current instance into parameter
		/// <summary>
		/// If both instances are valid, transfer balance from the current instance into
		///   the parameter.
		/// </summary>
		/// <param name="acc">A reference to the account to put current balance into.</param>
		/// <returns>A reference to the current instance.</returns>
		/* TODO: define the extraction operator as a mutator
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*
		* operator>>(acc)
		*
		* - use the insertion operator to transfer the balance: acc << (*this)
		* - return current instance
		*
		* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
		*/
		Account& operator>>(Account& acc);
	};


	/// <summary>
/// Add the first parameter and the balance of the second parameter and
///   return the result as a floating point number in double precision.
/// 
/// If the `acc` is not a valid account, this function returns 0.
/// 
/// This overload enables expressions "double + Account".
/// </summary>
/// <param name="amount">A floating point number in double precision.</param>
/// <param name="acc">A constant reference to an `Account` object.</param>
/// <returns>The sum of amount and balance from the current account as a
///   floating point number in double precision.</returns>
/* TODO: define the assignment operator as a free helper
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* operator+(amount, acc)
*
* - use conversion-to-bool operator to check if the account is valid.
* - use conversion-to-double operator to retrieve the balance from the account.
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/
	double operator+(double amount, const Account& acc);


	/// <summary>
	/// Add the balance of the second parameter to the value of the first parameter and
	///   return the result as a floating point number in double precision.
	/// 
	/// If the `Account` instance is not a valid account this function returns 0.
	/// 
	/// This overload enables expressions "double += Account".
	/// </summary>
	/// <param name="amount">A reference to a floating point number in double precision.</param>
	/// <param name="acc">A constant reference to an `Account` object.</param>
	/// <returns>The sum of amount and balance from the `Account` as a reference
	///   to a floating point number in double precision.</returns>
	/* TODO: define the addition-assignment operator as a free helper
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator+=(amount, acc)
	*
	* - use conversion-to-double operator to retrieve the balance from the account.
	* - return the first parameter
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	double& operator+=(double& amount, const Account& acc);

}

#endif