
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

void assert_card_valid(card_t c) {
  assert((c.value >= 2)&&(c.value <= VALUE_ACE)&&((c.suit==SPADES)||(c.suit==HEARTS)||(c.suit==DIAMONDS)||(c.suit==CLUBS)));

}

const char * ranking_to_string(hand_ranking_t r) {
  
  if(r==STRAIGHT_FLUSH){
    return "STRAIGHT_FLUSH";
  }
  if(r==FOUR_OF_A_KIND){
    return "FOUR_OF_A_KIND";
  }
  if(r==FULL_HOUSE){
    return "FULL_HOUSE";
  }
  if(r==FLUSH){
    return "FLUSH";
  }
  if(r==STRAIGHT){
    return "STRAIGHT";
  }
  if(r==THREE_OF_A_KIND){
    return "THREE_OF_A_KIND";
  }
  if(r==TWO_PAIR){
    return "TWO_PAIR";
  }
  if(r==PAIR){
    return "PAIR";
  }
  if(r==NOTHING){
    return "NOTHING";
  }
  else{
    return "ERROR WRONG ENTRY";
  }
}

char value_letter(card_t c) {
  int i=0;
  for(i=2; i<=9; i++){
    if(c.value==i){
      return ('0'+i);
    }
  }
  if(c.value==10){
    return '0';
  }
  if(c.value==11){ return 'J';}
  if(c.value==12){ return 'Q';}
  if(c.value==13){ return 'K';}
  if(c.value==14){ return 'A';}
  else {
    printf("wrong value. the value should be between 2 and 14\n");
  }
  return '?';
}


char suit_letter(card_t c) {
  if(c.suit==SPADES){ return 's';}
  if(c.suit==HEARTS){ return 'h';}
  if(c.suit==DIAMONDS){ return 'd';}
  if(c.suit==CLUBS){ return 'c';}
  else{ return '?';}
  
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp.value=0;
  int i=0;  
  for(i=2; i<=9; i++){
    if(value_let == ('0'+i)){
      temp.value = i;
    }
  }
  if(temp.value==0){
    if(value_let=='0'){
      temp.value=10;
    }
    if(value_let=='J'){
      temp.value=11;
    }
    if(value_let=='Q'){
      temp.value=12;
    }
    if(value_let=='K'){
      temp.value=13;
    }
    if(value_let=='A'){
      temp.value=14;
    }
  }
  else{ printf("wrong entry\n");
  }
  
  if(suit_let=='s'){
    temp.suit=SPADES;
  }
  else if(suit_let=='h'){
    temp.suit=HEARTS;
  }
  else if(suit_let=='c'){temp.suit=CLUBS;}
  else if(suit_let=='d'){temp.suit=DIAMONDS;}
  else{ printf("WRONG ENTRY");
    
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  int j=0;
    if(c/13==0){ temp.suit=SPADES;}
    if(c/13==1){ temp.suit=HEARTS;}
    if(c/13==2){ temp.suit=CLUBS;}
    if(c/13==3){temp.suit=DIAMONDS;}
    for(j=0; j<13; j++){
     if(c%13==j){
      temp.value=j+2;
     }
    }
  
  return temp;
}
