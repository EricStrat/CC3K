#include "character.h"
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "cell.h"
#include "floor.h"
int main() 
{
  std::string str;
  std::cout << "Choose your race" << std::endl;
  std::cout << "(S)hade, (D)row, (V)ampire, (T)roll, (G)oblin" << std::endl;
  std::string cmd;
  std::cin >> cmd;
  while(true){
  if (cmd == "s" || cmd == "S" || cmd == "D" || cmd == "d" || cmd == "V" || cmd == "v" || cmd == "T" || cmd == "t" || cmd == "G" || cmd == "g") 
  { 
    Floor *floor = new Floor( 2, cmd );
    break;;
  }
  else {
  std::cout << "Try again" << std::endl;
  std::cin.ignore();
  std::cin.clear();
}
}
  floor->init( 1 );
  std::cout << *floor;
  std::string s;
  while(std::cin >> s){
  floor->move(s);
  std::cout << *floor;
}
}
 
