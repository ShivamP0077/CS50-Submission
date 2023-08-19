#include <cs50.h>
#include <stdio.h>

int main(void)
{

  int start,years = 0;
  do{
  start = get_int("start : ");
  }while(start < 9);

   int end;
  do{
  end = get_int("end : ");
  }while(end < start);

   int pop = start;
   do{
    pop = pop + (pop/3) - (pop/4);
    years++;
    if(pop == end || pop > end){
        printf("Years: %i\n",years);
    }
   }while(pop < end);
}
