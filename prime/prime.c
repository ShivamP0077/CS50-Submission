#include <cs50.h>
#include <stdio.h>

int prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

int prime(int number)
{
    for(int i ; i<= number ;i++){
        if(number% i == 0){
            return 0;
        }
        else{
        return 1;
        }
    }

}
