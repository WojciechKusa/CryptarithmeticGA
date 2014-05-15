/*
 * Genotype.hpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef GENOTYPE_HPP_
#define GENOTYPE_HPP_

#include <vector>
#include <cstdlib>

class Genotype {
	public:
		Genotype(int *chromosome, int size = 10);
		Genotype();

		void init(int puzzleSize);
		void mutate(double probability);

		int getSize() const;
	protected:
		/**
		 * w tabeli -1 gdy nie ma takiej cyfry ;>
		 */
		int *_chromosome;
		int _size;
};

#endif /* GENOTYPE_HPP_ */
