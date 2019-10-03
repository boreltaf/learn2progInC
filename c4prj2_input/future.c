#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr){
  if(index < fc->n_decks){
     fc->decks[index].cards=realloc(fc->decks[index].cards, ++(fc->decks[index].n_cards)*sizeof(*(fc->decks[index].cards)));
     fc->decks[index].cards[fc->decks[index].n_cards -1] = ptr;
  }
  else{
    for(int i=0; i<index; i++){
      if(i>= fc->n_decks){
	fc->decks = realloc(fc->decks, ++(fc->n_decks)*sizeof(*(fc->decks)));
	fc->decks[fc->n_decks - 1].n_cards =0;
	fc->decks[fc->n_decks - 1].cards = NULL;
      }
    }
    fc->decks = realloc(fc->decks, ++(fc->n_decks)*sizeof(*(fc->decks)));
    fc->decks[index].cards=realloc(fc->decks[index].cards, ++(fc->decks[index].n_cards)*sizeof(*(fc->decks[index].cards)));
    fc->decks[index].cards[fc->decks[index].n_cards -1] = ptr;
  }
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc){
  if((fc == NULL)||(fc->n_decks == 0)){
    perror(" ERROR! there is no cards in the future deck \n");
    return;
  }
  for(int i=0; i< fc->n_decks; i++){
    if(fc->decks[i].cards!= NULL){
      size_t range = ((fc->deck[i]).n_cards > deck->n_cards)? deck->n_cards: (fc->deck[i]).n_cards;
	for(int j=0; j< range; j++){
	  (fc->decks[i]).cards[j] = deck->cards[i];
	}
    }
  }
}

