#include <stdio.h>
#include <stdlib.h>
#include <string.h>
size_t maxSeq(int * array, size_t n);

int main(){
  int array1[]={1,1,1,1,1,1,11};
  int array2[]={1,2,5,3,2,1,6,7,8};
  int array3[1]={};
  int array4[]={9,8,7,6,5,4,3,2,1};
  int array5[]={100,16,166,16,1666};
  int array6[]={-5,-6,-7,-3,-2,7};
  int array7[]={3};
  int array8[]={5,100};
  int array9[]={1,5,5,6,7,7,8,9};
  int array10[]={-100,4,9,-10,0,-200};

  if( maxSeq(array1, 7)!=2){
    return EXIT_FAILURE;}
  else if( maxSeq(array2,9) !=4){
    return EXIT_FAILURE;}
  else if( maxSeq(array3,0) !=0){
    return EXIT_FAILURE;}
  else if( maxSeq(array4,9) !=1){
    return EXIT_FAILURE;}
  else if( maxSeq(array5,5) !=2){
    return EXIT_FAILURE;}
  else if( maxSeq(array6,6) !=4){
    return EXIT_FAILURE;}
  else if( maxSeq(array7,1) !=1){
    return EXIT_FAILURE;}
  else if( maxSeq(array8,2) !=2){
    return EXIT_FAILURE;}
  else if( maxSeq(array9,8) !=3){
    return EXIT_FAILURE;}
  else if( maxSeq(array10,6) !=3){
    return EXIT_FAILURE;}
  else{ printf("passed\n");
    return  EXIT_SUCCESS;}
}
