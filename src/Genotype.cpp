/*
 * Genotype.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#include "Genotype.hpp"

Genotype::Genotype() {

}

Genotype::~Genotype() {

}

Genotype::Genotype(std::vector<int> chromosome) : _chromosome(chromosome) {
}

void Genotype::init() {
}

void Genotype::mutate() {
}

int Genotype::getSize() const {
	return _chromosome.size();
}
