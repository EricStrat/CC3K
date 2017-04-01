#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

class Character 
{

  protected:

  int HP;
  int baseHP;
  int atk;
  int baseAtk;
  int def;
  int baseDef;
  int gold;
  std::string race;
  char symbol;  

  public:

  Character( int HP, int baseHP, int atk, int baseAtk, int def, int baseDef, int gold, std::string race, char symbol );
  virtual ~Character();
  Character & operator=(const Character &cp1); 
  int getHP();
  int getAtk();
  int getDef();
  int getGold();
  int getBaseHP();
  int getBaseAtk();
  int getBaseDef();
  char getSymbol();
  void setHP();
  void setAtk();
  void setDef();
  std::string getRace();
  virtual int damage( Character &defender );
  virtual void mutAtk( int i );
  virtual void mutDef( int i );
  virtual void mutHP( int i );
  virtual void mutGold( int i );
  virtual void slain();
  virtual bool fiftyFifty(); 
};
#endif
