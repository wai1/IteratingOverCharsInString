

/* The following are four ways one can iterate over characters
 * of a string in C++. Most of the information is from:
 * https://www.techiedelight.com/iterate-over-characters-string-cpp/
 * This page provides information on STL algorithm functions:
 * https://docs.microsoft.com/en-us/cpp/standard-library/algorithm-functions?view=vs-2019
*/
#pragma once
#include "main.hpp"
#include <iostream>
#include <algorithm>


/* Iterate over the characters of a string using a for loop and print each character
 * at the current index using [] operator
*/

/* Note: The address operator will send address of string
 * Any changes in function will change string in caller
 * Caller's string will not be changed when there is no address operator
 * const will prevent caller's string from changing
*/

void printSimpleForLoop(const std::string& s)
{

	// s = "good-bye";
	for (std::string::size_type i = 0; i < s.size(); i++) {
		std::cout << s[i] << ' ';
	}
}

/* This is the recommended approach in C+11 and above to iterate over the characters of a
 * std::string using a range-based for loop
 */
void printRangeBasedForLoop(const std::string& s)
{
	for (char const& c : s) {
		std::cout << c << ' ';
	}
}

/* This uses an iterator to iterate over the characters of a std::string. Since the iteration is
 * read-only, we can use std::string::const_iterator returned by std::string::cbegin and std::string::cend
 */
void printUsingIterator(const std::string& s)
{
	for (auto it = s.cbegin(); it != s.cend(); ++it) {
		std::cout << *it << ' ';
	}
}

/* The complexity can be reduced by using std::for_each STL algorithm, which applies a specified function
 * to every element of the input range.
 */

 // This is the user defined function object that is applied to each element in the range
void fn(char const& c) {
	std::cout << c << ' ';
}

// Allows access to and modification (if needed) to each element within a range
void printUsingForEachAlgorithm(const std::string& s)
{
	std::for_each(s.begin(), s.end(), fn);
}

int main()
{
	std::string s("hello");
	std::cout << "************************" << std::endl;

	printSimpleForLoop(s);
	// std::cout << s << std::endl;

	std::cout << "\n************************" << std::endl;
	printRangeBasedForLoop(s);

	std::cout << "\n************************" << std::endl;
	printUsingIterator(s);

	std::cout << "\n************************" << std::endl;
	printUsingForEachAlgorithm(s);

	std::cout << "\n************************" << std::endl;

	return 0;
}