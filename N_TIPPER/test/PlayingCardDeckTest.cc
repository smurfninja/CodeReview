#include "PlayingCardDeckTest.h"

TEST_F(PlayingCardDeckTest, deckReducedByOneAfterDraw) {
  PlayingCard card = _deck->drawCard();
  unsigned short remainingCards = _deck->getCardsInDeck();
  ASSERT_EQ(remainingCards, 51);
}

TEST_F(PlayingCardDeckTest, testUniqueness) {
  unsigned short size = _deck->getCardsInDeck();
  vector<PlayingCard> cards;
  for(unsigned short u = 0; u < size; ++u) {
    cards.push_back(_deck->drawCard());
  }

  unsigned short index = 0;

  while(index < size) {
    PlayingCard currentCard = cards[index];
    for(unsigned short u = index + 1; u < size; ++u) {
      PlayingCard cardToCompare = cards[u];
      ASSERT_NE(currentCard, cardToCompare);
    }
    ++index;
  }
}

TEST_F(PlayingCardDeckTest, cardsAreShuffled) {
  vector<PlayingCard> top5_1, top5_2;
  PlayingCardDeck deck2; // Not shuffled
  _deck->shuffle();
  bool shuffled = false;
  ushort count = 0;
  for(ushort u = 0; u < 5; ++u) {
    PlayingCard c1 = _deck->drawCard();
    PlayingCard c2 = deck2.drawCard();
    if(c1 == c2)
      ++count;
  }
  
  if(count != 5)
    shuffled = true;

  ASSERT_TRUE(shuffled);
}
