#include <cs50.h>
#include <stdio.h>


    void show(int sum , int totaldigit,int f1)
{

    if (sum % 10 == 0)
    {
        if (totaldigit == 15)
        {
            printf("AMEX\n");
        }
        else if (totaldigit == 16)
        {
           if (f1 == 4)
           {
             printf("VISA\n");
           }
           else{
            printf("MASTERCARD\n");
           }

        }
        else if (totaldigit == 13 || f1 == 4)
        {
            printf("VISA\n");
        }

    }
    else
    {
       printf("INVALID\n");
    }

}

int main(void)
{  long long int number ;


  number = get_long("number: ");

      int i = 1,digit,sum1 = 0,sum2 = 0,f1,f2;
      f1 = number /1000000000000000;
      while (number != 0)
      {
            digit = number % 10;
         if(i%2 == 0)
           {
              sum1 =sum1 + (digit * 2);
           }
           else
           {
             sum2 = sum2 + digit;
           }
           number = number / 10;
           i++;

      }
        sum1 =sum1 + sum2;
        sum2 = i-1;

        show(sum1 ,sum2 ,f1);
}