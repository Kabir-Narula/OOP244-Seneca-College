
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
//! LIST OF LABEL
#include "Label.h"
namespace sdds
{
	class LabelMaker
	{
		//Number of the label
		int m_noOfLabels;

		Label* m_label; //Array of labels



	public:
		/// <summary>
		/// Creates a dynamically allocated array of objects of type
		///   `Label` of size specified as a parameter. Stores the
		///   address of the array in an attribute and manages it.
		/// </summary>
		/// <param name="noOfLabels">The number of labels in the array.</param>
		LabelMaker(int noOfLabels);

		/// <summary>
		/// Reads from keyboard the labels and stores them in the array.
		/// 
		/// **NOTE**: look in the sample output for hints.
		/// </summary>
		void readLabels();

		/// <summary>
		/// Prints to screen all the labels stored in current instance.
		/// 
		/// **NOTE**: look in the sample output for hints.
		/// </summary>
		void printLabels() const;

		/// <summary>
		/// Clean-up any resource used by the current instance.
		/// </summary>
		~LabelMaker();
	};
}
#endif
