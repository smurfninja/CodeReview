#include "GoFishView.h"

void GoFishView::displayRules() const {
  cout << endl << "Welcome to Go Fish! The goal of the game is to collect books, four cards of the same value,"
       << " and to be the player with the most books at the end of the game. In this variation, a player"
       << " fishes for cards only once per turn, regardless if you make a catch or not. Also, the game ends"
       << " when you run out of cards. On each players turn, that player chooses an opponent to \"fish\"" 
       << " a card of a chosen value from. If the chosen opponent has any cards that match the value of the "
       << " card that is being fished for, that player must forfeit their cards of that value to the player "
       << " who's turn it is. Got it? HAVE FUN!" << endl << endl << endl;
}

void GoFishView::displayPlayer(const string& name, const ushort& book) const {
  cout << endl << "Player:  " << name << " Books: " << book;
}
