#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <fstream>
#include <vector>
#include <tuple>

using namespace std;



struct Item {
	unsigned int value;
	unsigned int weight;
	unsigned int size;
};

class Knapsack {
	private:
		vector<Item> items;
		unsigned int sizeCapacity;
		unsigned int weightCapacity;

	public:
		/*
		Used to construct a Knapsack, with a given capacity
		*/
		Knapsack(unsigned int size, unsigned int weight, ofstream file);

		/*
		Used to evaluate the efficacy of a particular item combination
		*/
		unsigned int evaluateCode(unsigned int geneticCode) const;
};

#endif
