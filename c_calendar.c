#include <stdio.h>
#include <stdbool.h> // for bool type
#include <limits.h>  // for INT_MAX and INT_MIN
// #include <time.h>    // for getting current date

// Function prototypes
int inputChecker(int min, int max);
bool isLeap(int);
int askForYear();
void calculateDate(int *month, int *day, int *year, int daysPassed);
void clearInputBuffer();

// Global variables
const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 0 is a placeholder for the unused 0th index to make more logical to access based on month number

int main()
{
    // char [] currDate = getCurrDate();
    printf("Welcome to the calendar program.\n");
    while (true)
    {
        int option = 0;
        printf("Please select an option:\n");
        printf("1. Calculate future date based on number of days passed.\n");
        printf("2. Check if a year is a leap year.\n");
        printf("3. Exit.\n");
        option = inputChecker(1, 3);

        switch(option)
        {
            case 1:
                printf("This program calculates the date based on the number of days passed.\n");
                // calculateDate();
                break;
            case 2:
                printf("This program checks if a year is a leap year.\n");
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
        }

        // if (scanf("%i", &option) < 1 || scanf("%i", &option) > 3)
        // {
        //     printf("Invalid input. Please try again.\n");
        //     scanf("%*[^\n]"); // clear input buffer
        //     continue;
        // }
    }

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

int inputChecker(int min, int max)
{
    int option;
    while (true)
    {
        if ((scanf("%i", &option) == 1) && (option >= min && option <= max))
        {
            printf("%s\n", "This worked DELETE ME!");
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
        clearInputBuffer();
    }
    clearInputBuffer();
    return option;
}

void clearInputBuffer()
{
    scanf("%*[^\n]"); // clear input buffer
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

void calculateDate(int *month, int *day, int *year, int daysPassed)
{
    // TODO
}