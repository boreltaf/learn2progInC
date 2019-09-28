
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t *countStruct =NULL;
  countStruct =  realloc(countStruct, 1*sizeof(*(countStruct)));
  countStruct->countArray=NULL;
  countStruct->lenght=0;
  countStruct->unknown=0;
  return countStruct;
}
/*
int check(const char *c, const char *d){
  if((d==NULL)||(c==NULL)){
    return 0;
  }
  size_t lenght1= strlen(c);
  size_t lenght2= strlen(d);
  if(lenght1 == lenght2){
    for(int i=0; i<lenght2; i++){
      if(c[i]!=d[i]){
	return 0;
      }
    }
    return 1;
  }
    if(j==lenght2){
    return 1;
    }
  return 0;
}*/

void createStringCp(size_t len, const char *name, counts_t *c){
  char *string=NULL;
  string = calloc((len+1), sizeof(char));
  for(int i=0; i<len; i++){
    string[i]=name[i];
  }
  c->countArray=realloc(c->countArray, ((++c->lenght)*sizeof(*(c->countArray))));
  c->countArray[c->lenght-1]=NULL;
  c->countArray[c->lenght-1]=realloc(c->countArray[c->lenght-1], sizeof(*(c->countArray[c->lenght-1])));
  c->countArray[c->lenght-1]->name=string;
  c->countArray[c->lenght-1]->count=1;
  string=NULL;
  free(string);
  return;
}

void addCount(counts_t * c, const char * name) {
  if(name==NULL){
    c->unknown++;
    return;
  }
  for(int i=0; i<c->lenght; i++){
    if(strcmp(c->countArray[i]->name, name)==0){
      c->countArray[i]->count++;
      return;
    }
  }
  createStringCp(strlen(name), name, c);
}

void printCounts(counts_t * c, FILE * outFile) {
  if(c->lenght==0){
    return;
    }
  for(int i=0; i<c->lenght; i++){
    const char *h=c->countArray[i]->name;
    fprintf(outFile, "%s: %lu\n", h, c->countArray[i]->count);
  }
  if(c->unknown!=0){
    fprintf(outFile, "<unknown> : %lu\n", c->unknown);
  }
}

void freeCounts(counts_t * c) {
  for(int i=0; i<c->lenght; i++){
    free(c->countArray[i]->name);
    free(c->countArray[i]);
  }
  free(c->countArray);
  free(c);
}
