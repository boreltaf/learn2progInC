#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void rotate( char matrix[10][10]){
  if(matrix != NULL){
    int i,j;
    char Mcopy[10][10];
    for(i=0; i<10; i++){
      for(j=0; j<10; j++){
	Mcopy[i][j] = matrix[i][j];
      }
    }
    for(i=0; i<10; i++){
      for(j=0; j<10; j++){
	matrix[j][9 - i] = Mcopy[i][j];
      }
    }
  }
}

int main(int argc, char** argv){
  if( argc ==0){ printf("ERROR\n");
    return EXIT_FAILURE;
  }
  FILE * f=fopen(argv[1], "r");
  if(f==NULL){ printf("the file couldn't open\n");
    return EXIT_FAILURE;
  }
  char matrix[10][10];
  char c_line[11];
  int line_count =0;
  while( (fgets(c_line, 11, f))==NULL){
    if(strchr(c_line, '\n')==NULL){
      printf("This line is too long\n");
      return EXIT_FAILURE;
    }
    if(strlen(c_line)!=10){
      printf("THIS LINE IS TOO SHORT\n");
      return EXIT_FAILURE;
    }
    for(int i=0; i<10; i++){
      matrix[line_count][i] = c_line[i];
    }
    line_count++;
  }
  if(line_count != 10){
    return EXIT_FAILURE;
  }
  rotate(matrix);
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      fprintf(stdout,"%c", matrix[i][j]);
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
