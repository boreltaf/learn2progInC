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
