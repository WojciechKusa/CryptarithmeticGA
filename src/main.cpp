/*
 * main.cpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

//  #define PARALLEL
#include <iostream>
#include <fstream>
#include "GeneticAlgorithm.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Individual.hpp"

#ifdef PARALLEL
#include "mpi.h"
#endif

int main(int argc, char **argv) {

#ifdef PARALLEL
	int myid; // id tego komputera
	int numprocs; // ilosc procesorow
	int namelen; // nazwa konkretnego procesora
	char processor_name[MPI_MAX_PROCESSOR_NAME];

	MPI_Init(&argc, &argv); // uzyskanie dostepu do srodowiska mpi

	MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // definiujemy ilosc procesorow
	MPI_Comm_rank(MPI_COMM_WORLD, &myid); // definiujemy id tego procesora
	MPI_Get_processor_name(processor_name, &namelen); // pobieramy nazwe proc.


	if(myid == 0) {
	
#endif


	clock_t startTime = clock();

	CryptarithmeticPuzzle cp("puzzle.txt");
	cp.print();

	std::vector<int> solution;
	solution.push_back(9);
	solution.push_back(5);
	solution.push_back(6);
	solution.push_back(7);
	solution.push_back(1);
	solution.push_back(0);
	solution.push_back(8);
	solution.push_back(2);


	std::cout <<  cp.solve(solution) << std::endl;


	GeneticAlgorithm ga(50, 1000, 0.9, cp); // 50 pokolen, 10 osobnikow, 0.3 prawdopodobienstwo, zagadka

	ga.evolve();

	ga.printSolution();


	std::cout << "Program worked " << double( clock() - startTime ) / (double)CLOCKS_PER_SEC << " seconds." << std::endl;
#ifdef PARALLEL
	}
	MPI_Finalize(); // obowiazkowe zamkniecie mpi
#endif

}
