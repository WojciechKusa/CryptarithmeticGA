/*
 * GeneticAlgorithm.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "GeneticAlgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm() {
}

GeneticAlgorithm::~GeneticAlgorithm() {

}

GeneticAlgorithm::GeneticAlgorithm(const int maxGenerations,
	const int populationSize, double mutationProbability, CryptarithmeticPuzzle &cp) : _cp(cp),
		_population(populationSize, _cp.getLookupTable().size()), _populationSize(populationSize), _mutationProbability(mutationProbability) {
}

void GeneticAlgorithm::nextGeneration() {

}

void GeneticAlgorithm::evolve() {


	initPopulation();

	for(_generation = 0; _generation < _maxGenerations; ++_generation) {
		nextGeneration();
	}
}

void GeneticAlgorithm::initPopulation() {
	_population.initGeneration();

	calculateStatistics();
}

void GeneticAlgorithm::setMaxGenerations(int maxGenerations) {
	_maxGenerations = maxGenerations;
}

void GeneticAlgorithm::setPopulationSize(int populationSize) {
	_populationSize = populationSize;
}

bool GeneticAlgorithm::haltingCondition() {
	if( _bestFit == 0 ) {
		return true;
	} else {
		return false;
	}
}

void GeneticAlgorithm::printSolution() {
	std::vector<char> lt = _cp.getLookupTable();

	for (unsigned int i = 0; i < lt.size(); ++i) {
		std::cout << lt[i] << " = " << _bestIndividual._genotype._chromosome[i] << std::endl;
	}

	std::cout << "Fitness function value: " << _bestIndividual._fitness << std::endl;
}

void GeneticAlgorithm::calculateStatistics() {
	std::vector<Individual>::iterator it;

	double sumFit = 0;

	double temp = _population._population.begin()->_fitness;
	_bestIndividual = *(_population._population.begin());

	for( it = _population._population.begin(); it != _population._population.end(); ++it) {
		if ( it->_fitness < temp ) {
			temp = it->_fitness;
			sumFit += it->_fitness;

			_bestIndividual = *it;
		}
	}
	_averageFit = sumFit/(static_cast<double>(_populationSize));

//	_bestIndividual = *it;
}

void GeneticAlgorithm::setCryptarithmeticPuzzle(CryptarithmeticPuzzle &cp) {
	_cp = cp;
}

void GeneticAlgorithm::setMutationProbability(double mutationProbability) {
	_mutationProbability = mutationProbability;
}
