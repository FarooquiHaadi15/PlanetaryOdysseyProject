#include <iostream>
#include <cstring>
using namespace std;

#ifndef Planet_h
#define Planet_h

class Planet{
protected:
string name;
string description;
double fuelreq;
int hostility;

public:
Planet();
Planet(string,string,double, int);
void setName(string);
void setDescription(string);
void setFuelReq(double);
void setHostility(int);
string getName();
string getDescription();
double getFuelReq();
int getHostility();
void PrintP();
};

#endif