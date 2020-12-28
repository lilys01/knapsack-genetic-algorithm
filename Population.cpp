#include "Population.h"
#include "Knapsack.h"
#include <queue>
#include <tuple>
#include <stdlib.h>
#include <time.h>
using namespace std;

unsigned int readBit(unsigned int geneticCode, unsigned int index){
  return (geneticCode >> (31 - index)) % 2;
}

void writeBit(unsigned int& geneticCode, unsigned int index, unsigned int value){
  unsigned int mask = ~(1 << (31 - index));
  geneticCode = mask & geneticCode;
  geneticCode += value << (31 - index);
}

unsigned int Population::newGeneration(){
  vector<unsigned int> n(this->size);
  tuple<unsigned int, unsigned int> parents;
  vector<unsigned int> parentGen = this->geneticCodes.back();
  srand(time(NULL)); //random number generator

  while(n.size() < this->size){
    //tournament selection for 2 parents
    for(unsigned int i = 0; i < 2; i++){
      priority_queue<tuple<unsigned int, unsigned int>> pq;
      //add codes for tournament to pq
      for(unsigned int j = 0; j < this->tournamentSize; j++){
         unsigned int index = rand() % parentGen.size();
         unsigned int fitness = this->knapsack.evaluateCode(parentGen[index]);
         pq.push(make_tuple(fitness, parentGen[index]));
      }
      get<i>(parents) = pq.top();
    }
    //make new generation from parents
    for(unsigned int i = 0; i < 2, i++){
      unsigned int child = 0;
      for(unsigned int j = 0; j < 32; j++){
        //crossover
        unsigned int parent = get<(rand() % 2)>(parents);
        unsigned int trait = readBit(parent, j);

        //mutation
        if(((double)rand() / RAND_MAX) < this->mutationRate){
           trait = trait ^ 1;
        }
        writeBit(child, j, trait);
      }
      n.push_back(child); 
    }
  }
  geneticCodes.push_back(n);
}
