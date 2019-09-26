
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t *countStruct =NULL;
  countStruct =  malloc(1*sizeof(*(countStruct)));
  countStruct->countArray=NULL;
  countStruct->countArray=  malloc(3*sizeof(*(countStruct->countArray)));
  for(int i=0; i<3; i++){
    countStruct->countArray[i]=malloc(sizeof(*(countStruct->countArray[i])));
    }
  countStruct->countArray[0]->name="Captain";
  countStruct->countArray[1]->name="Commander";
  countStruct->countArray[2]->name="Lt. Commander";
  countStruct->countArray[0]->count=0;
  countStruct->countArray[1]->count=0;
  countStruct->countArray[2]->count=0;
  countStruct->lenght=3;
  countStruct->unknown=0;
  return countStruct;
}

int check(char *c, const char *d){
  if(d==NULL){
    return 0;
  }
  size_t lenght1= strlen(c);
  size_t lenght2= strlen(d);
  if(lenght1 == lenght2){
    for(int i=0; i<lenght1; i++){
      if(c[i]!=d[i]){
	return 0;
      }
    }
    return 1;
  }
  return 0;
}
void addCount(counts_t * c, const char * name) {
  if(name==NULL){
    c->unknown++;
  }
  for(int i=0; i<c->lenght; i++){
    if(check(c->countArray[i]->name, name)){
      c->countArray[i]->count++;
    }
  }
}

void printCounts(counts_t * c, FILE * outFile) {
  /* if(c->lenght==0){
    ;
    }*/
  for(int i=0; i<c->lenght; i++){
    fprintf(outFile, "%s: %lu\n", c->countArray[i]->name, c->countArray[i]->count);
  }
  if(c->unknown!=0){
    fprintf(outFile, "<unknown> : %lu\n", c->unknown);
  }
}

void freeCounts(counts_t * c) {
  for(int i=0; i<c->lenght; i++){
    free(c->countArray[i]);
  }
  free(c->countArray);
  free(c);
}
