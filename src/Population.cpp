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
	for(int i = 0; i < _populationSize; ++i) {
		_population.insert(Individual(puzzleSize));
	}
}

Population::~Population() {

}

void Population::initGeneration() {
	std::multiset<Individual>::iterator it;
	for(it = _population.begin(); it != _population.end(); ++it) {
//		it->init(); //problem z const iteratorem - potrzebne c++11
	}
}

void Population::nextGeneration() {
}


