/*
 * Genotype.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "Genotype.hpp"


Genotype::Genotype(int *chromosome, int size) : _size(size) {
	_chromosome = new int[_size];

	for(int i = 0; i < _size; ++i) {
		_chromosome[i] = chromosome[i];
	}
}

void Genotype::init(int puzzleSize) {
	for(int i = 0; i < _size; ++i) {
		if(i <= puzzleSize) {

			int random = rand()%10;

			_chromosome[i] = random;
		} else {
			_chromosome[i] = -1;
		}
	}
}

void Genotype::mutate(double probability) {

	double prob = ((double) rand() / (RAND_MAX));

	if(prob <= probability) {
		int index1 = rand()%_size;
		int index2 = rand()%_size;

		int temp = _chromosome[index1];
		_chromosome[index1] = _chromosome[index2];
		_chromosome[index2] = temp;
	}

}

int Genotype::getSize() const {
	return _size;
}

Genotype::Genotype() {

}
