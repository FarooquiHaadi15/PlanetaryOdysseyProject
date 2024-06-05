#include <iostream>
#include <string>

using namespace std;

#include "Spaceship.h"

Spaceship::Spaceship(){
  fuel = 250.0;
  capacity = 5;
  crewalive = 5;
}

Spaceship::Spaceship(double _fuel, int _capacity,int _crewalive){
  fuel = _fuel;
  capacity = _capacity;
  crewalive = _crewalive;
  
}

void Spaceship::setFuel(double userFuel) {
	fuel = userFuel;
}

void Spaceship::setCrewCap(int userCap) {
	capacity = userCap;
}

void Spaceship::setCrewAlive(int userCrew) {
	crewalive = userCrew;
}

double Spaceship::getFuel() {
	return fuel;
}

int Spaceship::getCrewCap() {
	return capacity;
}

int Spaceship::getCrewAlive() {
	return crewalive;
}

void Spaceship::PrintShip(){
  cout<<endl;
  cout<<"CURRENT SHIP INFO:"<<endl;
  cout<<"Fuel: "<<fuel<<endl;
  cout<<"Crew Capacity: "<<capacity<<endl;
  cout<<"Crew Members ALive: "<<crewalive<<endl;
}





