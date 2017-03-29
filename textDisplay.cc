#include "iostream"
#include "ifstream"
#include "texDisplay.h"

TextDisplay::TextDisplay()
{
  for ( int i = 0; i < n; ++i )
  {
    vector<char> c;
    theDisplay.emplace_back( c );
    for ( int j = 0; j < n; ++j )
    {
      theDisplay.at( i ).emplace_back( '_' ) ;
    }
  }
}

void TextDisplay::notify(Subject &whoNotified)
{
  if ( theDisplay.at( whoNotified.getInfo().row ).at( whoNotified.getInfo().col ) == 'X' )
  {
    theDisplay.at( whoNotified.getInfo().row ).at( whoNotified.getInfo().col ) = '_';
  }
  else theDisplay.at( whoNotified.getInfo().row ).at( whoNotified.getInfo().col ) = 'X';
}

TextDisplay::~TextDisplay() {}

ostream &operator<<(ostream &out, const TextDisplay &td)
{
  for ( int i = 0; i < td.gridSize; ++i )
  {
    for ( int j = 0; j < td.gridSize; ++j ) out << td.theDisplay.at( i ).at( j );
    out << endl;
  }
  return out;
}

