#include "GoFishController.h"

GoFishController::GoFishController() : CardGameController() {
  _view = new GoFishView();
}

GoFishController::GoFishController(vector<Player*> players, PlayingCardDeck* deck, GoFishView* view) : CardGameController(players, deck) {
  _view = view;
}

GoFishController::~GoFishController() {
  delete _view;
}

void GoFishController::startGame() {
  if(_players.size() == 0)
    getPlayers();
  
  _deck->shuffle();
  srand(time(nullptr));
  random_shuffle(_players.begin(), _players.end());
  
  ushort dealer = 0;
  ushort index = (dealer+1) % _players.size();
  ushort cardsDealt = 0, cardsToDeal = (_players.size() < 4) ? 7 : 5;
  while(cardsDealt < cardsToDeal) {
     PlayingCard dealtCard = _deck->drawCard();
     _players[index]->addCard(dealtCard);
     index = (index+1) % _players.size();
     if(index == (dealer+1) % _players.size())
	++cardsDealt;
  }

  gameLoop(dealer+1);
}

void GoFishController::gameLoop(const ushort& startingPlayer) {
  _view->displayRules();
  ushort currentPlayer = startingPlayer;
  bool gameOver = false;
  while(!gameOver) {
    _view->displayMessage("Current Player: " + _players[currentPlayer]->getName() + '\n' + '\n');
    _view->waitForInput();
    showPlayerHand((_players[currentPlayer]));
    showPlayers(currentPlayer);

    // GET INPUT ************************************************************
    ushort playerToFish = 0, numberOfInvalidInputs = 5, count = 0;
    while(true) {
      string input = _view->promptUserForInput("Choose the id of the opponent you wish to fish from: ");
      try {
	playerToFish = std::stoi(input);
      } catch (std::invalid_argument) {
	_view->displayMessage("Incorrect input. Please try again.\n");
	playerToFish = 10000; 
      }
      if(playerToFish >= 0 && playerToFish < _players.size() && playerToFish != currentPlayer) {
	break;
      }

      ++count;
      if(count >= 5) {
	_view->displayMessage("Ok, so we are going to choose for you...\n");
	playerToFish = (currentPlayer + 1) % _players.size();
	break;
      }
      _view->displayMessage("Incorrect input. Please try again.\n");
    }
    
    ushort valueToFishFor = 0;
    string valueInput;
    count = 0;
    while(true) {
       valueInput = _view->promptUserForInput("Choose a value you wish to fish for (2-A): ");
       
       if(_faceValues.find(valueInput) != _faceValues.end()) {
	 valueToFishFor = _faceValues[valueInput];
	 if(_players[currentPlayer]->hasCard(valueToFishFor))
	   break;
       }

       ++count;
       if(count >= numberOfInvalidInputs) {
	 _view->displayMessage("Ok, so we are going to choose for you...\n");
	 valueToFishFor = (rand() % 13) + 2; // rand value from 2-14
	 break;
       }
       
       _view->displayMessage("You must enter a value or face that is in your hand.");
    }
    // **************************************************************************
    
    vector<PlayingCard> cards = _players[playerToFish]->removeCards(valueToFishFor);
    if(cards.size() == 0) {
      _view->displayMessage("GO FISH\n");
      _players[currentPlayer]->addCard(_deck->drawCard()); // check add card and draw card
    }

    else {
      string grammar = cards.size() == 1 ? std::to_string(_faceValues[valueInput]) : (std::to_string(_faceValues[valueInput]) + "\'s");
      _view->displayMessage("You caught " + std::to_string(cards.size()) + " " + grammar + "!");
      if(_players[currentPlayer]->addCards(cards))
	_view->displayMessage("You made a book of " + std::to_string(valueToFishFor) + "'s!");
    }

    for(ushort u = 0; u < _players.size(); ++u) {
      if(_players[u]->getHand().size() == 0) {
	_view->displayMessage(_players[u]->getName() + " has run out of cards! The game is over!\n");
	gameOver = true;
	break;
      }
    }

    if(gameOver)
      break;

    if(_deck->getCardsInDeck() == 0) {
      _view->displayMessage("The deck has run out of cards! The game is over!\n");
      gameOver = true;
      break;
    }
    
    currentPlayer = (currentPlayer+1) % _players.size();
  }

  ushort winner = 0;
  for(ushort u = 1; u < _players.size(); ++u) {
    if(_players[u]->getBooks() > _players[winner]->getBooks())
      winner = u;
  }
  
  _view->displayMessage(_players[winner]->getName() + " wins!\n\nThanks for playing! Good bye");
}

void GoFishController::showPlayerHand(const Player* const player) const {
  vector<PlayingCard> hand = player->getHand();

  _view->displayMessage("Your Hand: ");
  for(ushort u = 0; u < hand.size(); ++u) {
    _view->displayCard(hand[u].getValue(), hand[u].getSuit());
  }
}

void GoFishController::showPlayers(const ushort& currentPlayer) const {
  for(ushort u = 0; u < _players.size(); ++u) {
    if(u == currentPlayer)
      continue;
    
    _view->displayMessage("\nID " + std::to_string(u) + ": " + _players[u]->getName() + " Books: " + std::to_string(_players[u]->getBooks()) + '\n');
  }
}

void GoFishController::getPlayers() {
  vector<string> playerNames = _view->getPlayers();
  for(ushort u = 0; u < playerNames.size(); ++u) {
    Player* newPlayer = new Player(playerNames[u]);
    _players.push_back(newPlayer);
  }
}
