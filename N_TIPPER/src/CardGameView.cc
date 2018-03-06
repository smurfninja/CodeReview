#include "CardGameView.h"

vector<string> CardGameView::getPlayers() const {
  vector<string> players;
  ushort max_players = 5;
  while(true) {
    string name = promptUserForInput("Please enter the name of Player " + std::to_string(players.size()) +
				    " (press q to stop): ");
    if(name.size() == 1 && name[0] == 'q') {
      if(players.size() < 2) {
	cout << "You must have at least 2 players to play Go Fish." << endl;
	continue;
      }
      else
	break;
    }
    
    players.push_back(name);
    if(players.size() == max_players) {
      cout << "You have reached the max number of players." << endl;
      break;
    }
  }

  return players;
}

string CardGameView::promptUserForInput(const string prompt) const {
  cout << endl << prompt;
  string returnInput;
  std::getline(cin, returnInput);
  
  return returnInput;
}

void CardGameView::displayMessage(const string message) const {
  cout << endl << message;
}

void CardGameView::displayCard(const ushort& value, const char& suit) const {
  if(value <= 10)
    cout << endl << value << " " << suits.at(suit);
  else
    cout << endl << faces.at(value) << " " << suits.at(suit);
}

void CardGameView::displayPlayer(const string& name) const {
  cout << endl << "Player: " << name << endl;
}

void CardGameView::waitForInput() const {
  cout << "Please hit Enter to continue...";
  if(cin.get() == '\n')
    return;
}
