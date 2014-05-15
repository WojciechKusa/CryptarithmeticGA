/*
 * Phenotype.hpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef PHENOTYPE_HPP_
#define PHENOTYPE_HPP_

#include "Genotype.hpp"
#include <vector>

struct Phenotype {
	Phenotype();
	Phenotype(int puzzleSize);
	~Phenotype();

	void decode(Genotype genotype);

	std::vector<int> _decodedChromosome;
	int _puzzleSize;
};

#endif /* PHENOTYPE_HPP_ */
