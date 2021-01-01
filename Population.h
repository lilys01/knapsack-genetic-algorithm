#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <tuple>

using namespace std;

#include "Knapsack.h"



class Population {

	private:
		Knapsack knapsack;
		vector<vector<unsigned int>> geneticCodes;		// The history of each generation
		unsigned int size;
		unsigned int bestCode;
		unsigned int tournamentSize;
		double mutationRate;

	public:

		/*
		Construct the population randomly with a given population size
		*/
		Population(Knapsack knapsack, unsigned int popSize, unsigned int tournamentSize, double mutationRate);

		/*
		Create a new generation using tournament selection and returns the efficacy of the best code
		Interally it updates its vector of genetic codes, and it's internal track of the best code
		*/
		unsigned int newGeneration(unsigned int bitsPerCrossover);

		const unsigned int getBestCode() const {
			return this->bestCode;
		};

};

#endif
