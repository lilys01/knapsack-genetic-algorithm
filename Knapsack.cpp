#include <fstream>
#include <string>
#include <random>
#include <limits>

using namespace std;

#include "GeneticCode.h"
#include "Knapsack.h"


Knapsack::Knapsack(string fileName, unsigned int sizeCapacity, unsigned int weightCapacity):
					sizeCapacity(sizeCapacity), weightCapacity(weightCapacity) {

	ofstream file(fileName, ofstream::out);

  	// Fandom number generator
	default_random_engine generator; // random_device{}()
	uniform_int_distribution<unsigned char> randValue (1, numeric_limits<unsigned char>::max());
	uniform_int_distribution<unsigned char> randWeight (0, this->weightCapacity / 10);
	uniform_int_distribution<unsigned char> randSize (0, this->sizeCapacity / 10);

	// Generate random items and record to file
	for(unsigned char i = 0; i < 32; i++) {
		struct Item item = {randValue(generator), randWeight(generator), randSize(generator)};
		this->items.push_back(item);

		file << (unsigned int) i << ", " << (unsigned int) item.value << ", " << (unsigned int) item.weight << ", " << (unsigned int) item.size << endl;
	}

	file.close();
}



unsigned int Knapsack::evaluateCode(unsigned int geneticCode) const {
	unsigned int totalValue = 0;
	unsigned int totalSize = 0;
	unsigned int totalWeight = 0;

	// Iterate through each bit of the code
	for(unsigned int i = 0; i < 32; i++) {
		unsigned int wtf = GeneticCode::readBit(geneticCode, i);
		if(wtf == 1) {
			// Include the item
			totalValue += this->items[i].value;
			totalSize += this->items[i].size;
			totalWeight += this->items[i].weight;
		}
	}

	if(totalSize > this->sizeCapacity || totalWeight > this->weightCapacity) {
		return 0;
	}

	return totalValue;
}