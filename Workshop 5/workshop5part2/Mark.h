//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
// Date           : 15/06/2023(Thursday)
//==============================================

#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds
{
	class Mark
	{
		char* m_grade;

		double m_gpa;

		int m_mark;

	public:
		//! Default Constructor
		//Mark();


		/// <summary>
/// Initializes the current instance with setting the mark to
///   the value of the parameter.
/// </summary>
/// <param name="value">An integer representing the mark.  This
///   parameter is optional, with a default value of 0. Only values
///   between 0 and 100 are considered valid.</param>
		Mark(int value = 0);



		/// <summary>
		/// Increase the mark by the value received as parameter.  If the current
		///   mark is not valid, this operator does nothing.
		/// </summary>
		/// <param name="value">An integer, representing how much to increase
		///   the current mark.</param>
		/// <returns>A reference to the current instance.</returns>
		Mark& operator+=(int value);

		/// <summary>
		/// The assignment operator sets the mark to the value received as parameter.
		/// </summary>
		/// <param name="value">An integer, representing the new mark.</param>
		/// <returns>A reference to the current instance.</returns>
		Mark& operator=(char* name);

		/// <summary>
		/// A conversion-to-integer operator overload. Returns the number representing
		///   the mark in the interval [0, 100]. If the mark is not valid, this
		///   operator returns 0.
		/// </summary>
		operator int() const;

		/// <summary>
		/// A conversion-to-char operator overload. Returns the letter representation
		///   of the mark (see the provided table). If the mark is not valid, this
		///   operator returns `X`.
		/// </summary>
		operator char()const;

		/// <summary>
		/// A conversion-to-double operator overload. Returns the GPA equivalent of the
		///   mark (see the provided table). If the mark is not valid, this operator
		///   returns 0.
		/// </summary>
		operator double() const;

	};

	/// <summary>
/// An overload of the addition-assignment operator that allows to add the mark
///   to an integer (received as the first parameter), returning the integer
///   after the operation. Invalid marks will not add any value to the integer.
/// </summary>
/// <param name="value">A reference to an integer.</param>
/// <param name="theMark">The mark to add to the first parameter.</param>
/// <returns>A reference to the first parameter.</returns>
	int& operator+=(int& val, const Mark& theMark);
}

#endif