#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int main(int argc, char **argv){
  char arr_alpha[26];
  int key;
  int count[26];  // array that will contains the count of each letter in the alphabet found in the input.
  for(int i=0; i<26; i++){
    count[i] = 0;
  }                          
  for(int i=0; i<26; i++){  // we fill this array with lower case alphabet letters.
    arr_alpha[i]= 'a'+i;
  }
  if(argc == 1){ fprintf(stderr," you enter one argc. The program takes 2 arguments\n");
    return EXIT_FAILURE;
  }
  if(argc != 2){ fprintf(stderr,"The program only takes 3 arguments\n");
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
  int ind=0;
  for(int i=0; i<26; i++){
    if(max <= count[i]){
      max = count[i];
      ind = i;
    }
  }
  
  assert(max !=0);
  key = arr_alpha[ind] - 'e';
  fprintf(stdout,"%d\n", key);
  return EXIT_SUCCESS;
}
  
