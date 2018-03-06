#include "PlayingCardDeck.h"

PlayingCardDeck::PlayingCardDeck()
{
   char symbols[4] = { 'S', 'H', 'D', 'C' };
   ushort numberOfSymbols = 4, minValue = 2;

   for(ushort u = 0; u < numberOfSymbols; ++u) {
      for(ushort v = 0; v < _deckSize / numberOfSymbols; ++v) {
	 _deck.push_back(PlayingCard(v + minValue, symbols[u]));
      }
   }
}

PlayingCard PlayingCardDeck::drawCard() {
    PlayingCard cardToDraw = _deck[_deck.size() - 1];
   _deck.pop_back();
   return cardToDraw;
}

void PlayingCardDeck::shuffle() {
   std::srand( unsigned(std::time(0) ) );
   std::random_shuffle(_deck.begin(), _deck.end());
}

ushort PlayingCardDeck::getCardsInDeck() const {
  return _deck.size();
}
