#include<bits/stdc++.h>
using namespace std;
class Interpreter{
private:
  string console_output;
  int instruction_limit;
public:
  Interpreter();
  string interpretCode(const std::string& commands);
  void flushConsole();
  void setInstructionLimit(int inst_limit);
};
