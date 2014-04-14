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

class GeneticAlgorithm {
	public:
		GeneticAlgorithm();
		virtual ~GeneticAlgorithm();

		void nextGeneration();

		void initPopulation();


	private:
		Population _population;

		int _generation;
		int _maxGenerations;

		double _bestFit;
		double _worstFit;
		double _averageFit;


};

#endif /* GENETICALGORITHM_HPP_ */
