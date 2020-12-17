#include "genome.h"
Genome::Genome() {
  this->code="";
  this->fitness=INT_MIN;
  this->code_output = "";
}
Genome::Genome(string code){
  this->code=code;
  this->fitness=INT_MAX;
  this->code_output = "";
}
string Genome::getOutput(){
  return this->code_output;
}
string Genome::getCode(){
  return this->code;
}
void Genome::setCode(string code){
  this->code=code;
}
void Genome::setOutput(string output){
  this->code_output=output;
}

double Genome::getFitness(){
  return this->fitness;
}
void Genome::setFitness(double fitness){
  this->fitness = fitness;
}
