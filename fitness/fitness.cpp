#include "fitness.h"

int Fitness::getFitness(string desired_output, string output){
  int desired_fitness=0;
  for(int i=0;i<desired_output.size();i++){
      desired_fitness+=256
  }
  int fitness=0;
  for(int i=0;i<desired_output.size();i++){
    if(output.size()>i){
      fitness+=256- abs((int)output[i]-(int)desired_output[i]);
    }
  }
  int dl=(int)desired_output.size();
  int ol=(int)output.size();
  fitness+=10*((dl-abs(dl-ol))/dl);
  return abs(desired_fitness-fitness);
}
