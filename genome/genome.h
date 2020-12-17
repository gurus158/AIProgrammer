#include<bits/stdc++.h>
using namespace std;
class Genome{
private:
  string code ;
  double fitness;
  string code_output;
public:
  Genome(string code);
  Genome();
  string getOutput();
  string getCode();
  void setCode(string code);
  void setOutput(string output);
  double getFitness();
  void setFitness(double fitness);
};
