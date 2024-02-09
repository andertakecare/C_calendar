#include <stdio.h>
#include <stdbool.h> // for bool type
#include <limits.h>  // for INT_MAX and INT_MIN
#include <time.h>    // for getting current date
#include <string.h>  // for string manipulation

// Function prototypes
int askForYear();
int askForDays();
void calculateDate(int year, int month, int day, int daysToPass);
void getCurrDate();
void clearInputBuffer();
int inputChecker(int min, int max);
bool isLeap(int);

// Global variables
int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 0 is a placeholder for the unused 0th index to make more logical to access based on month number
char currDate[11];

int main()
{
    printf("\n");
    printf("Welcome to the calendar program.\n");
    printf("\n");
    while (true)
    {
        getCurrDate();
        int year;
        int month;
        int day;
        sscanf(currDate, "%d/%d/%d", &year, &month, &day);

        int option = 0;
        printf("Please select an option:\n");
        printf("1. Calculate future date based on number of days passed.\n");
        printf("2. Check if a year is a leap year.\n");
        printf("3. Exit.\n");
        option = inputChecker(1, 3);

        switch (option)
        {
        case 1:
            printf("This program calculates the date based on the number of days passed.\n");

            int daysToPass = askForDays();
            // printf("The date %i days from now will be: \n", daysToPass);
            calculateDate(year, month, day, daysToPass);
            break;
        case 2:
            printf("I can check if a year is going to be a leap year!.\n");
            int yearToCheck = askForYear();
            if (isLeap(yearToCheck))
            {
                if (yearToCheck < year)
                {
                    printf("%i was a leap year.\n", yearToCheck);
                }
                else if (yearToCheck == year)
                {
                    printf("%i is a leap year.\n", yearToCheck);
                }
                else
                {
                    printf("%i will be a leap year.\n", yearToCheck);
                }
            }
            else
            {
                if (yearToCheck < year)
                {
                    printf("%i was not a leap year.\n", yearToCheck);
                }
                else if (yearToCheck == year)
                {
                    printf("%i is not a leap year.\n", yearToCheck);
                }
                else
                {
                    printf("%i will not be a leap year.\n", yearToCheck);
                }
            }
            printf("\n");
            break;
        case 3:
            printf("Exiting program.\n");
            return 0;
        }
    }
}

int inputChecker(int min, int max)
{
    int option;
    while (true)
    {
        if ((scanf("%i", &option) == 1) && (option >= min && option <= max))
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
            printf("\n");
        }
        clearInputBuffer();
    }
    printf("\n");
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
        printf("Enter a year between 1800 and 100000:\n");
        if (scanf("%i", &year) == 1 && year >= 1800 && year <= 100000)
        {
            flag = false;
        }
        else
        {
            scanf("%*[^\n]"); // clear input buffer
            printf("Invalid input. Please try again.\n");
        }
    }
    printf("\n");

    return year;
}

int askForDays()
{
    bool flag = true;
    int daysToPass;

    while (flag)
    {
        printf("Enter the number of days you want to move into the future:\n");
        if (scanf("%i", &daysToPass) == 1 && daysToPass >= 0 && daysToPass <= INT_MAX)
        {
            flag = false;
        }
        else
        {
            scanf("%*[^\n]"); // clear input buffer
            printf("Invalid input. Please try again.\n");
        }
    }
    printf("\n");
    return daysToPass;
}

void calculateDate(int year, int month, int day, int daysToPass)
{
    // Copying the current date to future date
    int futureYear = year;
    int futureMonth = month;
    int futureDay = day;
    // printf("The current date is: %i/%i/%i\n", year, month, day);
    // printf("The number of days to pass is: %i\n", daysToPass);
    printf("The date %i days from now will be:\n", daysToPass);

    while (daysToPass > 0)
    {
        if (isLeap(futureYear))
        {
            daysInMonth[2] = 29;
        }
        else
        {
            daysInMonth[2] = 28;
        }
        int daysLeftInMonth = daysInMonth[futureMonth] - futureDay;
        // printf("Days left in month: %i\n", daysLeftInMonth);
        if (daysToPass < daysLeftInMonth)
        {
            futureDay += daysToPass;
            daysToPass = 0;
        }
        else
        {
            daysToPass -= daysLeftInMonth;
            futureDay = 0;
            futureMonth++;
            if (futureMonth > 12)
            {
                futureMonth = 1;
                futureYear++;
            }
        }
    }
    printf("%i/%i/%i\n", futureYear, futureMonth, futureDay);
    printf("\n");
}

void getCurrDate()
{
    // Get current time
    time_t current_time;
    struct tm *local_time;

    time(&current_time);
    local_time = localtime(&current_time);
    // char currDate[11];
    strftime(currDate, sizeof(currDate), "%Y/%m/%d", local_time);
    printf("The current date is: %s\n", currDate);
    printf("\n");
}
