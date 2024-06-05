#include <cstring>
using namespace std;
#include <string>

#ifndef RandomEventHard_h
#define RandomEventHard_h
#include "RandomEvent.h"

class RandomHard:public RandomEvent{


public:
RandomHard();
RandomHard(string);
void setScenario(string userScenario);
string getScenario();
};
#endif