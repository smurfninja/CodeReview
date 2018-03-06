#ifndef PLAYINGCARDDECK_H
#define PLAYINGCARDDECK_H

#include "PlayingCard.h"
#include <algorithm> // random_shuffle
#include <ctime>
#include <cstdlib>
#include <vector> 

typedef unsigned short ushort;

/**
 *@class PlayingCardDeck
 *@brief An object representation of a deck which holds PlayingCard's
 */
class PlayingCardDeck {
  public:
   /**
    *@fn PlayingCardDeck()
    *@brief Constructor for PlayingCardDeck
    */
   PlayingCardDeck();
   virtual ~PlayingCardDeck() {}

   /**
    *@fn PlayingCard drawCard()
    *@brief Used for drawing the top card of the deck.
    */
   virtual PlayingCard drawCard();

   /**
    *@fn void shuffle()
    *@brief Shuffles the deck.
    */
   virtual void shuffle();

   /**
    *@fn short getCardsInDeck() const 
    *@brief A getter for returning the cards remaining the in PlayingCardDeck
    *@returns Number of cards in the remaining in the deck.
    */
   virtual ushort getCardsInDeck() const;

  private:
   std::vector<PlayingCard> _deck;
   ushort _deckSize = 52;
};

#endif
