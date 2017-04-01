#include "floor.h"
#include "subscriptions.h"
#include "subject.h"
#include "shade.h"
#include "ctime"

Floor::Floor( int level, std::string cmd ) 
: level{level}, len{len}, wid{wid}, mainChar{mainChar}
{
  if ( cmd == "s" || cmd == "S" ) mainChar = new Shade;
  else if ( cmd == "d" || cmd == "D" ) mainChar = new Drow;
  else if ( cmd == "v" || cmd == "V" ) mainChar = new Vampire;
  else if ( cmd == "g" || cmd == "G" ) mainChar = new Goblin;
  else if ( cmd == "t" || cmd == "T" ) mainChar = new Troll;
}

void Floor::clearFloor() 
{ 
  theFloor.clear(); 
  theChambers.clear();// leak mem??
  theCharacters.clear(); // leak mem??
}

Floor::~Floor() { clearFloor(); }

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
      theCharacters.emplace_back( ene );
    }
    else if ( rng < 7 )
    {
       Dwarf* ene = new Dwarf;
       theCharacters.emplace_back( ene );
    }
    else if ( rng < 12 ) 
    {
      Halfling* ene = new Halfling;
      theCharacters.emplace_back( ene );
    }
    else if ( rng < 14 )
    {
       Elf* ene = new Elf;
       theCharacters.emplace_back( ene );
    }
    else if ( rng < 16 )
    {
       Orc* ene = new Orc;
       theCharacters.emplace_back( ene );
    }
    else 
    {
      Merchant* ene = new Merchant;
      theCharacters.emplace_back( ene );
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
    theChambers.at( z )->placeChar( theCharacters.at( i ) );
  }  
}

void Floor::move( std::string direction)
{
  int startRow = mainChar->getRow();
  int startCol = mainChar->getCol();
  if ( direction == "no" )
  {
    if ( theFloor[startRow-1][startCol]->getPmov() )
    {  
      theFloor[startRow-1][startCol]->set( theFloor[startRow][startCol]->getCp() );
      mainChar->mutRow(startRow-1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if ( direction == "nw" )
  {
    if ( theFloor[startRow-1][startCol-1]->getPmov() )
    {  
      theFloor[startRow-1][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
       mainChar->mutRow(startRow-1);
       mainChar->mutCol(startCol-1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if ( direction == "ne" )
  {
    if ( theFloor[startRow-1][startCol+1]->getPmov() )
    {  
      theFloor[startRow-1][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      mainChar->mutRow(startRow-1);
      mainChar->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "so")
  {
    if ( theFloor[startRow+1][startCol]->getPmov() )
    {  
      theFloor[startRow+1][startCol]->set( theFloor[startRow][startCol]->getCp() );
       mainChar->mutRow(startRow+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "se")
  {
    if ( theFloor[startRow+1][startCol+1]->getPmov() )
    {  
      theFloor[startRow+1][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
     mainChar->mutRow(startRow+1);
     mainChar->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "sw")
  {
    if ( theFloor[startRow+1][startCol-1]->getPmov() )
    {  
      theFloor[startRow+1][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
  mainChar->mutRow(startRow+1);
 mainChar->mutCol(startCol-1);

      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "ea")
  {
    if ( theFloor[startRow][startCol+1]->getPmov() )
    {  
      theFloor[startRow][startCol+1]->set( theFloor[startRow][startCol]->getCp() );
      mainChar->mutCol(startCol+1);
      theFloor[startRow][startCol]->unSet();
    }
  }
  else if (direction == "we")
  {
    if ( theFloor[startRow][startCol-1]->getPmov() )
    {  
      theFloor[startRow][startCol-1]->set( theFloor[startRow][startCol]->getCp() );
      mainChar->mutCol(startCol-1);
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
  out << "				Floor " << f.level << std::endl;
  out << "HP: " << f.mainChar->getHP() << std::endl;
  out << "Atk: " << f.mainChar->getAtk() << std::endl;
  out << "Def: " << f.mainChar->getDef() << std::endl;
  
  return out;
}

