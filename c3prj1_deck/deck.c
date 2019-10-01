#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h> 
#include "deck.h"
void free_deck(deck_t * deck) ;

#define max 54

void print_hand(deck_t * hand){
  size_t i=0;
  card_t c={2, NUM_SUITS};
  for(i=0; i< hand->n_cards; i++){
    c.value = hand-> cards[i]->value;
    c.suit = hand->cards[i]->suit;
    print_card(c);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  size_t i;
  for(i=0; i<(d->n_cards); i++){
    if((d->cards[i]->value ==c.value)&&(d->cards[i]->suit==c.suit)){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  int i;
  for(i=0; i< (*d).n_cards; i++){
    size_t j = i + rand()/(RAND_MAX/((*d).n_cards - 1) + 1);
    if(j< (*d).n_cards){
      card_t * temp = (*d).cards[j];
      (*d).cards[j] = (*d).cards[i];
      (*d).cards[i] = temp;
    }
    else{
      j = j%((*d).n_cards);
      card_t * temp = (*d).cards[j];
      (*d).cards[j] = (*d).cards[i];
      (*d).cards[i] = temp;
    }
  }
}

void assert_full_deck(deck_t * d) {
  int i=0;
  for(i=0; i< (*d).n_cards; i++){
    if( deck_contains(d, *(d->cards[i])) != 1){
      exit(EXIT_FAILURE);
    }
    int j;
    for(j=0; j<(d->n_cards); j++){
      if( (j!=i)&&( ((d->cards[j]->value) == (d->cards[i]->value))&&((d->cards[j]->suit) == (d->cards[i]->suit)))){
	exit(EXIT_FAILURE);
      }
    }
  }
}
void add_card_to(deck_t * deck, card_t c){
  if(deck ==NULL){
    deck = malloc(sizeof(*deck));
    deck->n_cards = 0;
  }
  if(deck->n_cards==0){
    deck->cards = NULL;
  }
  deck->cards = realloc(deck->cards, (deck->n_cards+1)*sizeof(*deck->cards));
  deck->cards[deck->n_cards]=calloc(1, sizeof(*(deck->cards[deck->n_cards])));
  deck->cards[deck->n_cards]->value = c.value;
  deck->cards[deck->n_cards]->suit = c.suit;
  deck->n_cards++;
}
card_t * add_empty_card(deck_t * deck){
  card_t *c=calloc(1, sizeof(*c));
  c->value = 0;
  c->suit = 0;
  deck->cards = realloc(deck->cards, (++(deck->n_cards))*sizeof(*deck->cards));
  deck->cards[deck->n_cards - 1]= c;
  return c;
}


int num_from_card(card_t c){
  int num;
  if(c.suit == SPADES){
    num = c.value -2;
  }
  else if(c.suit == HEARTS){
    num = 13 + c.value - 2;
  }
  else if(c.suit == CLUBS){
    num = 2*13 + c.value -2;
  }
  else if(c.suit == DIAMONDS){
    num = 3*13 + c.value -2;
  }
  else{
    perror("card contain wrong values\n");
    return EXIT_FAILURE;
  }
  return num;
}
    
//  Create a deck that is full EXCEPT for all the cards
//  that appear in excluded_cards
deck_t * make_deck_exclude(deck_t * excluded_cards){
  int exclu_num[max]={0};
  for(int i=0; i<excluded_cards->n_cards; i++){
    exclu_num[i] = num_from_card(*(excluded_cards->cards[i]));
  }
  
  deck_t *deck = calloc(1, sizeof(*(deck)));
  deck->n_cards=0;
  deck->cards = NULL;
  if(excluded_cards->n_cards>=52){
    return deck;
  }
  int ck=0;
  for(int i=0; i<52; i++){
    for(int j=0; j<excluded_cards->n_cards; j++){
      if(i == exclu_num[j]){
	ck++;
      }
    }
    
    if(ck == 0){
      deck->cards = realloc(deck->cards, (++(deck->n_cards))*sizeof(*(deck->cards)));
      deck->cards[i] = NULL;
      deck->cards[i] = realloc(deck->cards[i], sizeof(*(deck->cards[i])));
      card_t c = card_from_num(i);
      deck->cards[i]->value = c.value;
      deck->cards[i]->suit = c.suit;
    }
    ck =0;
  }
  return deck;
}

// this function builds the deck of cards that remain after the cards from the array of hands
// it takes as parameters have been removed from a full deck
deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands){
  deck_t *tober=malloc(sizeof(*tober));
  tober->n_cards=0;
  tober->cards = NULL;
  for(int i=0; i<n_hands; i++){
    for(int j=0; j<hands[i]->n_cards; j++){
      add_card_to(tober, *(hands[i]->cards[j]));
    }
  }
  deck_t *remaining = make_deck_exclude(tober);
  free_deck(tober);
  return remaining;
}
void free_deck(deck_t * deck){
  for(int i=0; i<deck->n_cards; i++){
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
