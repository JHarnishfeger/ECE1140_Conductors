#pragma once
#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP
#include <string>
#include <list>

/* Utility functions for handling strings */
class string_utils{

	public:

		/* Return the nth word from a list of words separated by a delimiter.
		 * If the index is not valid, then return an empty string. */
		static std::string nth_word(std::string input, unsigned int index, char delim=' ');
		
		/* Separates a string separated by a delimiter into a list of strings. */
		static std::list<std::string> separate_strings(std::string input, char delim=' ');
		
		/* Returns a byte scaled to cover the range of A-Z or a-z. 
		 * For example: 'A' returns 0, 'z' returns 255, 'G' returns 58. 
		 * Any non-alphabetic characters return 0.*/
		static char char_to_rgb(char alpha);
	
	private:
	
		/* Returns the number of delimiters in a given sentence. */
		static int num_delims(std::string input, char delim);
};

#endif
