#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"
#include <string>

class Floor { 

  std::vector<std::vector<Cell>> theGrid;  // The actual grid.
  TextDisplay *td; // The text display.
  int level, gridLen, gridWid;
  void clearGrid();   // Frees the grid.

 public:
  Floor();
  ~Floor();
  void move(int startRow, int startCol, std::string direction );
  void init(int lv, int n, int m);
  void setCell(int r, int c, character *pc1 );

  friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif
