/*
 * Individual.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "Individual.hpp"

Individual::Individual(int puzzleSize) : _genotype(10), _phenotype(puzzleSize) {
//	std::cout << "xx\n" << ++ixx;
}

Individual::~Individual() {

}

void Individual::init() {
	_genotype.init();
	_phenotype.decode(_genotype);
}

double Individual::calculateFitness(CryptarithmeticPuzzle cp) {
	_fitness = cp.solve(_phenotype._decodedChromosome);
	return _fitness;
}

Individual::Individual() {

}

double Individual::getFitness() const {
	return _fitness;
}

int Individual::ixx = 0;

