#ifndef MOCKGOFISHVIEW_H
#define MOCKGOFISHVIEW_H

#include "gmock/gmock.h"
#include "GoFishView.h"

class MockGoFishView : public GoFishView {
 public:
  explicit MockGoFishView() { }
  virtual ~MockGoFishView() { }
  MOCK_CONST_METHOD0(displayRules, void());
  MOCK_CONST_METHOD1(promptUserForInput, string(const string));
  MOCK_CONST_METHOD1(displayMessage, void(const string));
  MOCK_CONST_METHOD2(displayCard, void(const ushort&, const char&));
  MOCK_CONST_METHOD2(displayPlayer, void(const string&, const ushort&));
  MOCK_CONST_METHOD0(waitForInput, void());
  MOCK_CONST_METHOD0(getPlayers, vector<string>());
};

#endif
