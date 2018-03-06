#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <map>
#include <stdexcept>

using std::map;
using std::out_of_range;

typedef unsigned short ushort;

/**
 *@Class A object represenation of a simple PlayingCard
*/
    
class PlayingCard {
  public:
   /**
    *@fn PlayingCard(const ushort, const char)
    *@brief Constuctor for PlayingCard
    *@param The value of the card ranging from 2-14. 11-14 Represent a Jack,
    *Queen, King and Ace respectively.
    *@param The suit of the PlayingCard represented by a single char (Spade
    *= 'S', Heart = 'H', Diamond = 'D', Club = 'C')
    *@throws out_of_range if either parameters are out of bounds.
   */
   PlayingCard(const ushort, const char);

   /**
    *@fn ushort getValue() const
    *@brief Getter for the value of the card.
    *@return The value of the card
    */
   ushort getValue() const;

   /**
    *@fn char getSuit() const
    *@brief Getter for the suit of the card.
    *@return The character which represents a suit.
    */
   char getSuit() const;

   friend bool operator==(const PlayingCard&, const PlayingCard&);
   friend bool operator!=(const PlayingCard&, const PlayingCard&);
   friend bool operator<(const PlayingCard&, const PlayingCard&);
  private:
   ushort _value;
   char _suit;
};

#endif
