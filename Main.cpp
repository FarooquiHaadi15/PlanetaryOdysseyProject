#include <iostream>
#include<string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "Planet.h"
#include "Spaceship.h"
#include "RandomEventEasy.h"
#include "RandomEventMedium.h"
#include "RandomEventHard.h"
using namespace std;

int main() {
  srand(time(NULL));
  
//CHECK IF USER WANTS TO LOAD OR START NEW GAME AND CHECK IF FILE NAME IS CORRECT

Spaceship Odysseous;
Odysseous = Spaceship();
int crewcap = Odysseous.getCrewCap();
int crewalive;
double fuel = Odysseous.getFuel();
char key;
  
  cout<<"Would you like to load the names of previous successful crews or begin your adventure? [type load or new]?"<<endl;
  string fileHandle;
  cin>>fileHandle;
  ifstream inFS;
  
  if(fileHandle == "new"){ 
    cout<<"New Game starting!"<<endl;
  }else if(fileHandle == "load"){
    cout<<"Enter file name:"<<endl;    
  string filename;  
  cin>>filename;
   inFS.open(filename);
    cout<<"Here is the previous crew that completed the challenge before you!"<<endl;    
    while(!inFS.eof()){
    string out;
      getline(inFS,out);
      cout<<out<<endl;
      
    }
    if (!inFS.is_open()) {
      cout << "File not found." << endl;
      return 1;
    
  }
  inFS.close();
  }
    
  
  ofstream outFS;
  outFS.open("loadfile.txt");
   

  
  //GAME STARTING HERE--------------------------------------------------------
  cout<<"WELCOME TO PLANETARY ODYSSEY."<<endl<<"You are the captain of your very own space crew! You are in charge of every decision that the team makes in each mission."<<endl<<"It is your goal to explore each of the planets, survive, and report back to HQ with your findings."<<endl<<"Let's begin!"<<endl<<"We will assign you your ship now - The Odysseous"<<endl;

cout<<"As your starter ship, Odysseous has a fuel capacity of "<<Odysseous.getFuel()<<" and a crew capacity of "<<Odysseous.getCrewCap()<<endl;


cout<<"You can bring have up to 5 crewmates. How many do you want?"<<endl;
cin>>crewalive;
while(crewalive>5||crewalive<=0){
  cout<<"Invalid number of crewmates. You can bring have up to 5 crewmates. How many do you want?";
  cin>>crewalive;
}
cin.ignore();
Odysseous.setCrewAlive(crewalive);

  string *arr = new string[crewalive];
  for(int i =0; i<crewalive;i++){
    cout<<"Enter crewmate name "<<i+1<<endl;
    getline(cin,arr[i]);
  }
  for(int i =0;i<crewalive;i++){
    cout<<"Crewmate #"<<i+1<<": "<<arr[i]<<endl;
  }






bool Starter=false;
bool ExploredRed = false;
bool ExploredRocky = false;
bool ExploredGas = false;
bool ExploredForest = false;
int NLEFT = 5;

cout<<"In order to become acquainted with your crew, your first mission will be at 'level 0'"<<endl;
  cout<<"This planet has already been explored by others and has no danger whatsoever, however, this will be a good place to test your skills and decision making abilities"<<endl;

  cout<<"Press any key and then enter to continue"<<endl;
  cin>>key;
  cout<<endl;
Planet StarterP;
  StarterP.setName("ERD-108");
  StarterP.setDescription("A calm planet with pleasant weather");
  StarterP.setHostility(1);
  StarterP.setFuelReq(5.0);

  cout<<"STARTER MISSION"<<endl<<"Planet Description: "<<endl<<"Name: "<<StarterP.getName()<<endl<<"Description: "<<StarterP.getDescription()<<endl<<"Hostility Level: "<<StarterP.getHostility()<<endl<<"Fuel Requirement: "<<StarterP.getFuelReq()<<endl;

  Odysseous.setFuel(fuel - StarterP.getFuelReq());
  Odysseous.PrintShip();
cout<<"Welcome to "<<StarterP.getName()<<" ! We will be landing shortly..."<<endl;
  int RNG;
  RandomEasy Easy;
  RandomMedium Medium;
  RandomHard Hard;

  cout<<"At each planet, there will be a random chance of an event happening. It is up to YOU to decide to go through with an event or back away."<<endl<<"Your first night on ERD begins now..."<<endl<<endl;

//------------------------------------------------------------Starter Planet
 

    cout<<"A STRANGER HAS APPEARED and wants you to follow him to an oasis of possible fuel sources. Do you follow him? [Enter Y for yes or any other key followed by 'enter' to ignore]"<<endl;
    cin>>key;
  cout<<endl;
    if(key=='Y'){
      cout<<"You chose to be trusting... and the stranger was telling the truth! You were able to add additional fuel to your ship."<<endl;
      Odysseous.setFuel(fuel + (rand()%50));
      Odysseous.PrintShip();
      cout<<endl;
    }else{
      cout<<"You chose to stay on your feet and not trust the stranger."<<endl;
      Odysseous.PrintShip();
    }
  
cout<<"After surviving a night on ERD you and your crew are ready to explore the galaxy together!"<<endl<<endl;
cout<<"Enter any key to continue"<<endl;
cin>>key;
cout<<endl;
Starter = true;
  NLEFT = NLEFT-1;

//---------------------------------------------------Planet List

Planet Red;
  Red.setName("MRS-204");
  Red.setDescription("A flat planet, with little atmosphere SPACE SUITS MUST BE WARN AT ALL TIMES");
  Red.setHostility(2);
  Red.setFuelReq(28.0);
  
Planet Rocky;
  Rocky.setName("PLUT-326");
  Rocky.setDescription("A desolate planet, nothing known except that it is cold, mountaneous and devoid of intelligent life");
  Rocky.setHostility(3);
  Rocky.setFuelReq(30.0);
  
Planet Gas;
  Gas.setName("SAT-487");
  Gas.setDescription("A planet with a thin solid film to walk on. Be light on your feet or you may break the film and fall through SPACE SUITS MUST BE WARN AT ALL TIMES");
  Gas.setHostility(4);
  Gas.setFuelReq(48);
  
Planet Forest;
  Forest.setName("DRE-404");
  Forest.setDescription("A world similar to Planet ERD except no one has made it back to HQ alive from here...");
  Forest.setHostility(5);
  Forest.setFuelReq(60);

cout<<endl<<"Choose a planet for your first mission!"<<endl<<"Your choices are as follows:"<<endl<<endl;
  Red.PrintP();
  Rocky.PrintP();
  Gas.PrintP();
  Forest.PrintP();

  do {
    if(fuel<0){
        cout<<"Mission Failed! You ran out of fuel..."<<endl;
        return 1;
    }else if(crewalive==0){
      cout<<"Mission Failed! No crew remains..."<<endl;
    }
    cout<<"Select your next planet [To make a choice type 'Red', 'Rocky', 'Gas', and 'Forest'] YOU ARE FREE TO REVISIT PLANETS UNTIL YOU HAVE VISITED ALL OF THEM ONCE:"<<endl;
    string choice;
    cin>>choice;
    
//---------------------------------------------------Choosing RedPlanet
    if(choice == "Red"){
      if(ExploredRed == false){
        ExploredRed = true;
        NLEFT = NLEFT-1;
      }
      fuel = Odysseous.getFuel();
      Odysseous.setFuel(fuel - Red.getFuelReq());
      Odysseous.PrintShip();
      fuel = Odysseous.getFuel();
      
      cout<<"Heading out to "<<Red.getName()<<endl;
      int Nevents = 0;
      for(int i =2;Nevents<i;Nevents++){
        int RRNG = rand()%Red.getHostility();
        int LRNG = rand()%Red.getHostility();
        
  if(RRNG==0){
        cout<<"Night "<<Nevents<< " was a calm night"<<endl;
  }else if(RRNG == 1){
      cout<<Easy.getScenario();
      cin>>key;
      cout<<endl;
      if(LRNG == 1&&key == 'Y'){
        cout<<"You were awarded with fuel and food"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel + 10);
        Odysseous.PrintShip();
        }else if (LRNG == 0&&key == 'Y'){
        cout<<"You were robbed while following the stranger"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel - 10);
        Odysseous.PrintShip();
        }else{
        cout<<"Scenario avoided"<<endl;
        Odysseous.PrintShip();
        }
  }
          } 
          }
            
          
        
//----------------------------------------------------------------End Planet Red
    if(choice == "Rocky"){
      if(ExploredRocky == false){
        ExploredRocky = true;
        NLEFT = NLEFT-1;
      }
      fuel = Odysseous.getFuel();
      Odysseous.setFuel(fuel - Rocky.getFuelReq());
      fuel = Odysseous.getFuel();
      Odysseous.PrintShip();
      int Nevents = 0;
      for(int i =3;Nevents<i;Nevents++){
        int RRNG = rand()%Rocky.getHostility();
        int LRNG = rand()%Rocky.getHostility();
       if(RRNG==0){
        cout<<"Night "<<Nevents<< " was a calm night"<<endl;
  }else if(RRNG == 1){
      cout<<Easy.getScenario();
      cin>>key;
      cout<<endl;
      if(LRNG == 1&&key == 'Y'){
        cout<<"You were awarded with fuel and food"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel + 10);
        fuel = Odysseous.getFuel();
        Odysseous.PrintShip();
        }else if (LRNG == 0&&key == 'Y'){
        cout<<"You were robbed while following the stranger"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel - 10);
        Odysseous.PrintShip();
        }else{
        cout<<"Scenario avoided"<<endl;
        Odysseous.PrintShip();
        }
  }else if(RRNG == 2){
            cout<<Medium.getScenario();
            cin>>key;
          if(key=='F'){
            cout<<"Fuel sacrificed, but everyone is safe!"<<endl;
            fuel = Odysseous.getFuel();
            Odysseous.setFuel(fuel - 10);
            fuel = Odysseous.getFuel();
            Odysseous.PrintShip();
          }
          } 
          }
            
          
          }
//--------------------------------------------------------------End Planet Rocky
    if(choice == "Gas"){
      if(ExploredGas == false){
        ExploredGas = true;
        NLEFT = NLEFT-1;
      }
      fuel = Odysseous.getFuel();
      Odysseous.setFuel(fuel - Gas.getFuelReq());
      fuel = Odysseous.getFuel();
      Odysseous.PrintShip();
      int Nevents = 0;
      for(int i =3;Nevents<i;Nevents++){
        int RRNG = rand()%Gas.getHostility();
        int LRNG = rand()%Gas.getHostility();
        int BRNG = rand()%2;
       if(RRNG==0){
        cout<<"Night "<<Nevents<< " was a calm night"<<endl;
  }else if(RRNG == 1){
      cout<<Easy.getScenario();
      cin>>key;
      cout<<endl;
      if(BRNG == 1&&key == 'Y'){
        cout<<"You were awarded with fuel and food"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel + 10);
        fuel = Odysseous.getFuel();
        Odysseous.PrintShip();
        }else if (BRNG == 0&&key == 'Y'){
        cout<<"You were robbed while following the stranger"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel - 10);
        fuel = Odysseous.getFuel();
        Odysseous.PrintShip();
        }else{
        cout<<"Scenario avoided"<<endl;
        Odysseous.PrintShip();
        }
  }else if(RRNG == 2){
            cout<<Medium.getScenario();
            cin>>key;
          if(key=='F'){
            cout<<"Fuel sacrificed, but everyone is safe!"<<endl;
            fuel = Odysseous.getFuel();
            Odysseous.setFuel(fuel - 10);
            fuel = Odysseous.getFuel();
            Odysseous.PrintShip();
          }
       }
  else if(RRNG == 3){
            cout<<Hard.getScenario();
            cin>>key;
          if(key=='S'){
            cout<<"A crew member was sacrificed..."<<endl;
            Odysseous.setCrewAlive(crewalive-1);
            crewalive = Odysseous.getCrewAlive();
            Odysseous.PrintShip();
          }else if(key=='F'){
            cout<<"The fight begins..."<<endl;
            if(LRNG<2){
              cout<<"The fight is won, but we suffered a casualty"<<endl;
              Odysseous.setCrewAlive(crewalive-1);
            crewalive = Odysseous.getCrewAlive();
            Odysseous.PrintShip();              
            }else{
              cout<<"Flawless victory."<<endl;
              Odysseous.PrintShip();                 
            }
          }
          } 
          }
    }
//---------------------------------------------------------------End of Gas
    if(choice == "Forest"){
      if(ExploredForest == false){
        ExploredForest = true;
        NLEFT = NLEFT-1;
      }
      fuel = Odysseous.getFuel();
      Odysseous.setFuel(fuel - Gas.getFuelReq());
      fuel = Odysseous.getFuel();
      Odysseous.PrintShip();
      int Nevents = 0;
      for(int i =4;Nevents<i;Nevents++){
        int RRNG = rand()%Forest.getHostility();
        int LRNG = rand()%Forest.getHostility();
        int BRNG = rand()%2;
       if(RRNG==0){
        cout<<"Night "<<Nevents<< " was a calm night"<<endl;
  }else if(RRNG == 1){
      cout<<Easy.getScenario();
      cin>>key;
      cout<<endl;
      if(BRNG == 1&&key == 'Y'){
        cout<<"You were awarded with fuel and food"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel + 10);
        fuel = Odysseous.getFuel();
        Odysseous.PrintShip();
        }else if (BRNG == 0&&key == 'Y'){
        cout<<"You were robbed while following the stranger"<<endl;
        fuel = Odysseous.getFuel();
        Odysseous.setFuel(fuel - 10);
        Odysseous.PrintShip();
        }else{
        cout<<"Scenario avoided"<<endl;
        Odysseous.PrintShip();
        }
  } else if(RRNG <=3){
            cout<<Hard.getScenario();
            cin>>key;
          if(key=='S'){
            cout<<"A crew member was sacrificed..."<<endl;
            Odysseous.setCrewAlive(crewalive-1);
            crewalive = Odysseous.getCrewAlive();
            Odysseous.PrintShip();
          }else if(key=='F'){
            cout<<"The fight begins..."<<endl;
            if(LRNG<=3){
              cout<<"The fight is won, but we suffered a casualty"<<endl;
              Odysseous.setCrewAlive(crewalive-1);
            crewalive = Odysseous.getCrewAlive();
            Odysseous.PrintShip();              
            }else{
              cout<<"Flawless victory."<<endl;
              Odysseous.PrintShip();                 
            }
          }
          } 
          }
    }
//---------------------------------------------------------------End of Forest
    
    
    
    }//Closes DO loop   
      
    
  
    while (NLEFT!=0);

  if(Odysseous.getCrewAlive()==00||Odysseous.getFuel()==0){
    cout<<"Mission failed, we either lost all fuel or all crew members"<<endl;
  }else{
cout<<"CONGRATULATIONS YOU HAVE SUCCESSFULLY REPORTED TO HQ. Your work will never be forgotten!"<<endl;
  }
    cout<<"Would you like to save your crew names?[Type 'Y' if yes]"<<endl;
    cin>>key;
    if(key=='Y'){
     for(int i =0;i<crewalive;i++){
    outFS<<"Crewmate #"<<i+1<<": "<<arr[i]<<endl;
       cout<<"Crewmate # "<<i+1<<" SAVED! "<<arr[i]<<endl;
       
  } 
    }
outFS.close();
  
   

}
