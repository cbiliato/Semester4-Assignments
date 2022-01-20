#include <stdio.h>
/* Carter Biliato, 1132258, 1/17/2022
This assignment is will calculate the next date given the current date inputed */ 

/* Question 7: 7. Define a structure called Date that contains 3 members: year, month, and day. Then:  
a. Implement a function called getNextDate that takes a Date parameter and returns a Date which 
is 1 day after the date of the input parameter. For example, if the function’s input is equal to 
1/6/2022, the function must return 1/7/2022. (Do not consider leap years.) */

struct date { //structure containing the variables that make up a date
    int month;
    int day;
    int year;
};


struct date getNextDate(struct date now){ //function that returns the next day when given current
    now.day++; //increment date by 1

    if(now.month == 1 || now.month == 3 || now.month == 5 || now.month == 7 || now.month == 8 || now.month == 10 || now.month == 12){ //current months with 31 days
        if(now.day > 31){ //if over 31 days
            now.day = 1; //start first day of next month
            now.month++;
        }
    } else if(now.month == 4 || now.month == 6 || now.month == 9 || now.month == 11){ //current months with 30 days
        if(now.day > 30){ //if over 30 days
            now.day = 1; //start first day of next month
            now.month++;
        }
    } else {
        if(now.day > 28){ //february, if over 28 days
            now.day = 1; //start first day of next month
            now.month++;
        }
    }
    if(now.month > 12){ //if over the amount of months in year
        now.month = 1; //start new month first day
        now.day = 1;
        now.year++; //start new year
    }
    return now;
};

int main(){   
    int day, month, year; //variables for date
    printf("Enter the month day and year:"); //receive user input
    scanf("%d %d %d", &month, &day, &year);

    struct date now = {month, day, year}; //save the date entered into the date structure
    struct date nextDay = getNextDate(now); //computing what the next day is

    printf("The next day is %d/%d/%d", nextDay.month, nextDay.day, nextDay.year); //displaying what the next day is
}