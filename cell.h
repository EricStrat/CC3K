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

class Cell : public Subject, public Observer {
  Character* cp;
  char symbol;
  string name;
  int row, col;
  bool emov, pmov, imov;

 public:
  Cell( char sym, int r, int c );
  ~Cell();
  Character* getCp();
  void setCp();       
  void setCoords(int r, int c);
  void unsetCp();
  char getSymbol();
  std::string getname();
  int getRow();
  int getCol();
 bool getEmov();
 bool getPmov();
 bool getImov();

  SubscriptionType subType() const override;
  void notify(Subject &whoNotified) override;  
};
#endif
