/*
 * GeneticAlgorithm.hpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef GENETICALGORITHM_HPP_
#define GENETICALGORITHM_HPP_

#include "Genotype.hpp"
#include "Phenotype.hpp"
#include "Individual.hpp"
#include "Population.hpp"
#include "CryptarithmeticPuzzle.hpp"
#include <vector>

class GeneticAlgorithm {
	public:
		GeneticAlgorithm();
		GeneticAlgorithm(const int maxGenerations, const int populationSize);
		virtual ~GeneticAlgorithm();

		void nextGeneration();

		bool haltingCondition();

		void printSolution();

		void evolve();

		void initPopulation();

		void setMaxGenerations(int maxGenerations);
		void setPopulationSize(int populationSize);
		void setMutationProbability(double mutationProbability);

		void setCryptarithmeticPuzzle(CryptarithmeticPuzzle &cp);

	private:
		Population _population;
		Population _tempPopulation;

		Individual _bestIndividual;

		int _generation;
		int _maxGenerations;

		int _populationSize;

		double _mutationProbability;

		double _bestFit;
		double _worstFit;
		double _averageFit;

		CryptarithmeticPuzzle _cp;
};

#endif /* GENETICALGORITHM_HPP_ */
