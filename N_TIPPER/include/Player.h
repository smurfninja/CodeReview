#ifndef PLAYER_H
#define PLAYER_H

#include "PlayingCard.h"
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

typedef unsigned short ushort;

/**
 *@class Player 
 * An object which represents the Player in the game
 */
class Player {
 public:
  Player() { }

  explicit Player(const string&);
  virtual ~Player() { }
  /**
   *@fn bool addCard(const PlayingCard&)
   *@brief Adds a card to the players hand.
   *@param card PlayingCard to add to their hand.
   *@return A bool which is true if the added card resulted in a book, false otherwise.
   */
  virtual bool addCard(const PlayingCard&);

  /**
   *@fn bool addCards(const vector<PlayingCard> Adds multiple cards to the Player's hand.
   *@param A vector of cards to add to the Player's hand.
   *@return A bool which is true if the added cards resulted in a book, false otherwise.
   */
  virtual bool addCards(const vector<PlayingCard>);

  /**
   *@fn Removes a card from the Player's hand.
   *@param The value and suit of the card to remove.
   *@return A pointer to the PlayingCard that was removed, nullptr if not found.
   */
  virtual PlayingCard* removeCard(const ushort&, const char&);

  /**
   *@fn Removes multipleCards from the Player's hand.
   *@param The value of the cards to remove.
   *@return A vector which contains the removed cards.
   */
  virtual vector<PlayingCard> removeCards(const ushort&);

  /**
   *@fn ushort getBooks() const
   *@brief A getter which returns the number of books made by the Player.
   *@return The number of books made by the Player.
   */
  virtual ushort getBooks() const;

  /**
   *@fn string getName() const
   *@brief A getter for the Player's name
   *@return Name of the player.
   */
  virtual string getName() const;

  /**
   *@fn void Player::setName(const string&)
   *@brief Sets the name of the player.
   *@param name The name of the player.
   */
  virtual void setName(const string&);
  /**
   *@fn A getter which returns the number of cards in the Player's hand.
   *@return The number of cards in the Player's hand.
   */
  virtual ushort getHandSize() const;

  /**
   *@fn A getter which returns the Player's hand.
   *@return A read only vector of PlayingCard's in tne Player's hand.
   */
  virtual const vector<PlayingCard> getHand() const; 
  
  /**
   *@fn virtual bool Player::hasCard(const ushort&) const
   *@brief Returns whether the Player has any card with the given value.
   *@param value The value to be searched for.
   *@returns True if any card with the given value exists in the Player's hand, false otherwise.
   */
  virtual bool hasCard(const ushort&) const;
  
  /**
   *@fn virtual bool Player::hasCard(const ushort&, const char& suit = '!') const
   *@brief Returns whether the Player has the card with the value and suit provided.
   *@param value The value to be searched for.
   *@param suit The suit of the card to be searched for.
   *@returns True if the card exists in the Player's hand, false otherwise.
   */
  virtual bool hasCard(const ushort&, const char& suit) const;
  
 private:
  vector<PlayingCard> _hand;
  vector<vector<PlayingCard>> _books;
  string _name;

  /**
   *@fn Sorts the players hand according to value in ascending order.
   */
  void sortHand();

  /**
   *@fn Checks to see if a book is in the Player's hand.
   *@return The value of the book that can be made. 0 if no book can be made.
   */

  ushort checkForBook();

  /**
   *@fn A helper function for checkForBook to see if there are any books in the Player's hand.
   *@return The value of the book that can be made. 0 if no book can be made.
   */
  ushort hasBook() const;
};

#endif
