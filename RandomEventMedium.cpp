#include <iostream>
#include <string>

using namespace std;

#include "RandomEventMedium.h"

RandomMedium::RandomMedium():RandomEvent(){
  description = "You are unable to start a fire for warmth or cooking. Do you use a little fuel to start a fire or risk not having a fire for a small chance at losing a crewmate? [F to use fuel]";
}

RandomMedium::RandomMedium(string _RDescript):RandomEvent(_RDescript){
}

void RandomMedium::setScenario(string userDescript) {
	userDescript = description;
}

string RandomMedium::getScenario(){
  return description;
}