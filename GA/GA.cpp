#include "GA.h"

GA::GA(){
  srand((unsigned) time(0));

  for(int i=0;i<100;i++){
    string code="";
    for(int j=0;j<50;j++){
          code.push_back(this->alphabets[rand()%7]);
    }
    this->pop[i].setCode(code);
  }
}
// GA::GA(Genome pop[]){
//
// }
// void GA::setFitness(){
//
// }
// void GA::setFitness(Genome genome){
//
// }
// Genome GA::getBestGenome(){
//
// }


Genome * GA::getPop(){
return this->pop;
}
bool sortByVal(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}
void GA::generateNextGen(Genome * population){
  // Genome nexPop[100];
  map<int,int> indexFitnessMap;
  for(int i=0;i<100;i++){
    indexFitnessMap[i]=population[i].getFitness();
  }
  vector<pair<int,int>> tvec;
  map<int,int>::iterator it;
  for(it=indexFitnessMap.begin();it!=indexFitnessMap.end();it++){
    tvec.push_back(make_pair(it->first,it->second));
  }
  sort(tvec.begin(),tvec.end(),sortByVal);
  for(int i=0;i<tvec.size();i++){
    // cout<<tvec[i].second<<endl;
    Genome gn = population[tvec[i].first];
    this->nextPop[i]=gn;
    // cout<<gn.getCode()<<"\n"<<gn.getFitness()<<endl;
  }
  // return this->nextPop;
}
Genome * GA::getNextGen(){
  return this->nextPop;
}


// void GA::generateRandomPop(){
//
// }
