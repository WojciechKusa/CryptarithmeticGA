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
	const int populationSize, double mutationProbability, CryptarithmeticPuzzle cp) : _cp(cp),
		 _maxGenerations(maxGenerations), _populationSize(populationSize), _mutationProbability(mutationProbability) {

 	_averageFit = 0;
 	_worstFit = 0;
 	_bestFit = 0;
 	_generation = 0;


	for(int i = 0; i < populationSize; ++i) {
		_population.push_back(Individual(_cp.getLookupTable().size()));
	}

}

void GeneticAlgorithm::nextGeneration() {
	std::vector<Individual>::iterator it;

	for(it = _population.begin(); it != _population.end(); ++it) {
		it->_genotype.mutate(_mutationProbability);

		it->calculateFitness(_cp);
	}
	calculateStatistics();

}

void GeneticAlgorithm::evolve() {

	std::fstream file("log.txt", std::ios::out);

	file << "generation\t average fit\t best fit\t worst fit "<< std::endl;

	initPopulation();

	for(_generation = 0; _generation < _maxGenerations; ++_generation) {
		nextGeneration();

		file << _generation << "\t" << _averageFit << "\t" << _bestFit << "\t" << _worstFit << std::endl;
	}

	file.close();
}

void GeneticAlgorithm::initPopulation() {

// #ifdef PARALLEL
// 	int argc = 0;
// 	char **argv = NULL;
// 	int myid; // id tego komputera
// 	int numprocs; // ilosc procesorow
// 	int namelen; // nazwa konkretnego procesora
// 	char processor_name[MPI_MAX_PROCESSOR_NAME];

// 	MPI_Init(&argc, &argv); // uzyskanie dostepu do srodowiska mpi

// 	MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // definiujemy ilosc procesorow
// 	MPI_Comm_rank(MPI_COMM_WORLD, &myid); // definiujemy id tego procesora
// 	MPI_Get_processor_name(processor_name, &namelen); // pobieramy nazwe proc.


// 	if(myid == 0) {
	
// #endif

	std::vector<Individual>::iterator it;

	for(it = _population.begin(); it != _population.end(); ++it) {
		it->init();
		it->calculateFitness(_cp);
	}

	calculateStatistics();

// #ifdef PARALLEL
// }
// 	MPI_Finalize(); // obowiazkowe zamkniecie mpi
// #endif
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

	std::cout << "Best individual fitness function value: " << _bestIndividual._fitness << std::endl;
	std::cout << "Average fitness function value: " << _averageFit << std::endl;

}

void GeneticAlgorithm::calculateStatistics() {
	std::vector<Individual>::iterator it;

	double sumFit = 0;

	double temp = _population.begin()->_fitness;
	double temp1 = _population.begin()->_fitness;

	_bestIndividual = *(_population.begin());

	for( it = _population.begin(); it != _population.end(); ++it) {
		if ( it->_fitness < temp ) {
			temp = it->_fitness;
			sumFit += it->_fitness;

			_bestIndividual = *	it;
		}

		if ( it->_fitness > temp1 ) {
			temp1 = it->_fitness;
		}
	}
	_averageFit = sumFit/(static_cast<double>(_populationSize));
	_bestFit = temp;
	_worstFit = temp1;
}

double GeneticAlgorithm::getAverageFit() const {
	return _averageFit;
}

double GeneticAlgorithm::getBestFit() const {
	return _bestFit;
}

double GeneticAlgorithm::getWorstFit() const {
	return _worstFit;
}

void GeneticAlgorithm::setCryptarithmeticPuzzle(CryptarithmeticPuzzle cp) {
	_cp = cp;
}

void GeneticAlgorithm::setMutationProbability(double mutationProbability) {
	_mutationProbability = mutationProbability;
}
