#include "interpreter.h"
Interpreter::Interpreter(){
  this->console_output="";
  this->instruction_limit=150;
}
void Interpreter::flushConsole(){
  this->console_output="";
  cout<<"console_output is flushed"<<endl;
}
void Interpreter::setInstructionLimit(int inst_limit){
this->instruction_limit = inst_limit;
}
string Interpreter::interpretCode(const std::string& commands)
  {
    std::vector<int> data(1, 0);
    std::vector<int>::iterator dataPtr = data.begin();

    std::string::const_iterator instructionPtr = commands.begin();
    std::stack<std::string::const_iterator> instructionStack;
    int inst_exe=0;
    while ((instructionPtr != commands.end()) && (inst_exe++ < this->instruction_limit) )
    {
        switch (*instructionPtr)
        {
        case '<':
        {   if(dataPtr == data.begin()){
            dataPtr=data.end()-1;
            break;
          }
            dataPtr--;
            break;
        }
        case '>':
        {
            dataPtr++;
            if (dataPtr == data.end()) {
                data.push_back(0);
                dataPtr = data.end()-1;
            }
            break;
        }
        case '+':
        {
            (*dataPtr) += 1;
            break;
        }
        case '-':
        {
            (*dataPtr) -= 1;
            break;
        }
        case '.':
        {
            this->console_output.push_back(char(*dataPtr));
            break;
        }
        case ',':
        {
            char input;
            std::cin >> input;
            *dataPtr = input;
        }
        case '[':
        {
            instructionStack.push(instructionPtr);

            if (*dataPtr == 0)
            {
                auto startInstructionPtr = instructionPtr;
                while (++instructionPtr != commands.end())
                {
                    if (*instructionPtr == '[')
                        instructionStack.push(instructionPtr);
                    else if (*instructionPtr == ']')
                    {
                        if (instructionStack.empty()){
                          return this->console_output;
                            // throw std::runtime_error("Found a ']' that did not have a matching '['!");
                          }

                        auto tempInstructionPtr = instructionStack.top();
                        instructionStack.pop();

                        if (startInstructionPtr == tempInstructionPtr)
                            break;
                    }
                }
            }
            break;
        }
        case ']':
        {
            if (instructionStack.empty()){
              return this->console_output;
                // throw std::runtime_error("Found a ']' that did not have a matching '['!");
              }
            if (*dataPtr != 0)
                instructionPtr = instructionStack.top();
            else
                instructionStack.pop();

            break;
        }
        default:
            break;
        }

        instructionPtr++;
    }

    if (!instructionStack.empty()){
      return this->console_output;
        // throw std::runtime_error("Found a '[' that did not have a matching ']'!");
      }
      // free(instructionPtr);
return this->console_output;
}
