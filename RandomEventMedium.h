#include <cstring>
using namespace std;
#include <string>

#ifndef RandomEventMedium_h
#define RandomEventMedium_h
#include "RandomEvent.h"

class RandomMedium:public RandomEvent{


public:
RandomMedium();
RandomMedium(string);
void setScenario(string userScenario);
string getScenario();
};
#endif