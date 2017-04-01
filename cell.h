#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "textdisplay.h"
#include "subject.h"
#include "observer.h"
#include "character.h"
#include "subscriptions.h"
#include <string>

class Cell : public Subject, public Observer {
  
  Character* cp;
  char symbol;
  std::string name;
  int row, col;
  bool emov, pmov, imov;

 public:

  Cell( char sym, int r, int c );
  ~Cell();
  void set( Character* cp1);       
  void setCoords(int r, int c);
  void unSet();
  char getSymbol() const;
  std::string getname() const;
  Character* getCp() const;
  int getRow() const;
  int getCol() const;
  bool getEmov() const;
  bool getPmov() const;
  bool getImov() const;

  SubscriptionType subType() const override;
  void notify(Subject &whoNotified) override;  
};
#endif
