#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

int main(int argc, char **argv){
  unsigned count[26]={0};  // array that will contains the count of each letter in the alphabet found in the input.                         
  if(argc != 2){ fprintf(stderr,"The program only takes 3 arguments\n");
    return EXIT_FAILURE;
  }
  FILE * f= fopen(argv[1], "r");
  if( f==NULL){
    fprintf(stderr, "the file in not open\n");
    return EXIT_FAILURE;
  }
  int c, i, d;
  while( (c = fgetc(f)) != EOF){
    if( isalpha(c)){
      c = tolower(c); // we will count base on the lower case. so we need to convert all uppercase to lowercase
      d = c - 'a';
      assert((d>=0)&&(d<26));
      count[d]++;         // we count the frequency of each letter found.
    }
  }
  unsigned max =0;
  int ind=0;
  for(i=0; i<26; i++){
    if(max < count[i]){
      max = count[i];
      ind = i;
    }
  }
  int key = (ind + 22)%26;
  fprintf(stdout,"%d\n", key);
  if(fclose(f)!=0){
    printf("failed to close the file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
  
