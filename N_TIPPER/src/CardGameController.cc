#include "CardGameController.h"

CardGameController::CardGameController() {
  _deck = new PlayingCardDeck();
}

CardGameController::CardGameController(vector<Player*> players, PlayingCardDeck* deck) : _deck{deck} {
  if(players.size() == 1 || players.size() > 5)
    throw runtime_error("Cannot play Go Fish with less than 2 players or more than 5 players");
  _players = players;
}

CardGameController::~CardGameController() {
  delete _deck;
}
