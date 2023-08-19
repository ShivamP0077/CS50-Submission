#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<math.h>

const int BITS_IN_BYTE = 8;


void print_bulb(int bit);

void convert_binary(int number,int length)
{
    int digit,reminder,arr[8];

   for(int i = 0 ; i <8 ; i++)
   {
      reminder = number%2;
      digit = number/2;
      number = digit;
      arr[i] = reminder;

   }

   for(int i = 0 ; i< 8 ;i++)
   {
     print_bulb(arr[7-i]);
   }
   printf("\n");

}


int main(void)
{
    // TODO
    string str = get_string("Message: ");
    int num;
    for(int i = 0, l = strlen(str); i < l ; i++)
    {
        num = (int)str[i];
        convert_binary(num,l);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
