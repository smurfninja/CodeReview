#ifndef CARDGAMEVIEW_H
#define CARDGAMEVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;
using std::cout;
using std::cin;
using std::endl;

typedef unsigned short ushort;

/**
 *@class CardGameView
 *@brief An abstract class for views
 */

class CardGameView {
 public:
  /**
   *@fn CardGameView()
   *@brief Default Constructor
   */
  CardGameView() {}
  /**
   *@fn ~CardGameView()
   *@brief Destructor
   */
  virtual ~CardGameView() { }

  /**
   *@fn vector<string> getPlayers() const
   *@brief Prompts the player to enter Player's to play the game.
   */
  virtual vector<string> getPlayers() const;

  /**
   *@fn void displayRules() const = 0
   *@brief Pure virtual function which displays the rules of the game.
   */
  virtual void displayRules() const = 0;

  /**
   *@fn string promptUserForInput(const string) const
   *@brief Allows for input from the console while giving a prompt for what the program wants from the user.
   *@param prompt The prompt the program will give to the user.
   *@return The string from the command line.
   */
  virtual string promptUserForInput(const string) const;

  /**
   *@fn void displayMessage(const string) const;
   *@brief Allows Controllers to display messages to the View.
   */
  virtual void displayMessage(const string) const;

  /**
   *@fn void displayCard(const ushort&, const char&) const
   *@brief Displays a cards value and suit.
   *@param value The value of the card.
   *@param suit The suit of the card.
   */
  virtual void displayCard(const ushort&, const char&) const;

  /**
   *@fn void displayPlayer(const string&) const
   *@brief Displays the Player's name on the console.
   *@param name Name of the player.
   */
  virtual void displayPlayer(const string&) const;

  /**
   *@fn void waitForInput() const;
   *@brief Waits for the user to hit enter before continuing the program.
   */
  virtual void waitForInput() const;
 private:
  map<char, string> suits = { {'S', "Spades"}, {'H', "Hearts"}, {'D', "Diamonds"}, {'C', "Clubs"} };
  map<ushort, char> faces = { { 11, 'J' }, { 12, 'Q' }, { 13, 'K' }, { 14, 'A' } };
};

#endif
