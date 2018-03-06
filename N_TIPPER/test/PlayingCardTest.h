#include <gtest/gtest.h>
#include "PlayingCard.h"

class PlayingCardTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
 
  }

  virtual void TearDown() {

  }

  ushort MIN_VALUE = 2, MAX_VALUE = 14;
};
