#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_words(string str)
{
    int count = 0;
    for (int i = 0, l = strlen(str); i <= l; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int count_sentance(string str)
{
    int count = 0;
    for (int i = 0, l = strlen(str); i <= l; i++)
    {
        if (str[i] == '!' || str[i] == '.' || str[i] == '?')
        {
            count++;
        }
    }
    return count;
}

int count_letters(string str)
{
    int count = 0;
    for (int i = 0, l = strlen(str); i <= l; i++)
    {

        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        if (str[i] >= 65 && str[i] <= 122)
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
    string str = get_string("Text: ");
    int latter = count_letters(str);
    int sentance = count_sentance(str);
    int words = count_words(str);
    float l, s;
    l = (float)latter / words * 100;
    s = (float)sentance / words * 100;
    float grade = (0.0588 * l - 0.296 * s - 15.8);

    if (grade < 0)
    {
        printf("Before Grade %.0f\n", 1.0);
    }
    else if (grade >= 16)
    {
        printf("Grade %.0f+\n", 16.0);
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
}