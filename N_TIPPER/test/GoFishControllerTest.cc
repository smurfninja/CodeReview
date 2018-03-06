#include "GoFishControllerTest.h"

TEST_F(GoFishControllerTest, testDefaultConstructor) {
  GoFishController* defaultController;
  ASSERT_NO_THROW(defaultController = new GoFishController());
  delete defaultController;
}

TEST_F(GoFishControllerTest, testInvalidNumberOfPlayers) {
  _players.clear();
  ushort lowerBound = 1, upperBound = 6;
  for(ushort u = 0; u < lowerBound; ++u) {
    Player* newPlayer = new MockPlayer();
    _players.push_back(newPlayer);
  }

  GoFishController* newController;
  ASSERT_THROW(newController = new GoFishController(_players, _deck, _view), runtime_error);

  _players.clear();
  for(ushort u = 0; u < upperBound; ++u) {
    Player* newPlayer = new MockPlayer();
    _players.push_back(newPlayer);
  }
  
  ASSERT_THROW(newController = new GoFishController(_players, _deck, _view), runtime_error);
}

TEST_F(GoFishControllerTest, startGameTest) {
   MockPlayingCardDeck* deck = dynamic_cast<MockPlayingCardDeck*>(_deck);
   MockPlayer* player1 = dynamic_cast<MockPlayer*>(_players[0]);
   MockPlayer* player2 = dynamic_cast<MockPlayer*>(_players[1]);
   MockPlayer* player3 = dynamic_cast<MockPlayer*>(_players[2]);
   MockGoFishView* view = dynamic_cast<MockGoFishView*>(_view);

   vector<PlayingCard> fakeCards = { PlayingCard(2, 'S') };
   ON_CALL(*(deck), shuffle())
      .WillByDefault(Return());

   ON_CALL(*(deck), drawCard())
      .WillByDefault(Return(PlayingCard(2, 'S')));
   
   ON_CALL(*(player1), addCard(_))
     .WillByDefault(Return(true));

   ON_CALL(*(player1), addCard(_))
     .WillByDefault(Return(true));

   ON_CALL(*(player1), removeCards(_))
     .WillByDefault(Return(fakeCards));

   ON_CALL(*(player1), hasCard(_))
     .WillByDefault(Return(true));
   
   ON_CALL(*(player2), getHand())
     .WillByDefault(Return(fakeCards));
   
   ON_CALL(*(player2), addCard(_))
     .WillByDefault(Return(true));

   ON_CALL(*(player2), addCard(_))
     .WillByDefault(Return(true));
   
   ON_CALL(*(player2), removeCards(_))
     .WillByDefault(Return(fakeCards));

   ON_CALL(*(player2), hasCard(_))
     .WillByDefault(Return(true));
   
   ON_CALL(*(player3), getHand())
     .WillByDefault(Return(fakeCards));
   
   ON_CALL(*(player3), addCard(_))
     .WillByDefault(Return(true));

   ON_CALL(*(player3), addCards(_))
     .WillByDefault(Return(true));
   
   ON_CALL(*(player3), removeCards(_))
     .WillByDefault(Return(vector<PlayingCard>()));

   ON_CALL(*(player3), hasCard(_))
     .WillByDefault(Return(true));

   ON_CALL(*(view), waitForInput())
     .WillByDefault(Return());

   ON_CALL(*(view), displayMessage(_))
     .WillByDefault(Return());
   
   EXPECT_CALL(*(deck), shuffle())
     .Times(1);
   
   EXPECT_CALL(*(view), promptUserForInput(_))
     .Times(12)
     .WillOnce(Return("AAAAAAA")) // Player 1
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("1234"))
     .WillOnce(Return("0")) // Player 2
     .WillOnce(Return("A"));

   EXPECT_CALL(*(player1), getHand())
     .Times(AtLeast(1))
     .WillOnce(Return(fakeCards))
     .WillOnce(Return(fakeCards))
     .WillRepeatedly(Return(vector<PlayingCard>()));
				      
   EXPECT_CALL(*(player2), getHand())
     .Times(AtLeast(1))
     .WillOnce(Return(fakeCards))
     .WillOnce(Return(fakeCards))
     .WillRepeatedly(Return(vector<PlayingCard>()));

   EXPECT_CALL(*(player3), getHand())
     .Times(AtLeast(1))
     .WillOnce(Return(fakeCards))
     .WillOnce(Return(fakeCards))
     .WillRepeatedly(Return(vector<PlayingCard>()));
		     

   EXPECT_CALL(*(player1), getBooks())
     .Times(AtLeast(1))
     .WillOnce(Return(1));

   EXPECT_CALL(*(player2), getBooks())
     .Times(AtLeast(1))
     .WillOnce(Return(2));

   EXPECT_CALL(*(player3), getBooks())
     .Times(AtLeast(1))
     .WillOnce(Return(3));
   
   EXPECT_CALL(*(player1), addCard(_))
     .Times(AtLeast(7));

   EXPECT_CALL(*(player2), addCard(_))
     .Times(AtLeast(7));

   EXPECT_CALL(*(player3), addCard(_))
     .Times(AtLeast(7));

   EXPECT_CALL(*(deck), drawCard())
     .Times(AtLeast(21));

   EXPECT_CALL(*(deck), getCardsInDeck())
     .Times(AtLeast(1))
     .WillRepeatedly(Return(52));
   
   _controller->startGame();
   player1 = nullptr;
   player2 = nullptr;
   player3 = nullptr;
}

TEST_F(GoFishControllerTest, getPlayerTest) {
  MockGoFishView* view = dynamic_cast<MockGoFishView*>(_view);
  MockPlayingCardDeck* deck = dynamic_cast<MockPlayingCardDeck*>(_deck);

  vector<Player*> players;

  GoFishController* emptyPlayerController = new GoFishController(players, _deck, _view);
  
  ON_CALL(*(deck), shuffle())
      .WillByDefault(Return());
     
   ON_CALL(*(deck), drawCard())
      .WillByDefault(Return(PlayingCard(2, 'S')));
  
  ON_CALL(*(view), waitForInput())
     .WillByDefault(Return());

  ON_CALL(*(view), displayMessage(_))
    .WillByDefault(Return());
  
  vector<string> playerNames = { "Nathan", "Shelby", "Aussie" };
  EXPECT_CALL(*view, getPlayers())
    .Times(1)
    .WillOnce(Return(playerNames));
  
  EXPECT_CALL(*deck, drawCard())
    .WillOnce(Return(PlayingCard(2, 'H')))
    .WillOnce(Return(PlayingCard(2, 'S')))
    .WillOnce(Return(PlayingCard(2, 'D')))
    .WillOnce(Return(PlayingCard(3, 'H')))
    .WillOnce(Return(PlayingCard(4, 'C')))
    .WillOnce(Return(PlayingCard(5, 'C')))
    .WillRepeatedly(Return(PlayingCard(6, 'S')));
	      
  EXPECT_CALL(*view, promptUserForInput(_))
    .Times(AtLeast(2))
    .WillOnce(Return("0"))
    .WillOnce(Return("1"))
    .WillOnce(Return("2"));
  
  EXPECT_CALL(*deck, getCardsInDeck())
    .Times(1)
    .WillOnce(Return(0));

  emptyPlayerController->startGame();
}
