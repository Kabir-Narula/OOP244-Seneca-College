
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds
{
	class Label
	{
		/*
		The Label class creates a label by drawing a frame around a one-line text with an unknown size
		(maximum of 70 chars; the class must store in an attribute the address of a dynamically allocated array of characters).
		*/
		char* m_label;

		// The frame is dictated by a series of 8 characters in a C-string. These characters indicate how the frame is to be drawn:
		char m_frame[9];  // 8 + '\0'


	public:
		/// <summary>
	/// Creates an empty label with the frame `"+-+|+-+|"`.
	/// </summary>
		Label();

		/// <summary>
		/// Creates an emtpy label specified frame.
		/// </summary>
		/// <param name="frame">The frame for the label.</param>
		Label(const char* frame);

		/// <summary>
		/// Creates a label with specified frame and content.
		/// </summary>
		/// <param name="frame">The frame for the label.</param>
		/// <param name="content">The text to be displayed inside the label.
		///   Must be stored dynamically in an attribute.</param>
		Label(const char* frame, const char* content);

		/// <summary>
		/// Clean-up any dynamic memory used by the current instance.
		/// </summary>
		~Label();

		/// <summary>
		/// Reads the label from console up to 70 characters and
		///   stores it in the current object.
		/// </summary>
		void readLabel();

		/// <summary>
		/// Prints the label to screen by drawing the frame around the content.
		/// 
		/// Note that no newline is printed after the last line.
		/// </summary>
		/// <returns>`std::cout`</returns>
		std::ostream& print() const;

	};
}

#endif
