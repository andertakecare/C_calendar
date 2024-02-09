#include <stdio.h>
#include <stdbool.h>

bool isLeap(int);
int askForYear();

int main()
{
    printf("This program checks if a year is a leap year.\n");
    int year = askForYear();
    
    if (isLeap(year))
    {
        printf("%i is a leap year.\n", year);
    }
    else
    {
        printf("%i is not a leap year.\n", year);
    }
}

bool isLeap(int year)
{
    if (year % 4 != 0)
    {
        return false;
    }
    else if (year % 100 != 0)
    {
        return true;
    }
    else if (year % 400 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int askForYear()
{
    bool flag = true;
    int year;

    while (flag)
    {
        printf("Enter a year between 1800 and 10000:\n");
        if (scanf("%i", &year) == 1 && year >= 1800 && year <= 10000)
        {
            flag = false;
        }
        else
        {
            scanf("%*[^\n]"); // clear input buffer
            printf("Invalid input. Please try again.\n");
        }
    }

    return year;
}