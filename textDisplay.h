#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

class textDisplay
{
 <vector<vector<Cell>> theDisplay;
 int gridSize;

 public:
 TextDisplay( int n );
 void notify(Subject &whoNotified) override;
 SubscriptionType subType() const override;
 ~TextDisplay();
  friend std::ostream &operator<<( std::ostream &out, const TextDisplay &td );

};


#endif
