#ifndef GENETIC_CODE_H
#define GENETIC_CODE_H

namespace GeneticCode {
	unsigned int readBit(unsigned int geneticCode, unsigned int index);

	void writeBit(unsigned int& geneticCode, unsigned int index, unsigned int value);
}

#endif