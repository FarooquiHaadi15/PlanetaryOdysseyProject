#include <iostream>
#include <string>

using namespace std;

#include "RandomEvent.h"

RandomEvent::RandomEvent(){
  description = "Unknown";
}

RandomEvent::RandomEvent(string _RDescript){
  description =_RDescript;
}

void RandomEvent::setEventDescription(string userDescript) {
	userDescript = description;
}

string RandomEvent::getEventDiscription(){
  return description;
}

void RandomEvent::printChoices(){
  cout<<"Continue event? [type 'yes' to continue, or 'leave' to turn back]."<<endl;
}







