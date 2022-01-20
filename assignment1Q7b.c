#include <stdio.h>
/* Carter Biliato, 1132258, 1/17/2022
This assignment is will calculate which date inputed will come before or after one another*/ 

/*b. Implement a function that takes two parameters of the Date type and compares them.  
i. If the two parameters refer to the same date, the function returns zero,  
ii. If the first parameter is a date after the date of the second parameter, it returns +1, 
iii. If the first parameter is the date before the date of the second parameter, it returns -1 */

struct date{ //structure containing 3 integer values
    int month;
    int day;
    int year;
};

int compare(struct date first, struct date second){ //function that compares two dates with one another
    int result; //1 - comes after, -1 comes before
    
    if(first.year != second.year){ //if the first year does not equal the second year
        if(first.year > second.year){ //but is greater than second year
            result = 1; //comes after
        } else {
            result = -1;
        }
    } else if(first.month != second.month) { //if the first month does not equal the second month
        if(first.month > second.month){ //but is greater than second month
            result = 1; //comes after
        } else {
            result = -1;
        }
    } else if(first.day != second.day){ //if the first day does not equal the second day
        if(first.day > second.day){ //but is greater than second day
            result = 1; //comes after
        } else {
            result = -1;
        }
    } else {
        result = 0; //or else they are the same date
    }
    return result;
}

int main(){
    int day, month, year; //initializing date variables

    printf("Enter the month, day and year of the first date: \n"); //receiving first date information
    scanf("%d%d%d", &month, &day, &year);

    struct date first = {month, day, year}; //obtaining values into first date structure

    printf("Enter the month, day and year of the second date: \n"); //receiving second date information
    scanf("%d%d%d", &month, &day, &year);   

    struct date second = {month, day, year}; //obtaining values into second date structure

    int result = compare(first, second); //runs function to compare dates

    printf("\nThe First Date: %d/%d/%d\nThe Second Date: %d/%d/%d\n", first.month, first.day, first.year, second.month, second.day, second.year);

    if(result == 1) //if the value is 1, first date comes after the second date
        printf("The First Date comes after the Second Date!\n");
    else if(result == -1) //if the value is 1, first date comes before the second date
        printf("The First Date comes before the Second Date!\n");
    else //if the value is 0, same date
        printf("Both dates entered are the same date!\n");
    
}