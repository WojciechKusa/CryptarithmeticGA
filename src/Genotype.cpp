/*
 * Genotype.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "Genotype.hpp"


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
	if( _chromosome != NULL ) {
		delete []_chromosome;
	}
}

Genotype::Genotype(const Genotype& g) {

	this->_chromosome = new int[g._size];
	this->_size = g._size;

	for(int i = 0; i < g._size; ++i) {
		this->_chromosome[i] = g._chromosome[i];
	}
}

Genotype& Genotype::operator=(Genotype &g) {
	delete [](this->_chromosome);

	this->_size = g._size;
	this->_chromosome = new int[this->_size];

	for(int i = 0; i < g._size; ++i) {
		this->_chromosome[i] = g._chromosome[i];
	}	

	return *this;
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

