#include <iostream>
#include <cstring>
using namespace std;

#ifndef Spaceship_h
#define Spaceship_h

class Spaceship{
private:
double fuel;
int capacity;
int crewalive;

public:
Spaceship();
Spaceship(double, int,int);
void setFuel(double);
void setCrewCap(int);
void setCrewAlive(int);
double getFuel();
int getCrewCap();
int getCrewAlive();
void PrintShip();
};

#endif
