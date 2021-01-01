#include <vector>

using namespace std;


namespace GeneticCode {
	unsigned int readBit(unsigned int geneticCode, unsigned int index){
		return (geneticCode >> (31 - index)) % 2;
	}

	void writeBit(unsigned int& geneticCode, unsigned int index, unsigned int value){
		unsigned int mask = ~(1 << (31 - index));
		geneticCode = mask & geneticCode;
		geneticCode += value << (31 - index);
	}
}