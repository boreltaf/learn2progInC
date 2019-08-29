#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int main(int argc, char **argv){
  char arr_alpha[26];
  int key;
  int count[26] = {0}; // array that will contains the count of each letter in the alphabet found in the input. 
  for(int i=0; i<26; i++){  // we fill this array with lower case alphabet letters.
    arr_alpha[i]= 'a'+i;
  }
  if(argc != 1){ fprintf(stderr,"The program only takes one argument\n");
    return EXIT_FAILURE;
  }
  FILE * f= fopen(argv[0], "r");
  if( f==NULL){
    fprintf(stderr, "the file in not open\n");
    return EXIT_FAILURE;
  }
  int c;
  while( (c=fgetc(f)) != EOF){
    if( isalpha(c)){
      c = tolower(c); // we will count base on the lower case. so we need to convert all uppercase to lowercase
      for(int i=0; i<26; i++){
	if( c == arr_alpha[i]){
	  count[i]++;         // we count the frequency of each letter found.
	}
      }
    }
  }
  int max =0;
  for(int i=0; i<26; i++){
    if(max< count[i]){
      max = count[i];
    }
  }
  assert((max !=0)&&(max < 26));
  key = arr_alpha[max] - 'e';
  printf("%d\n", key);
  return EXIT_SUCCESS;
}
  
