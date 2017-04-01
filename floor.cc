#include "floor.h"
#include "subscriptions.h"
#include "subject.h"
#include "shade.h"
#include "ctime"

Floor::Floor( int level, std::string cmd ) 
: level{level}, len{len}, wid{wid}
{
  if ( cmd == "s" || cmd == "S" ) mainChar = new Shade;
  else if ( cmd == "d" || cmd == "D" ) mainChar = new Drow;
  else if ( cmd == "v" || cmd == "V" ) mainChar = new Vampire;
  else if ( cmd == "g" || cmd == "G" ) mainChar = new Goblin;
  else if ( cmd == "t" || cmd == "T" ) mainChar = new Troll;
}

Character* Floor::getMainChar(){ return mainChar; }

void Floor::clearFloor() 
{ 
  theFloor.clear(); 
  theChambers.clear();// leak mem??
  theEnemies.clear(); // leak mem??
}

Floor::~Floor() { clearFloor(); }

void Floor::newTurn()
{
  


}

void Floor::init( int lvl ) 
{ 

//check if clear
  if ( theFloor.size() ) clearFloor();
// make Chambers
  for ( int i = 0; i < 5; ++i )
  {
    Chamber* ch = new Chamber;
    theChambers.emplace_back( ch );
  }
// generate enemies    
  srand( time(NULL) );
  for ( int i = 0; i < 20; ++i ) 
  {
    int rng = rand() % 18; 
    if ( rng < 4 ) 
    {
      Human* ene = new Human;
      theEnemies.emplace_back( ene );
    }
    else if ( rng < 7 )
    {
       Dwarf* ene = new Dwarf;
       theEnemies.emplace_back( ene );
    }
    else if ( rng < 12 ) 
    {
      Halfling* ene = new Halfling;
      theEnemies.emplace_back( ene );
    }
    else if ( rng < 14 )
    {
       Elf* ene = new Elf;
       theEnemies.emplace_back( ene );
    }
    else if ( rng < 16 )
    {
       Orc* ene = new Orc;
       theEnemies.emplace_back( ene );
    }
    else 
    {
      Merchant* ene = new Merchant;
      theEnemies.emplace_back( ene );
    }
  }

//read in stage
  std::ifstream file("stage.txt");
  level = lvl;
  int row = 0;
  int col = 0;
  char cha;
  while ( file.get(cha) ) 
  {
    if (col == 0 ) 
    {
      theFloor.emplace_back();
    }
    if ( col >= 0 && col < 80 )
    {
      Cell *cell = new Cell( cha, row, col ); // leak mem?
      theFloor[row].emplace_back( cell );
      if ( cha == 'A' ) theChambers.at( 0 )->theChamber.emplace_back( cell );
      else if ( cha == 'B' ) theChambers.at( 1 )->theChamber.emplace_back( cell ); 
      else if ( cha == 'C' ) theChambers.at( 2 )->theChamber.emplace_back( cell );
      else if ( cha == 'D' ) theChambers.at( 3 )->theChamber.emplace_back( cell );
      else if ( cha == 'E' ) theChambers.at( 4 )->theChamber.emplace_back( cell ); 
      ++col;
    }
    if ( col == 80 )
    {
      col = 0;
      ++row;
    }
  }
  srand( time(NULL) );
  int q = rand() % 5;
  theChambers.at( q )->placeChar( mainChar );
  
  for ( int i = 0; i < 20; ++i )
  {
    int z = rand() % 5;
    theChambers.at( z )->placeChar( theEnemies.at( i ) );
  }  
}

void Floor::moveEnemies()
{
  int len = theEnemies.size();
  std::cout << "Enemy size " << len << std::endl;
  srand( time(NULL) );
  std::string randPos[8] = {"no", "ea", "we", "so", "nw", "ne", "se", "sw"};
  for ( int i = 0; i < len; ++i )
  {
    int rng = rand() % 8;
    move( theEnemies[i], randPos[rng]);
  }
}

void Floor::move( Character* cp1, std::string direction )
{
  int startRow = cp1->getRow();
  int startCol = cp1->getCol();
  if ( direction == "no" )
  {
    if (cp1->getType() == "player"? theFloor[startRow-1][startCol]->getPmov() : theFloor[startRow-1][startCol]->getEmov()) 
    {  
      theFloor[startRow-1][startCol]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow-1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if ( direction == "nw" )
  {
    if (cp1->getType() == "player"?  theFloor[startRow-1][startCol-1]->getPmov() :  theFloor[startRow-1][startCol-1]->getEmov()) 
    {  
      theFloor[startRow-1][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
       cp1->mutRow(startRow-1);
       cp1->mutCol(startCol-1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if ( direction == "ne" )
  {
    if (cp1->getType() == "player"? theFloor[startRow-1][startCol+1]->getPmov() :  theFloor[startRow-1][startCol+1]->getEmov()) 
    {  
      theFloor[startRow-1][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow-1);
      cp1->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "so")
  {
    if (cp1->getType() == "player"?  theFloor[startRow+1][startCol]->getPmov() :  theFloor[startRow+1][startCol]->getEmov()) 
    {  
      theFloor[startRow+1][startCol]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "se")
  {
    if (cp1->getType() == "player"?  theFloor[startRow+1][startCol+1]->getPmov() :  theFloor[startRow+1][startCol+1]->getEmov()) 
    {  
      theFloor[startRow+1][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow+1);
      cp1->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "sw")
  {
    if (cp1->getType() == "player"?  theFloor[startRow+1][startCol-1]->getPmov() :  theFloor[startRow+1][startCol-1]->getEmov())
    {  
      theFloor[startRow+1][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutRow(startRow+1);
      cp1->mutCol(startCol-1);

      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "ea")
  {
    if (cp1->getType() == "player" ?  theFloor[startRow][startCol+1]->getPmov() :  theFloor[startRow][startCol+1]->getEmov()) 
    {  
      theFloor[startRow][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "we")
  {
    if (cp1->getType() == "player" ?  theFloor[startRow][startCol-1]->getPmov() :  theFloor[startRow][startCol-1]->getEmov()) 
    {  
      theFloor[startRow][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
      cp1->mutCol(startCol-1);
      theFloor[startRow][startCol]->unSet();
    }
  }
}


std::ostream &operator<<(std::ostream &out, const Floor &f) 
{
  for(int row = 0; row < 25; row++)
  {
    for(int col = 0; col < 80; col++) 
    {
      if ( f.theFloor[row][col]->getCp() ) { out << f.theFloor[row][col]->getCp()->getSymbol(); }
      else out << f.theFloor[row][col]->getSymbol();
    }
  }
  out << "Race: "<< f.mainChar->getRace() << " Gold: " << f.mainChar->getGold();
  out << "					Floor " << f.level << std::endl;
  out << "HP: " << f.mainChar->getHP() << std::endl;
  out << "Atk: " << f.mainChar->getAtk() << std::endl;
  out << "Def: " << f.mainChar->getDef() << std::endl;
  
  return out;
}

