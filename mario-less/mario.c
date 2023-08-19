#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int hight;
    do
    {
        hight = get_int("Height: ");
    }
    while (hight <= 0 || hight >= 9);



    for (int i = 1 ; i <= hight ; i++)
    {
        int space = hight - i;
        while (space)
        {
            printf(" ");
            space--;
        }
        for (int j = 1 ; j <= i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}