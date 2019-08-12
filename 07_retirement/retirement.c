#include <stdio.h>
#include <stdlib.h>
int current_age;

struct retire_inf{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct retire_inf rInf;

double  balance (rInf x, double initial, int startAge){
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
void retirement(int startAge, double initial, rInf working, rInf retired){
  initial = balance(working, initial, startAge);
  initial = initial + (initial * retired.rate_of_return) + retired.contribution;
  retired.months = retired.months - 2;
 initial =  balance(retired, initial, current_age);
}
int main(){
  rInf working, retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;
  retirement(327, 21345, working, retired);
}
