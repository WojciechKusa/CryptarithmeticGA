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

struct Genotype {

	Genotype(int size = 10);

	Genotype(const Genotype& g);

	~Genotype();

	Genotype & operator=(Genotype &g);

	void init();
	void mutate(double probability);

	int *_chromosome;
	int _size;
};

#endif /* GENOTYPE_HPP_ */
