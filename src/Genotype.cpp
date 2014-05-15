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

void Genotype::init() {
	bool tab[10] = {false};
	bool isSetted = false;

	for(int i = 0; i < _size; ++i) {

		while ( !isSetted ) {
			int random = rand()%_size;

			if( !tab[random] ) {
				_chromosome[i] = random;
				tab[random] = true;
				isSetted = true;
			}
		}
		isSetted = false;
	}
}

Genotype::~Genotype() {
	delete []_chromosome;
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


Genotype::Genotype(int size) : _size(size) {
	_chromosome = new int[_size];
}

