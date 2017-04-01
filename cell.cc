#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"

Cell::Cell( char sym, int r, int c) : cp{nullptr}, row{r}, col{c} 
{
	if ( sym == 'A' || sym == 'B' || sym == 'C' || sym == 'D' || sym == 'E' )
	{
		symbol = '.';
		name = "tile";
		pmov = true;
		imov = true;
		emov = true;
	}
	else {
		symbol = sym;
		if ( sym == '#' )
		{
			name = "passage";
			pmov = true;
			imov = false;
			emov = false;
		}
		else if ( sym == '|' )
		{
			name = "Vwall";
			pmov = false;
			imov = false;
			emov = false;
		}
		else if ( sym == '-' )
		{
			name = "Hwall";
			pmov = false;
			imov = false;
			emov = false;
		}
		else if ( sym == ' ' )
		{
			name = "blank";
			pmov = false;
			imov = false;
			emov = false;
		}
		else if ( sym == '\n' )
		{
			name = "newline";
			pmov = false;
			imov = false;
			emov = false;
		}
		else if ( sym == '\\' )
		{
			name = "stairs";
			pmov = true;
			imov = false;
			emov = false;
		}       
              	else if ( sym == '+' )
		{
			name = "exit";
			pmov = true;
			imov = false;
			emov = false;
		}
	}
}

Cell::~Cell() { delete cp; }

Character* Cell::getCp() const { return cp; }
char Cell::getSymbol() const { return symbol; }
std::string Cell::getname() const { return name; }
int Cell::getRow() const { return row; }
int Cell::getCol() const { return col; }
bool Cell::getEmov() const { return emov; }
bool Cell::getImov() const { return imov; }
bool Cell::getPmov() const { return pmov; }

void Cell::unSet() { cp = nullptr;}

void Cell::set( Character* cp1 ) 
{ 
  cp = cp1;
//  notifyObservers( SubscriptionType::NewCharacter );
}

void Cell::notify( Subject &whoNotified )
{ 
  notifyObservers( SubscriptionType::All );
}

SubscriptionType Cell::subType() const { return SubscriptionType::SwitchOnly; }
