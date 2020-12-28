#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <fstream>
#include <vector>
#include <tuple>

using namespace std;



struct Item {
	int value;
	int weight;
	int size;
};

class Knapsack {
	private:
		vector<Item> items;
		int sizeCapacity;
		int weightCapacity;

	public:
		/*
		Used to construct a Knapsack, with a given capacity
		*/
		Knapsack(int size, int weight, ofstream file);

		/*
		Used to evaluate the efficacy of a particular item combination
		*/
		int evaluateCode(int geneticCode) const;
};

#endif