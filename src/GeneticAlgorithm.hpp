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
		GeneticAlgorithm(const int maxGenerations, const int populationSize, double mutationProbability, CryptarithmeticPuzzle &cp);
		virtual ~GeneticAlgorithm();

		void nextGeneration();

		bool haltingCondition();

		void calculateStatistics();

		void printSolution();

		void evolve();

		void initPopulation();

		void setMaxGenerations(int maxGenerations);
		void setPopulationSize(int populationSize);
		void setMutationProbability(double mutationProbability);

		void setCryptarithmeticPuzzle(CryptarithmeticPuzzle &cp);

	private:
		CryptarithmeticPuzzle _cp;

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

};

#endif /* GENETICALGORITHM_HPP_ */
