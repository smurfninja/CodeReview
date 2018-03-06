#ifndef GOFISHVIEW_H
#define GOFISHVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "CardGameView.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

typedef unsigned short ushort;

/**
 *@class GoFishView
 *@brief A View for the Go Fish game.
 */
class GoFishView : public CardGameView {
  public:
   GoFishView() { }
   ~GoFishView() { }
   /**
    *@fn void displayRules() const
    *@brief Displays the rules related to Go Fish.
    */
   virtual void displayRules() const;

   /**
    *@fn void displayPlayer(const string&, const ushort&) const
    *@brief Displays the name of the Player and the number of books the player has.
    *@param The name of the Player.
    *@param The number of books the Player has.
    */
   virtual void displayPlayer(const string&, const ushort&) const;
};

#endif
