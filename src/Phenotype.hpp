/*
 * Phenotype.hpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef PHENOTYPE_HPP_
#define PHENOTYPE_HPP_

#include "Genotype.hpp"

class Phenotype {
	public:
		Phenotype();
		Phenotype(Genotype genotype);
		~Phenotype();

		void decode(Genotype genotype);

		double fitnessFunction();

	private:
		double _decodedChromosome;
};

#endif /* PHENOTYPE_HPP_ */
