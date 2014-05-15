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
#include <set>

struct Population {
	Population();
	Population(int populationSize, int puzzleSize);
	Population(std::vector<Individual> population);
	~Population();

	void initGeneration();

//		struct FitnessComparison {
//		  bool operator() (const Individual& lhs, const Individual& rhs) {
//			  return lhs.getFitness() < rhs.getFitness();
//		  }
//		};
//
//		std::multiset<Individual, FitnessComparison> _population;

	std::vector<Individual> _population;
	int _populationSize;

	int _generation;
	int _maxGenerations;

	double _mutationProbability;

};

#endif /* POPULATION_HPP_ */
