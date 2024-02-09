#include <stdio.h>
#include <stdbool.h> // for bool type
#include <limits.h> // for INT_MAX and INT_MIN

// Function prototypes
int intChecker();
bool isLeap(int);
int askForYear();
void calculateDate(int *month, int *day, int *year, int daysPassed);

// Global variables
const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 0 is a placeholder for the unused 0th index to make more logical to access based on month number

int main()
{
    printf("Welcome to the calendar program.\n");
    while (true) {
        int option = 0;
        printf("Please select an option:\n");
        printf("1. Calculate future date based on number of days passed.\n");
        printf("2. Check if a year is a leap year.\n");
        printf("3. Exit.\n");

        if(scanf("%i", &option) < 1 || scanf("%i", &option) > 3) {
            printf("Invalid input. Please try again.\n");
            scanf("%*[^\n]"); // clear input buffer
            continue;
        }
    }
    printf("This program calculates the date based on the number of days passed.\n");
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

int intChecker() {
    int option;
    if(scanf("%i", &option) == 1) {
        return option;
    } else {
        printf("Invalid input. Please try again.\n");
        scanf("%*[^\n]"); // clear input buffer
        return 0;
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

void calculateDate(int *month, int *day, int *year, int daysPassed)
{
    // TODO
}