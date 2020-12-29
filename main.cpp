#include "Population.h"
#include "Knapsack.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		return 1;
	}

	Knapsack knapsack(argv[1], 100, 100);
	Population population(knapsack, 100, 4, 0.05);

	for(int i = 0; i < 100; i++) {
		population.newGeneration();
	}

	cout << (unsigned int) population.getBestCode() << ", " << (unsigned int) knapsack.evaluateCode(population.getBestCode()) << endl;
	return 0;
}