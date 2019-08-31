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
  for(int p=0; p<26; p++){  // we fill this array with lower case alphabet letters.
    arr_alpha[p]= 'a'+ p;
  }
  if(argc != 2){ fprintf(stderr,"The program only takes 3 arguments\n");
    return EXIT_FAILURE;
  }
  FILE * f= fopen(argv[1], "r");
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
  for(int j=0; j<26; j++){
    if(max < count[j]){
      max = count[j];
      ind = j;
    }
  }
  key = (ind + 22)%26;
  fprintf(stdout,"%d\n", key);
  if(fclose(f)!=0){
    printf("failed to close the file\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
  
