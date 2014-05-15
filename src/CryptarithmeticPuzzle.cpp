/*
 * CryptarithmeticPuzzle.cpp
 *
 *  Created on: 17 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "CryptarithmeticPuzzle.hpp"

CryptarithmeticPuzzle::CryptarithmeticPuzzle() {

}

CryptarithmeticPuzzle::CryptarithmeticPuzzle(const char* fileName) {
	std::fstream file(fileName, std::ios::in);

	if( !file.good() ) {
		std::cout << "File " << fileName << "could not be opened" << std::endl;
		return;
	}

	bool line2 = false, result = false;

	while( file.good() ) {
		char c = file.get();

		if( isspace(c) || file.eof() ) {

		} else if( c == '+' ) {
			_operation = 0;
			line2 = true;
		} else if( c == '-' ) {
			_operation = 1;
			line2 = true;
		} else if( c == '*' ) {
			_operation = 2;
			line2 = true;
		} else if( c == '/') {
			_operation = 3;
			line2 = true;
		} else if ( c == '=') {
			result = true;
			line2 = false;
		} else {

			if( line2 ) {
				addPuzzleElement(c, _line2);
			} else if( result ) {
				addPuzzleElement(c, _result);
			} else {
				addPuzzleElement(c, _line1);
			}

		}

	}

//	print();
//
//	for (int i = 0 ; i < _lookupTable.size(); ++i) {
//		std::cout << _lookupTable[i] << " ";
//	}
}

CryptarithmeticPuzzle::~CryptarithmeticPuzzle() {

}

void CryptarithmeticPuzzle::print() {
	for(std::vector<int>::iterator it = _line1.begin(); it != _line1.end(); ++it) {
		std::cout << _lookupTable[*it];
	}
	std::cout << std::endl << getOperation() << std::endl;

	for(std::vector<int>::iterator it = _line2.begin(); it != _line2.end(); ++it) {
		std::cout << _lookupTable[*it];
	}
	std::cout << std::endl << "=" << std::endl;

	for(std::vector<int>::iterator it = _result.begin(); it != _result.end(); ++it) {
		std::cout << _lookupTable[*it];
	}
	std::cout << std::endl;

}

void CryptarithmeticPuzzle::addPuzzleElement(const char &c, std::vector<int> &line) {
	std::vector<char>::iterator it = std::find(_lookupTable.begin(), _lookupTable.end(), c);

	if( it != _lookupTable.end() ) {
		line.push_back(std::distance(_lookupTable.begin(), it));
	} else {
		_lookupTable.push_back(c);
		it = std::find(_lookupTable.begin(), _lookupTable.end(), c);
		line.push_back(std::distance(_lookupTable.begin(), it));
	}
}

char CryptarithmeticPuzzle::getOperation() const {
	if( _operation == 0 ) {
		return '+';
	} else if( _operation == 1 ) {
		return '-';
	} else if( _operation == 2 ) {
		return '*';
	} else {
		return '/';
	}
}

double CryptarithmeticPuzzle::solve(std::vector<int> solution) {
	int sol1 = 0, sol2 = 0, solLine1 = 0, solLine2 = 0;

	int i = 1;
	for(std::vector<int>::reverse_iterator it = _line1.rbegin(); it != _line1.rend(); ++it) {
		solLine1 += solution[*it]*i;
		i *= 10;
	}

	i = 1;
	for(std::vector<int>::reverse_iterator it = _line2.rbegin(); it != _line2.rend(); ++it) {
		solLine2 += solution[*it]*i;
		i *= 10;
	}

	if( _operation == 0 ) {
		sol1 =  solLine1 + solLine2;
	} else if( _operation == 1 ) {
		sol1 =  solLine1 - solLine2;
	} else if( _operation == 2 ) {
		sol1 =  solLine1 * solLine2;
	} else {
		sol1 =  solLine1 / solLine2;
	}

	i = 1;
	for(std::vector<int>::reverse_iterator it = _result.rbegin(); it != _result.rend(); ++it) {
		sol2 += solution[*it]*i;
		i *= 10;
	}

//	std::cout << sol1 << "\t" << sol2 << std::endl;

	return (sol1 - sol2);
}
