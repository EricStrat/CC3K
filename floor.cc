#include "floor.h"
#include "subscriptions.h"
#include "subject.h"
using namespace std;

Floor::Floor( int lv ) : td{nullptr},  {}

Floor::~Floor() { clearFloor(); }

void Floor::clearFloor() 
{ 
  theFloor.clear();
  delete td;
}

void Floor::init() 
{ 
  if ( td ) clearFloor();
  ifstream file("stage.txt");
  int row = 0;
  int col = 0;
  char cha;
  while (file.get(cha)) {
    if (col == 0 ) 
    {
        theFloor.emplace_back();
    }
		if (col >= 0 && col < 80){
			theFloor[row].emplace_back( Cell( cha, row, col ));
			col++;
		}
		if (col == 80){
			col = 0;
			row++;
		}
	}
}

void Floor::setCell(int r, int c, character *pc1 ) { theFloor[r][c].cp = pc1; }
void Floor::move( int startRow, int startCol, std::string direction)
{
  if (direction == "no")
  {
    if ( theFloor[startRow-1][startCol].getPmov() )
    {  
      theFloor[startRow-1][startCol].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
  else if (direction == "nw")
  {
    if ( theFloor[startRow-1][startCol-1].getPmov() )
    {  
      theFloor[startRow-1][startCol-1].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
  else if (direction == "ne")
  {
    if ( theFloor[startRow-1][startCol+1].getPmov() )
    {  
      theFloor[startRow-1][startCol+1].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
  else if (direction == "so")
  {
    if ( theFloor[startRow+1][startCol].getPmov() )
    {  
      theFloor[startRow+1][startCol].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
  else if (direction == "se")
  {
    if ( theFloor[startRow+1][startCol+1].getPmov() )
    {  
      theFloor[startRow+1][startCol+1].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
  else if (direction == "sw")
  {
    if ( theFloor[startRow+1][startCol-1].getPmov() )
    {  
      theFloor[startRow+1][startCol-1].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
  else if (direction == "ea")
  {
    if ( theFloor[startRow][startCol+1].getPmov() )
    {  
      theFloor[startRow][startCol+1].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
  else if (direction == "we")
  {
    if ( theFloor[startRow][startCol-1].getPmov() )
    {  
      theFloor[startRow][startCol-1].set( theFloor[startRow][startCol].getPc() );
      theFloor[startRow][startCol].unSet();
    }
  }
}

ostream &operator<<(ostream &out, const Floor &f) 
{
  out << *f.td;
  return out;
}
