#include<bits/stdc++.h>
// #include "genome/genome.h"
#include "GA/GA.h"
#include "interpreter/interpreter.h"
#include "fitness/fitness.h"
using namespace std;

int main(){
  string desired_output="hi";
  // Genome g1=Genome(code);
  // g1.setOutput(output);
  // cout<<g1.getCode();
  // cout<<g1.getOutput();
  GA ga=GA();
  Genome * population;
  Genome * newPop;
  Fitness fitness = Fitness();
  population=ga.getPop();
  Interpreter interpreter = Interpreter();
  for(int i=0;i<100;i++){
    string current_code = population[i].getCode();
    // cout<<"current_code: "<<current_code<<endl;
    population[i].setOutput(interpreter.interpretCode(current_code));
    // cout<<"current_code output: "<<population[i].getOutput()<<endl;
    interpreter.flushConsole();
    population[i].setFitness(fitness.getFitness(desired_output,population[i].getOutput()));
    // cout<<"fitness: "<<population[i].getFitness()<<endl;
  }
  ga.generateNextGen(population);
  newPop = ga.getNextGen();
  for(int i=0;i<100;i++){
    string current_code = newPop[i].getCode();
    int fitness = newPop[i].getFitness();
    cout<<current_code<<"\n"<<fitness<<endl;
  }
}
