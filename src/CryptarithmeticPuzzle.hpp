/*
 * CryptarithmeticPuzzle.hpp
 *
 *  Created on: 17 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef CRYPTARITHMETICPUZZLE_HPP_
#define CRYPTARITHMETICPUZZLE_HPP_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <ctype.h>


/**
 * class representing Cryptarithmetic Puzzle, containing letter representation of puzzle.\n
 */
class CryptarithmeticPuzzle {
	public:
		CryptarithmeticPuzzle();
		CryptarithmeticPuzzle(const char* fileName);
		~CryptarithmeticPuzzle();

		void print();

		char getOperation() const;

		void addPuzzleElement(const char &c, std::vector<int> &line);

		double solve(std::vector<int> solution);


	private:

		std::vector<char> _lookupTable;

		int _variable;

		/**
		 * default base = 10
		 */
		int _base;

		std::vector<int> _line1;
		std::vector<int> _line2;

		std::vector<int> _result;

		int _operation;

		enum _operations {
			ADDITION = 0,
			SUBSTRACTION = 1,
			MULTIPLICATION = 2,
			DIVISION = 3
		};
};

#endif /* CRYPTARITHMETICPUZZLE_HPP_ */
