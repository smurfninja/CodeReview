#include "Player.h"

Player::Player(const string& name) : _name{name} {}

bool Player::addCard(const PlayingCard& card) {
  _hand.push_back(card);
  sortHand();
  return checkForBook();
}

bool Player::addCards(const vector<PlayingCard> cardsToAdd) {
  for(ushort u = 0; u < cardsToAdd.size(); ++u) {
    _hand.push_back(cardsToAdd[u]);
  }
  sortHand();
  return checkForBook();
}

PlayingCard* Player::removeCard(const ushort& value, const char& suit) {
  PlayingCard cardToCompare(value, suit);
  for(ushort u = 0; u < _hand.size(); ++u) {
    if(_hand[u] == cardToCompare) {
      PlayingCard* cardToReturn = new PlayingCard(_hand[u].getValue(), _hand[u].getSuit());
      _hand.erase(_hand.begin() + u);
      return cardToReturn;
    }
  }

  return nullptr;
}

vector<PlayingCard> Player::removeCards(const ushort& value) {
  vector<PlayingCard> vectorToReturn;
  for(ushort u = 0; u < _hand.size(); ++u) {
    if(_hand[u].getValue() == value) {
      vectorToReturn.push_back(_hand[u]);
      _hand.erase(_hand.begin() + u--);
    }
  }

  return vectorToReturn;
}

const vector<PlayingCard> Player::getHand() const {
  return _hand;
}

ushort Player::getBooks() const {
  return _books.size();
}

string Player::getName() const {
  return _name;
}

void Player::setName(const string& name) {
  _name = name;
}

ushort Player::getHandSize() const {
  return _hand.size();
}

void Player::sortHand() {
  sort(_hand.begin(), _hand.end());
}

ushort Player::checkForBook() {
  ushort bookValue = hasBook();
  if(bookValue) {
    _books.push_back(removeCards(bookValue));
  }

  return bookValue;
}

ushort Player::hasBook() const {
  ushort value = _hand[0].getValue(), count = 1;
  for(ushort u = 1; u < _hand.size(); ++u) {
    if(_hand[u].getValue() == value) {
      ++count;
      if(count == 4)
	return value; 
    }

    else {
      value = _hand[u].getValue();
      count = 1;
    }
  }

  return 0;
}

bool Player::hasCard(const ushort& value) const {
  for(ushort u = 0; u < _hand.size(); ++u) {
    if(_hand[u].getValue() == value)
      return true;
  }

  return false;
}

bool Player::hasCard(const ushort& value, const char& suit) const {
  for(ushort u = 0; u < _hand.size(); ++u) {
      PlayingCard card(value, suit);
      if(_hand[u] == card)
	return true;
    }

  return false;
}
