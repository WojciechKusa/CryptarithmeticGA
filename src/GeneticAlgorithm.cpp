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
	const int populationSize) : _population(_populationSize, _cp.getLookupTable().size()) {

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
}



void GeneticAlgorithm::setCryptarithmeticPuzzle(CryptarithmeticPuzzle &cp) {
	_cp = cp;
}

void GeneticAlgorithm::setMutationProbability(double mutationProbability) {
	_mutationProbability = mutationProbability;
}
