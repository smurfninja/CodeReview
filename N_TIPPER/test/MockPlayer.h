#include "Player.h"
#include "gmock/gmock.h"

class MockPlayer : public Player {
 public:
  explicit MockPlayer() { }
  virtual ~MockPlayer() { }
  MOCK_METHOD1(addCard, bool(const PlayingCard& cardToAdd));
  MOCK_METHOD1(addCards, bool(const vector<PlayingCard> cardsToAdd));
  MOCK_METHOD2(removeCard, PlayingCard*(const ushort& value, const char& suit));
  MOCK_METHOD1(removeCards, vector<PlayingCard>(const ushort& value));
  MOCK_CONST_METHOD0(getBooks, ushort());
  MOCK_CONST_METHOD0(getName, string());
  MOCK_CONST_METHOD0(getHandSize, ushort());
  MOCK_CONST_METHOD0(getHand, const vector<PlayingCard>());
  MOCK_CONST_METHOD1(hasCard, bool(const ushort&));
};
