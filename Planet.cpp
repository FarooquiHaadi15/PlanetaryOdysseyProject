#include <iostream>
#include <string>

using namespace std;

#include "Planet.h"

Planet::Planet(){
  name = "Unknown";
  description = "N/A";
  fuelreq = 0;
  hostility = 0;
}

Planet::Planet(string _name, string _description, double _fuelreq, int _hostility){
  name = _name;
  description = _description;
  fuelreq = _fuelreq;
  hostility = _hostility;
}

void Planet::setName(string Pname) {
	name = Pname;
}

void Planet::setDescription(string Pdescription) {
	description = Pdescription;
}

void Planet::setFuelReq(double Preq) {
	fuelreq = Preq;
}

void Planet::setHostility(int Phostility) {
	hostility = Phostility;
}

string Planet::getName(){
  return name;
}

string Planet::getDescription(){
  return description;
}

double Planet::getFuelReq(){
  return fuelreq;
}

int Planet::getHostility(){
  return hostility;
}

void Planet::PrintP(){
  cout<<endl;
  cout<<getName()<<" PLANET INFO:"<<endl;
  cout<<"Description: "<<getDescription()<<endl;
  cout<<"Fuel Requirement: "<<getFuelReq()<<endl;
  cout<<"Hostility "<<getHostility()<<endl;
}