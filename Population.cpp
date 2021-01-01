#include <queue>
#include <tuple>
#include <random>
#include <limits>

using namespace std;

#include "GeneticCode.h"
#include "Population.h"
#include "Knapsack.h"


unsigned int Population::newGeneration(unsigned int bitsPerCrossover){
	vector<unsigned int> parentGen = this->geneticCodes.back();
	vector<unsigned int> n(this->size);
	unsigned int parentA;
	unsigned int parentB;

  	// Fandom number generator
	default_random_engine generator(random_device{}());
	uniform_int_distribution<unsigned int> randTournament(0, parentGen.size()-1);
	uniform_int_distribution<unsigned char> randParent(0, 1);
	uniform_real_distribution<double> randMutation(0.0, 1.0);

	while(n.size() < this->size){

    	// Tournament selection for 2 parents
		for(unsigned char i = 0; i < 2; i++){

			priority_queue<tuple<unsigned int, unsigned int>> pq;

      		// Add codes for tournament to pq
			for(unsigned int j = 0; j < this->tournamentSize; j++){
				unsigned int index = randTournament(generator);
				unsigned int fitness = this->knapsack.evaluateCode(parentGen[index]);

				pq.push(make_tuple(fitness, parentGen[index]));
			}

      		// Add most fit code from the tournament to be a parent
      		if(i == 0) {
				parentA = get<0>(pq.top());
      		} else {
      			parentB = get<0>(pq.top());
      		}
		}

    	// Make new generation from parents
		for(unsigned int i = 0; i < 2; i++){

			unsigned int child = 0;


			unsigned int parent;
			if(randParent(generator) == 0) {
				parent = parentA;
			} else {
				parent = parentB;
			}
			for(unsigned int j = 0; j < 32; j++){

        		// Crossover
        		if(j%bitsPerCrossover == 0) {
					if(randParent(generator) == 0) {
						parent = parentA;
					} else {
						parent = parentB;
					}
				}

				unsigned int trait = GeneticCode::readBit(parent, j);

        		// Mutation
				if(randMutation(generator) < this->mutationRate){
					trait = trait ^ 1;
				}

				GeneticCode::writeBit(child, j, trait);
			}

			n.push_back(child); 
		}
	}

	geneticCodes.push_back(n);

	// Updating the best code
	unsigned int bestFitness = this->knapsack.evaluateCode(this->bestCode);

	unsigned int fitness;
	for(unsigned int i: n) {
		fitness = this->knapsack.evaluateCode(i);

		if(fitness > bestFitness) {
			bestFitness = fitness;
			this->bestCode = i;
		}
	}

	return this->bestCode;
}



Population::Population(Knapsack knapsack, unsigned int popSize, unsigned int tournamentSize, double mutationRate): 
					knapsack(knapsack), size(popSize), tournamentSize(tournamentSize), mutationRate(mutationRate), bestCode(0) {

	// Random number generator
	default_random_engine generator(random_device{}());
	uniform_int_distribution<unsigned int> randCode(0, numeric_limits<unsigned int>::max());

	// Keeping track of the best code for the initial generation
	unsigned int bestFitness = 0;
	unsigned int fitness;

	// Generating first set of random codes
	vector<unsigned int> newGen;
	for(unsigned int i = 0; i < this->size; i++) {
		newGen.push_back(randCode(generator));

		// Max fitness
		fitness = this->knapsack.evaluateCode(newGen.back());
		if(fitness > bestFitness) {
			bestFitness = fitness;
			this->bestCode = newGen.back();
		}
	}

	this->geneticCodes.push_back(newGen);
}