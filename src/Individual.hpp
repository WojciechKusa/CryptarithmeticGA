/*
 * Individual.hpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef INDIVIDUAL_HPP_
#define INDIVIDUAL_HPP_

#include "Genotype.hpp"
#include "Phenotype.hpp"
#include "CryptarithmeticPuzzle.hpp"

struct Individual {
	Individual();
	Individual(int puzzleSize);
	~Individual();

	void init();

	double calculateFitness(CryptarithmeticPuzzle cp);

	double getFitness() const;

	Genotype _genotype;
	Phenotype _phenotype;

	static int ixx;

	double _fitness;
};


#endif /* INDIVIDUAL_HPP_ */
