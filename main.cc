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
  
  Floor *floor = new Floor( 2, "s" );
  floor->init( 1 );
  std::cout << *floor;
  std::string s;
  while(std::cin >> s){
  floor->move(s);
  std::cout << *floor;
}
}
 
