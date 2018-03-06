#include <gtest/gtest.h>
#include "Player.h"

class PlayerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    p1 = new Player();
  }

  virtual void TearDown() {
    delete p1;
  }

  Player* p1;
};
