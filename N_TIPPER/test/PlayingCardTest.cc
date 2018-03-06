#include "PlayingCardTest.h"

TEST_F(PlayingCardTest, invalidValueOnCreation) {
   ASSERT_THROW(PlayingCard(MAX_VALUE+1, 'S'), out_of_range);
   ASSERT_THROW(PlayingCard(MIN_VALUE-1, 'S'), out_of_range);
}

TEST_F(PlayingCardTest, invalidSuitOnCreation) {
  ASSERT_THROW(PlayingCard(8, '!'), out_of_range);
  ASSERT_THROW(PlayingCard(9, 't'), out_of_range);
}

TEST_F(PlayingCardTest, getValueCorrect) {
  PlayingCard c1(MAX_VALUE, 'S'), c2(MIN_VALUE, 'S');
  ASSERT_EQ(c1.getValue(), MAX_VALUE);
  ASSERT_EQ(c2.getValue(), MIN_VALUE);
}

TEST_F(PlayingCardTest, getSuitCorrect) {
  PlayingCard c1(MAX_VALUE, 'H'), c2(MIN_VALUE, 'D');
  ASSERT_EQ(c1.getSuit(), 'H');
  ASSERT_EQ(c2.getSuit(), 'D');
}

TEST_F(PlayingCardTest, testEquality) {
  PlayingCard c1(MAX_VALUE, 'H'), c2(MAX_VALUE, 'H'), c3(MIN_VALUE, 'S'), c4(MIN_VALUE, 'S');
  ASSERT_EQ(c1, c2);
  ASSERT_EQ(c3, c4);
  ASSERT_FALSE(c1 == c3);
  ASSERT_FALSE(c2 == c4);
}

TEST_F(PlayingCardTest, testNotEqual) {
  PlayingCard c1(MAX_VALUE, 'C'), c2(MAX_VALUE, 'D'), c3(MIN_VALUE, 'S'), c4(MIN_VALUE, 'S');
  ASSERT_NE(c1, c3);
  ASSERT_NE(c2, c4);
  ASSERT_FALSE(c1 != c1);
  ASSERT_FALSE(c3 != c4);
}
