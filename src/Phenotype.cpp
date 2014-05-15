/*
 * Phenotype.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "Phenotype.hpp"

Phenotype::Phenotype() {

}

Phenotype::~Phenotype() {

}

Phenotype::Phenotype(int puzzleSize) : _puzzleSize(puzzleSize) {
}

void Phenotype::decode(Genotype genotype) {
	_decodedChromosome.clear();

	for(int i = 0; i < _puzzleSize; ++i) {
		_decodedChromosome.push_back(genotype._chromosome[i]);
	}
}

