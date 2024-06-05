#include <cstring>
using namespace std;
#include <string>

#ifndef RandomEventEasy_h
#define RandomEventEasy_h
#include "RandomEvent.h"

class RandomEasy:public RandomEvent{


public:
RandomEasy();
RandomEasy(string);
void setScenario(string userScenario);
string getScenario();
};
#endif
