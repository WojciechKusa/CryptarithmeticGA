/*
 * Population.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "Population.hpp"

Population::Population() {

}

Population::Population(std::vector<Individual> population) {

}

Population::Population(int populationSize, int puzzleSize) : _populationSize(populationSize) {
	for(int i = 0; i < populationSize; ++i) {
		_population.push_back(Individual(puzzleSize));
	}

//	std::cout << "aaaa";
}

Population::~Population() {

}

void Population::initGeneration() {
	std::vector<Individual>::iterator it;
	for(it = _population.begin(); it != _population.end(); ++it) {
		it->init();
	}
}


