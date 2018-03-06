#include "PlayingCardDeck.h"
#include "gmock/gmock.h"

class MockPlayingCardDeck : public PlayingCardDeck {
  public:
   explicit MockPlayingCardDeck() { }
   virtual ~MockPlayingCardDeck() { }
   MOCK_METHOD0(drawCard, PlayingCard());
   MOCK_METHOD0(shuffle, void());
   MOCK_CONST_METHOD0(getCardsInDeck, ushort());
};
