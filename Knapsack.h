#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <string>
#include <vector>
#include <tuple>

using namespace std;



struct Item {
	unsigned char value;
	unsigned char weight;
	unsigned char size;
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
		Knapsack(string fileName, unsigned int sizeCapacity, unsigned int weightCapacity);

		/*
		Used to evaluate the efficacy of a particular item combination
		*/
		unsigned int evaluateCode(unsigned int geneticCode) const;
};

#endif
