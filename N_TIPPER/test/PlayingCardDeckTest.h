#include "PlayingCardDeck.h"
#include <gtest/gtest.h>
#include <vector>

using std::vector;

class PlayingCardDeckTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    _deck = new PlayingCardDeck();
  }

  virtual void TearDown() {
    delete _deck;
  }

  PlayingCardDeck* _deck;
};
