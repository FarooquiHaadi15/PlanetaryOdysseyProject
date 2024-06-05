#include <iostream>
#include <string>

using namespace std;

#include "RandomEventHard.h"

RandomHard::RandomHard():RandomEvent(){
  description = "You're under attack! Your assailants are armed and dangerous, do you offer a sacrifice and live? or stand to fight and take a chance?  [S if you want to Sacrifice, F if you want to fight]";
}

RandomHard::RandomHard(string _RDescript):RandomEvent(_RDescript){
}

void RandomHard::setScenario(string userDescript) {
	userDescript = description;
}

string RandomHard::getScenario(){
  return description;
}