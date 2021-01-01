#include <stdio.h>
#include <cstdlib>

using namespace std;

#include "Population.h"
#include "Knapsack.h"

int main(int argc, char* argv[]) {
	if(argc != 2) {
		return 1;
	}

	Knapsack knapsack(argv[1], 100, 100);
	Population population(knapsack, 1000, 8, 0.1);

	unsigned int generationCount = 10000;
	for(int i = 0; i < generationCount; i++) {
		population.newGeneration((unsigned int) ((31.0/generationCount) * i) + 1);
	}

	printf("%x, %u\n", population.getBestCode(), knapsack.evaluateCode(population.getBestCode()) );
	return 0;
}