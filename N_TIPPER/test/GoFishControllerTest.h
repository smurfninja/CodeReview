#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "GoFishController.h"
#include "MockPlayer.h"
#include "MockPlayingCardDeck.h"
#include "MockGoFishView.h"

using namespace ::testing;

class GoFishControllerTest : public ::testing::Test {
  protected:
   virtual void SetUp() {
      p1 = new MockPlayer();
      p1->setName("Shelby");
      
      p2 = new MockPlayer();
      p2->setName("Nathan");

      p3 = new MockPlayer();
      p3->setName("Aussie");

      _players.push_back(p1);
      _players.push_back(p2);
      _players.push_back(p3);
      
      _deck = new MockPlayingCardDeck();
      _view = new MockGoFishView();
      _controller = new GoFishController(_players, _deck, _view);
   }
   
   virtual void TearDown() {
      delete _controller;
      delete p1;
      delete p2;
      delete p3;
   }
   
   GoFishView* _view;
   PlayingCardDeck* _deck;
   vector<Player*> _players;
   Player *p1, *p2, *p3;
   GoFishController* _controller;
};
