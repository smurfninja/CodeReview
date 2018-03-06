#ifndef GOFISHCONTROLLER_H
#define GOFISHCONTROLLER_H

#include "CardGameController.h"
#include "PlayingCardDeck.h"
#include "GoFishView.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

/**
 *@class GoFishController
 *@brief The Controller for the Go Fish card game.
 */

class GoFishController : public CardGameController {
 public:
  /**
   *@fn GoFishController()
   *@brief The default constructor which creates a default PlayingCardDeck and a default GoFishView.
   */
  GoFishController();

  /**
   *@fn GoFishController(vector<Player*>, PlayingCardDeck*, GoFishView*)
   *@brief A Contructor which allows for a controller to be made with given attributes. 
   */
  GoFishController(vector<Player*>, PlayingCardDeck*, GoFishView*);
  virtual ~GoFishController();

  /**
   *@fn void startGame() override
   *@brief Overriden function of CardGameController which starts the Go Fish game.
   */
  virtual void startGame() override;
 private:
  GoFishView* _view;

  /**
   *@fn void gameLoop(const ushort&)
   *@brief Responsible for running the Go Fish game.
   *@param startingPlayer The player to the "left" of the randomized dealer.
   */
  void gameLoop(const ushort&);

  /**
   *@fn void showPlayerHand(const Player* const) const
   *@brief Calls the View to show a Player's hand.
   *@param player The Player who's hand to display.
   */
  void showPlayerHand(const Player* const) const;

  /**
   *@fn void showPlayers(const ushort&) const
   *@brief Calls the View to display the other Player's other than the current Player.
   *@param currentPlayer The player NOT to display
   */
  void showPlayers(const ushort&) const;

  /**
   *@fn void getPlayers()
   *@brief Calls the view to get Player's from the command line.
   */
  void getPlayers();
};

#endif
