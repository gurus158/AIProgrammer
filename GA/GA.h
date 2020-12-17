#include<bits/stdc++.h>
#include "../genome/genome.h"
using namespace std;

class GA{
private:
  Genome pop[100];
  Genome nextPop[100];
  Genome best;
public:
  char alphabets[8] = "><+-.[]";
  // void generateRandomPop();
  GA();
  // GA(Genome pop[]);
  // void setFitness();
  // void setFitness(Genome genome);
  // Genome getBestGenome();
  Genome * getPop();
  void generateNextGen(Genome * population);
  Genome * getNextGen();
};
