#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"

Cell::Cell( char sym, int r, int c) : cp{nullptr} row{r}, col{c} 
{
	if ( sym == 'A' || sym == 'B' || sym == 'C' || sym == 'D' || sym == 'E' )
	{
		symbol = '.'
			name = "tile";
		pmov = true;
		imov = true;
		emove = true;
	}
	else {
		symbol = sym;
		else if ( sym == '#' )
		{
			name = "passage";
			pmov = true;
			imov = false;
			emove = false;
		}
		else if ( sym == '|' )
		{
			name = "Vwall";
			pmov = false;
			imov = false;
			emove = false;
		}
		else if ( sym == '-' )
		{
			name = "Hwall";
			pmov = false;
			imov = false;
			emove = false;
		}
		else if ( sym == ' ' )
		{
			name = "blank";
			pmov = false;
			imov = false;
			emove = false;
		}
		else if ( sym == '\n' )
		{
			name = "newline";
			pmov = false;
			imov = false;
			emove = false;
		}
		else if ( sym == '\\' )
		{
			name = "stairs";
			pmov = true;
			imov = false;
			emove = false;
		}       
	}
}

Cell::~Cell() { delete cp; }

Character* Cell::getCp() const { return cp; }
char Cell::getSymbol() { return symbol; }
std::string Cell::getname() { return name; }
int Cell::getRow() { return row; }
int Cell::getCol() { return col; }
bool Cell::getEmov() { return emov; }
bool Cell::getImov() { return imov; }
bool Cell::getPmov() { return pmov; }

void Cell::unSetCp() { cp = nullptr;}

void Cell::setCp( character* cp1 ) 
{ 
  cp = cp1;
  notifyObservers( SubscriptionType::NewCharacter );
}

void Cell::notify( Subject &whoNotified )
{ 
  notifyObservers( SubscriptionType::NewCharacter );
}

SubscriptionType Cell::subType() const { return SubscriptionType::SwitchOnly; }
