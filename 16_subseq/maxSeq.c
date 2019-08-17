#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  int i=0, j=1;
  if(n==0){ return 0;}
  else {
    int max[n];
    for(i=0;i<n;i++){
      max[i]=0;
    }
  for(i=0; i<n; i++){
    while((array[i]<array[i+1])&&((i+1)<n)){
    j++;
    i++;
    };
    max[i] = j;
    j=1;
  }
  size_t maxseq = max[0];
  for(i=0; i<n; i++){
    if(maxseq<=max[i]){
      maxseq = max[i];
    }
  }
  return maxseq;
  }
}
