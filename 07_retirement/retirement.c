#include<stdio.h>
#include<stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculate(double initial, retire_info info, int startAge)
{
  double final;
  int i;
  
  final= initial;
  for(i=0;i<info.months,i++)
    {
      printf("Age %3d month %2d  you have $%.2lf\n",startAge/12, startAge%12, res);
      final += final*(info.rate_of_return/12+info.contribution);
      startAge++;
    }
  return final;
}
void retirement( int startAge, double initial, retire_info working, retire_info retired)
{
  double worked;
  worked= calculate(initial, working, starAge);
  calculate(worked, retired, startAge+working.months);
  
}

int main()
{
  int 
}
