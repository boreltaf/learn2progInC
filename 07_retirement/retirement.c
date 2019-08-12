#include <stdio.h>
#include <stdlib.h>
int current_age;

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double  balance (retire_info x, double initial, int startAge){
  int i=0;
  do{
     printf("Age %3d month %2d you have $%.2f\n", startAge/12, startAge%12, initial);
     initial = initial + (initial * x.rate_of_return) + x.contribution;
     startAge++;
     i++;
  } while(i<= x.months);
  initial = (initial - x.contribution)/(1 + x.rate_of_return);
  current_age = startAge;
  return initial;
}
void retirement(int startAge, double initial, retire_info working, retire_info retired){
  initial = balance(working, initial, startAge);
  initial = initial + (initial * retired.rate_of_return) + retired.contribution;
  retired.months = retired.months - 2;
 initial =  balance(retired, initial, current_age);
}
int main(){
  retire_info working, retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;
  retirement(327, 21345, working, retired);
}
