#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include "chamber.h"
#include "cell.h"
#include "character.h"
#include <string>
#include <fstream>
#include "posn.h"

class Floor 
{ 
  std::vector<std::vector<Cell*>> theFloor;
  std::vector<Chamber*> theChambers;
  std::vector<Character*> theCharacters;
  int level, len, wid;
  
  Character* mainChar;

  public:
  
  Floor( int lvl, std::string cmd );
  ~Floor();
  void clearFloor();
  void move( std::string direction );
  void init( int lvl );
//  void set(int r, int c, Character* pc1 );
  


  friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
