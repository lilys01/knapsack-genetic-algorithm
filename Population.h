#ifndef POPULATION_H
#define POPULATION_H

#include "Knapsack.h"
#include <vector>
#include <tuple>

using namespace std;



class Population {

	private:
		Knapsack knapsack;
		vector<vector<int>> geneticCodes;		// The history of each generation
		int size;
		int bestCode;

	public:
		
		/*
		Construct the population randomly with a given population size
		*/
		Population(int popSize, Knapsack knapsack);

		/*
		Create a new generation using tournament selection and returns the efficacy of the best code
		Interally it updates its vector of genetic codes, and it's internal track of the best code
		*/
		int newGeneration();

};

#endif