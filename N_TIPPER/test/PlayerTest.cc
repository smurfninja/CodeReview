#include "PlayerTest.h"

TEST_F(PlayerTest, setNameOnCreation) {
  p1->setName("Shelby");
  ASSERT_EQ(p1->getName(), "Shelby");
}

TEST_F(PlayerTest, addCardToHand) {
  ASSERT_EQ(p1->getHandSize(), 0);
  p1->addCard(PlayingCard(3, 'S'));
  ASSERT_EQ(p1->getHandSize(), 1);
}

TEST_F(PlayerTest, addCardsToHand) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(2, 'S'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  ASSERT_EQ(p1->getHandSize(), 0);
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);
}

TEST_F(PlayerTest, cardSuccessfullyRemoved) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(2, 'S'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);
  PlayingCard* card = p1->removeCard(2, 'S');
  ASSERT_EQ(p1->getHandSize(), 2);
  delete card;
}

TEST_F(PlayerTest, cardNotFound) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(2, 'S'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);
  PlayingCard* card = p1->removeCard(3, 'D');
  ASSERT_EQ(card, nullptr);
}

TEST_F(PlayerTest, removeMultipleCardsSuccessful) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(9, 'S'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);
  p1->removeCards(9);
  ASSERT_EQ(p1->getHandSize(), 1);
}

TEST_F(PlayerTest, removeMultipleCardsUnsuccessful) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(9, 'S'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);
  vector<PlayingCard> emptyVector = p1->removeCards(8);
  ASSERT_EQ(p1->getHandSize(), 3);
  ASSERT_EQ(emptyVector.size(), 0);
}

TEST_F(PlayerTest, testCardsAreSorted) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(10, 'S'), PlayingCard(8, 'H'), PlayingCard(2, 'C') };
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);
  const vector<PlayingCard> hand = p1->getHand();
  for(ushort u = 0; u < p1->getHandSize()-1; ++u) {
    ASSERT_TRUE(hand[u] < hand[u+1]);
  }
}

TEST_F(PlayerTest, bookOnAddSingleCard) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(10, 'D'), PlayingCard(10, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);
  ASSERT_TRUE(p1->addCard(PlayingCard(10, 'S')));
  ASSERT_EQ(p1->getBooks(), 1);
}

TEST_F(PlayerTest, bookOnMultipleAdd) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(10, 'D'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);
  ASSERT_EQ(p1->getHandSize(), 3);

  vector<PlayingCard> tens = { PlayingCard(10, 'S'), PlayingCard(10, 'H') };
  
  ASSERT_TRUE(p1->addCards(tens));
  ASSERT_EQ(p1->getBooks(), 1);  
}

TEST_F(PlayerTest, playerHasCard) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(10, 'D'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);

  ASSERT_TRUE(p1->hasCard(9));
  ASSERT_TRUE(p1->hasCard(9, 'H'));
}

TEST_F(PlayerTest, playerDoesNotHaveCard) {
  vector<PlayingCard> cardsToAdd = { PlayingCard(10, 'D'), PlayingCard(9, 'H'), PlayingCard(10, 'C') };
  p1->addCards(cardsToAdd);

  ASSERT_FALSE(p1->hasCard(2));
  ASSERT_FALSE(p1->hasCard(2, 'H'));
}

