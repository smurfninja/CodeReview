#ifndef CARDGAMECONTROLLER_H
#define CARDGAMECONTROLLER_H

#include "Player.h"
#include "PlayingCardDeck.h"
#include "CardGameView.h"
#include  <stdexcept>
#include <vector>
#include <map>

using std::runtime_error;
using std::vector;
using std::map;
/**
 *@class CardGameController
 *@brief Abstract class for Controllers.
 */
class CardGameController
{
 public:
  /**
   *@fn CardGameController()
   *@brief Default Contructor which constructs its own PlayingCardDeck
   */
  CardGameController();

  /**
   *@fn CardGameController(vector<Player*>, PlayingCardDeck*)
   *@brief Contructor which allows for dependency injection of Player's amd PlayingCardDeck's.
   */
  CardGameController(vector<Player*>, PlayingCardDeck*);

  /**
   *@fn ~CardGameController
   *@brief Virtual Destructor
   */
  virtual ~CardGameController();

  /**
   *@fn virtual void startGame() = 0
   *@brief A pure virtual class which allows Controllers to start their games differently
   */
  virtual void startGame() = 0;
  
 protected:
  vector<Player*> _players; /**< A vector to hold the Player's of the game. */
  map<string, ushort> _faceValues = { {"2", 2 }, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6 }, {"7", 7}, {"8", 8} , {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}, {"A", 14} }; /**< A map of face values to map input values to the value of the card. */ 
  PlayingCardDeck* _deck; /** < The deck that will be used throughout the game */
};

#endif
