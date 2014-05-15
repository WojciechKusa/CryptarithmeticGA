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

void GeneticAlgorithm::nextGeneration() {
}

void GeneticAlgorithm::evolve() {
	for(_generation = 0; _generation < _maxGenerations; ++_generation) {
		nextGeneration();
	}
}

void GeneticAlgorithm::initPopulation() {
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

void GeneticAlgorithm::setCryptarithmeticPuzzle(CryptarithmeticPuzzle &cp) {
	_cp = cp;
}

void GeneticAlgorithm::setMutationProbability(double mutationProbability) {
	_mutationProbability = mutationProbability;
}
