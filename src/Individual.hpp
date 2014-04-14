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

class Individual {
	public:
		Individual();
		~Individual();

		void init();

		double calculateFitness();
	private:
		Genotype _genotype;
		Phenotype _phenotype;

		double _fitness;
};

#endif /* INDIVIDUAL_HPP_ */
