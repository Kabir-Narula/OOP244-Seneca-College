//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 15/06/2023(Thursday)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Account.h"

using namespace std;
namespace sdds
{
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
	Account::Account()
	{
		m_holderName[0] = '\0';
		m_number = 0;
		m_balance = 0.0;
	}


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
	Account::Account(const char* name, int number, double balance) : Account()
	{
		if (name != nullptr and name[0] != '\0')
		{
			strcpy(m_holderName, name);

			if (number >= 100000 and number < 1000000)
			{
				m_number = number;
				m_balance = balance;
			}
		}
	}


	/// <summary>
	/// Print to screen the information stored in the current instance.
	///  (this function is fully provided)
	/// </summary>
	void Account::display()const
	{
		auto oldFill = std::cout.fill();
		auto oldPrec = std::cout.precision();
		if (m_holderName[0] != '\0')
		{
			// there is account
			std::cout << "| ";
			std::cout.width(WIDTH_NAME);
			std::cout.fill(' ');
			std::cout.setf(std::ios::left);
			std::cout << this->m_holderName << " | ";
			std::cout.unsetf(std::ios::left);
			std::cout.width(WIDTH_NUM);
			if (*this)
				std::cout.fill('0');
			else
				std::cout.fill(' ');
			std::cout.setf(std::ios::right);
			std::cout << this->m_number << " | ";
			std::cout.setf(std::ios::fixed);
			std::cout.width(WIDTH_BAL);
			std::cout.precision(2);
			std::cout.fill(' ');
			std::cout << this->m_balance << " |\n";
			std::cout.unsetf(std::ios::fixed);
			std::cout.unsetf(std::ios::right);
		}
		else
		{
			std::cout.fill('x');
			std::cout << "| ";
			std::cout.width(WIDTH_NAME);
			std::cout << "" << " | ";
			std::cout.width(WIDTH_NUM);
			std::cout << "" << " | ";
			std::cout.width(WIDTH_BAL);
			std::cout << "" << " |\n";
		}
		std::cout.fill(oldFill);
		std::cout.precision(oldPrec);
	}



	/* TODO: define conversion-to-string query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator const char*()
	*
	* - this conversion operator cannot be used in automatic conversions.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Account::operator const char* () const
	{
		return m_holderName;
	}



	/* TODO: define conversion-to-int query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator int()
	*
	* - this conversion operator cannot be used in automatic conversions.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Account::operator int() const
	{
		return m_number;
	}


	/* TODO: define conversion-to-double query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator double()
	*
	* - this conversion operator cannot be used in automatic conversions.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Account::operator double() const
	{
		return m_balance;
	}



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
	Account::operator bool() const
	{
		return (m_holderName[0] != '\0' and m_number >= 100000 and m_number < 1000000);

	}



	/* TODO: define the negation operator query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator!()
	*
	* - return the opposite of conversion-to-bool operator.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool Account::operator!() const
	{
		return !operator bool();
	}



	/* TODO: define the assignment operator as a mutator
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator=(name)
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Account& Account::operator=(const char* name)
	{
		if (name != nullptr and name[0] != '\0')
			strcpy(this->m_holderName, name);

		return *this;
	}


	/* TODO: define the assignment operator as a mutator
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator=(number)
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Account& Account::operator=(int number)
	{
		if (m_holderName[0] != '\0' and number >= 100000 and number < 1000000)
		{
			m_number = number;
		}
		return *this;
	}


	/* TODO: define the assignment operator as a mutator
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator=(balance)
	*
	* - use conversion-to-bool operator to check if the account is valid.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Account& Account::operator=(double balance)
	{
		if (*this) // Conversion-to-bool
		{
			m_balance = balance;
		}
		return *this;
	}



	/* TODO: define the addition operator as a query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator+(acc)
	*
	* - use conversion-to-bool operator to check if the accounts are valid.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	double Account::operator+(const Account& acc) const
	{
		double sumBalance = 0.0;
		if (*this)
		{
			return sumBalance = m_balance + acc.m_balance;
		}
		else
		{
			return sumBalance;
		}
	}



	/* TODO: define the addition operator as a query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator+(amount)
	*
	* - use conversion-to-bool operator to check if the account is valid.
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	double Account::operator+(double amount) const
	{
		double sumBalance = 0.0;
		if (*this)
		{
			return sumBalance = m_balance + amount;
		}
		else
		{
			return sumBalance;
		}
	}


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
	Account& Account::operator++()
	{
		if (*this)
		{
			m_balance += 1000;
		}
		return *this;
	}



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
	Account Account::operator++(int)
	{
		Account mu(*this);   // Create a local Account object and copy current instance
		++(*this);           // Use prefix increment operator to add 1000 to the balance
		return mu;           // Return the local object
	}



	/* TODO: define the addition-assignment operator as a mutator
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator+=(amount)
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	Account& Account::operator+=(double amount)
	{
		if (m_holderName[0] != '\0')
		{
			m_balance += amount;
		}
		return *this;
	}


	/* TODO: define the comparison operator as a query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator==(number)
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool Account::operator==(int number) const
	{
		bool okay = false;
		if (this->m_number == number and this->m_holderName != nullptr and this->m_holderName[0] != '\0')
		{
			okay = true;
		}
		return okay;
	}


	/* TODO: define the comparison operator as a query
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*
	* operator==(name)
	*
	* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
	*/
	bool Account::operator==(const char* name)const
	{
		if (m_holderName != nullptr and name != nullptr)
		{
			if (strcmp(m_holderName, name) == 0)
			{
				return true;  // Check if comparing the same instance
			}
		}

		return false;
	}


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
	Account& Account::operator<<(Account& acc)
	{
		if (this != &acc)
		{
			m_balance += acc.m_balance;
			acc.m_balance = 0.0;
		}
		return *this;
	}


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
	Account& Account::operator>>(Account& acc)
	{
		// Use the insertion operator to transfer the balance
		acc << (*this);

		// Return a reference to the current instance
		return *this;
	}

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
	double operator+(double amount, const Account& acc)
	{
		if (acc)
		{
			return amount + acc.operator double();
		}
		return 0.0;
	}

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
	double& operator+=(double& amount, const Account& acc)
	{
		if (acc)
		{
			amount += acc.operator double();
		}
		return amount;
	}

}