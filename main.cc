#include "character.h"
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <string>
#include <iostream>

int main() 
{
  std::string str;
  Vampire *vam = new Vampire();
  Shade *sha = new Shade();
  Drow *dro = new Drow();
  Troll *tro = new Troll();
  Goblin *gob = new Goblin();
  Human *hum = new Human;
  Dwarf *dwa = new Dwarf();
  Elf *elf  = new Elf();
  Orc *orc = new Orc();
  Merchant *mer = new Merchant();
  Dragon *dra  = new Dragon();
  Halfling *hal = new Halfling();

  while ( std::cin >> str )
  {

    // player attacks an enemy    

    if ( str == "shaahum" ) hum->attackedBy( *sha );
    else if ( str == "shaadwa" ) dwa->attackedBy( *sha );
    else if ( str == "shaaelf" ) elf->attackedBy( *sha );
    else if ( str == "shaaorc" ) orc->attackedBy( *sha );
    else if ( str == "shaamer" ) mer->attackedBy( *sha );
    else if ( str == "shaadra" ) dra->attackedBy( *sha );    
    else if ( str == "shaahal" ) hal->attackedBy( *sha );

    else if ( str == "droahum" ) hum->attackedBy( *dro );
    else if ( str == "droadwa" ) dwa->attackedBy( *dro );
    else if ( str == "droaelf" ) elf->attackedBy( *dro );
    else if ( str == "droaorc" ) orc->attackedBy( *dro );
    else if ( str == "droamer" ) mer->attackedBy( *dro );
    else if ( str == "droadra" ) dra->attackedBy( *dro );
    else if ( str == "droahal" ) hal->attackedBy( *dro );

    else if ( str == "troahum" ) hum->attackedBy( *tro );
    else if ( str == "troadwa" ) dwa->attackedBy( *tro );
    else if ( str == "troaelf" ) elf->attackedBy( *tro );
    else if ( str == "troaorc" ) orc->attackedBy( *tro );
    else if ( str == "troamer" ) mer->attackedBy( *tro );
    else if ( str == "troadra" ) dra->attackedBy( *tro );
    else if ( str == "troahal" ) hal->attackedBy( *tro );

    else if ( str == "gobahum" ) hum->attackedBy( *gob );
    else if ( str == "gobadwa" ) dwa->attackedBy( *gob );
    else if ( str == "gobaelf" ) elf->attackedBy( *gob );
    else if ( str == "gobaorc" ) orc->attackedBy( *gob );
    else if ( str == "gobamer" ) mer->attackedBy( *gob );
    else if ( str == "gobadra" ) dra->attackedBy( *gob );
    else if ( str == "gobahal" ) hal->attackedBy( *gob );
    
    else if ( str == "vamahum" ) hum->attackedBy( *vam );
    else if ( str == "vamadwa" ) dwa->attackedBy( *vam );
    else if ( str == "vamaelf" ) elf->attackedBy( *vam );
    else if ( str == "vamaorc" ) orc->attackedBy( *vam );
    else if ( str == "vamamer" ) mer->attackedBy( *vam );
    else if ( str == "vamadra" ) dra->attackedBy( *vam );
    else if ( str == "vamahal" ) hal->attackedBy( *vam );

    // enemy attacks a player 
    
    else if ( str == "humasha" ) sha->attackedBy( *hum );
    else if ( str == "humadro" ) dro->attackedBy( *hum );
    else if ( str == "humavam" ) vam->attackedBy( *hum );
    else if ( str == "humatro" ) tro->attackedBy( *hum );
    else if ( str == "humagob" ) gob->attackedBy( *hum );
    
    else if ( str == "dwaasha" ) sha->attackedBy( *dwa );
    else if ( str == "dwaadro" ) dro->attackedBy( *dwa );
    else if ( str == "dwaavam" ) vam->attackedBy( *dwa );
    else if ( str == "dwaatro" ) tro->attackedBy( *dwa );
    else if ( str == "dwaagob" ) gob->attackedBy( *dwa );
   
    else if ( str == "elfasha" ) sha->attackedBy( *elf );
    else if ( str == "elfadro" ) dro->attackedBy( *elf );
    else if ( str == "elfavam" ) vam->attackedBy( *elf );
    else if ( str == "elfatro" ) tro->attackedBy( *elf );
    else if ( str == "elfagob" ) gob->attackedBy( *elf );

    else if ( str == "orcasha" ) sha->attackedBy( *orc );
    else if ( str == "orcadro" ) dro->attackedBy( *orc );
    else if ( str == "orcavam" ) vam->attackedBy( *orc );
    else if ( str == "orcatro" ) tro->attackedBy( *orc );
    else if ( str == "orcagob" ) gob->attackedBy( *orc );

    else if ( str == "merasha" ) sha->attackedBy( *mer );
    else if ( str == "meradro" ) dro->attackedBy( *mer );
    else if ( str == "meravam" ) vam->attackedBy( *mer );
    else if ( str == "meratro" ) tro->attackedBy( *mer );
    else if ( str == "meragob" ) gob->attackedBy( *mer );
    
    else if ( str == "draasha" ) sha->attackedBy( *dra );
    else if ( str == "draadro" ) dro->attackedBy( *dra );
    else if ( str == "draavam" ) vam->attackedBy( *dra );
    else if ( str == "draatro" ) tro->attackedBy( *dra );
    else if ( str == "draagob" ) gob->attackedBy( *dra );

    else if ( str == "halasha" ) sha->attackedBy( *hal );
    else if ( str == "haladro" ) dro->attackedBy( *hal );
    else if ( str == "halavam" ) vam->attackedBy( *hal );
    else if ( str == "halatro" ) tro->attackedBy( *hal );
    else if ( str == "halagob" ) gob->attackedBy( *hal );
  }
  
  delete sha;
  delete dro;
  delete vam;
  delete tro;
  delete gob;
  
  delete hum;
  delete dwa;
  delete elf;
  delete orc;
  delete mer;
  delete dra;
  delete hal;

  return 0;
}
