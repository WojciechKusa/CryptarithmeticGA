/*
 * Genotype.hpp
 *
 *  Created on: 10 kwi 2014
 *      Author: Filip Koperski, Wojciech Kusa
 */

#ifndef GENOTYPE_HPP_
#define GENOTYPE_HPP_

#include <vector>

class Genotype {
	public:
		Genotype();
		Genotype(std::vector<int> chromosome);
		~Genotype();

		void init();
		void mutate();

		int getSize() const;
	protected:
		std::vector<int> _chromosome;
};

#endif /* GENOTYPE_HPP_ */
