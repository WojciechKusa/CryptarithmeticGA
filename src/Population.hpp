/*
 * Population.hpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef POPULATION_HPP_
#define POPULATION_HPP_

#include "Genotype.hpp"
#include "Phenotype.hpp"
#include "Individual.hpp"
#include <vector>

class Population {
	public:
		Population();
		Population(std::vector<Individual> population);
		~Population();

		void initGeneration();
		void nextGeneration();

	private:
		std::vector<Individual> _population;
		int _populationSize;

		int _generation;
		int _maxGenerations;

		double _mutationProbability;
};

#endif /* POPULATION_HPP_ */
