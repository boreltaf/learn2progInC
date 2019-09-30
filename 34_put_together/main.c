#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  FILE *f=fopen(filename, "r");
  counts_t *c=createCounts();
  if((f==NULL)||(c==NULL)){
    fprintf(stderr, "the file couldn't open or c haven't been created\n");
    return c;
  }
  /*for(int j=0; j<kvPairs->kvlenght; j++){
    addCount(c, kvPairs->arraykv[j]->value);
  }*/
  size_t  x=0;
  char *line=NULL;
  while(getline(&line, &x, f)>0){
    line[strlen(line)-1]='\0';
    char* Cvalue = lookupValue(kvPairs, line);   // lookupValue will check if there is a key equivlent to line and return the value of \that key if there is. if not, it will return a null pointer.
    addCount(c, Cvalue);
    Cvalue=NULL;
  }
  free(line);
  if(fclose(f)!=0){
    fprintf(stderr, "the file couldn't close\n");
  }
  return c;
}

int main(int argc, char ** argv) {
  if(argc<3){          //WRITE ME (plus add appropriate error checking!)
    fprintf(stderr, " this program takes at least 3 arguments\n");
    return EXIT_FAILURE;
  }
  
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  kvarray_t *kv= readKVs(argv[1]);
 //count from 2 to argc (call the number you count i)
  for(int i=2; i<argc; i++){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t *c= countFile(argv[i], kv);
    //compute the output file name from argv[i] (call this outName)
    char *outName= computeOutputFileName(argv[i]);


    //open the file named by outName (call that f)
    FILE *f=fopen(outName, "w");
    

    //print the counts from c into the FILE f
    printCounts(c, f);;
    //close f
    if(fclose(f)!=0){
      fprintf(stderr, "ERROR when closing the file\n");
      return EXIT_FAILURE;
    }
    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }


 //free the memory for kv
    freeKVs(kv);    

  return EXIT_SUCCESS;
}
