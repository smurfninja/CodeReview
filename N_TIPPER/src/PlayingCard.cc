#include "PlayingCard.h"

PlayingCard::PlayingCard(const ushort value, const char suit) {
   if(value < 2 || value > 14)
      throw out_of_range("Value for playing card is out of range");

   _value = value;
   
   if(suit != 'C' && suit != 'S' && suit != 'H' && suit != 'D')
	 throw out_of_range("suit was out of range in context.");
   
   _suit = suit;
}

ushort PlayingCard::getValue() const {
  return _value;
}

char PlayingCard::getSuit() const {
  return _suit;
}

bool operator==(const PlayingCard& op1, const PlayingCard& op2) {
  if(op1._value == op2._value && op1._suit == op2._suit)
    return true;

  return false;
}

bool operator!=(const PlayingCard& op1, const PlayingCard& op2) {
  if(op1._value != op2._value || op1._suit != op2._suit)
    return true;

  return false;
}

bool operator<(const PlayingCard& op1, const PlayingCard& op2) {
  if(op1.getValue() < op2.getValue())
    return true;

  return false;
}
