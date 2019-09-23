
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvpair_t *splitpair(char *line, size_t size){
  if(line==NULL){
    fprintf(stderr, "line is NULL\n");
    exit(EXIT_FAILURE);
  }
  if(size == 0){
    fprintf(stderr, "line does not containt any character\n");
    exit(EXIT_FAILURE);
    }
  kvpair_t *pair =malloc(sizeof(*pair));
  pair->key = NULL;
  pair->value =NULL;
  int i=0;
  while((line[i]!='=')&&(i<size)){
      pair->key = realloc(pair->key, (i+1)*sizeof(*(pair->key)));
      pair->key[i] = line[i];
      i++;
  };
  if(i==0){
     free(pair);
     fprintf(stdout, "there is not key\n");
     exit(EXIT_FAILURE);
    }
  if(i >= size-1){
    free(pair->key);
    free(pair);
    fprintf(stdout, "there is not value\n");
    exit(EXIT_FAILURE);
    }
  pair->key = realloc(pair->key, (i+1)*sizeof(*(pair->key)));
  pair->key[i]='\0';
  i++;
  int j=i;
  for(j=i; j<size; j++){
    pair->value = realloc(pair->value, (j-i+1)*sizeof(*(pair->value)));
    pair->value[j-i]=line[j];
  }
  pair->value = realloc(pair->value, (j-i+1)*sizeof(*(pair->value)));
  pair->value[j-i] = '\0';
  return pair;
}

kvarray_t * readKVs(const char * fname) {
  FILE *f = fopen(fname, "r");
  kvarray_t *kvarray=malloc(sizeof(*kvarray));
  kvarray->arraykv = NULL;
  char *line=NULL;
  size_t x=0;
  ssize_t lsize=0;
  int i=0;
  while((lsize=getline(&line, &x,f))>0){
    kvarray->arraykv = realloc(kvarray->arraykv, (i+1)*sizeof(*(kvarray->arraykv)));
    size_t size = lsize;
    kvarray->arraykv[i] = splitpair(line, size);
    i++;
    //line = NULL;
    free(line);
    line=NULL;
  }
  kvarray->kvlenght = (i>0)? i: i;
  free(line);
  if(kvarray->arraykv == NULL){
    fprintf(stdout, "the file was empty\n");
    return NULL;
  }
  if(fclose(f)!=0){
    fprintf(stderr, "the file couldn't close correctly\n");
    return NULL;
  }
  return kvarray;
}

void freeKVs(kvarray_t * pairs) {
  for(int i=0; i<pairs->kvlenght; i++){
    free(pairs->arraykv[i]->key);
    free(pairs->arraykv[i]->value);
    free(pairs->arraykv[i]);
  }
  free(pairs->arraykv);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  for(int i=0; i < pairs->kvlenght; i++){
    fprintf(stdout,"key = '%s' value = '%s'\n", pairs->arraykv[i]->key, pairs->arraykv[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for(int i=0; i < pairs->kvlenght; i++){
    if(strcmp(pairs->arraykv[i]->key, key)==0){
      return pairs->arraykv[i]->key;
    }
  }
  return NULL;
}
