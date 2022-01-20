#include <stdio.h>
/* Carter Biliato, 1132258, 1/17/2022
Uncomment the current question to reveal result */ 

/* Question 1: Implement a program to take a four-digit number from input and print it in reverse order */

int reverseOrder(int number){ //takes input from the function in main
    int temp, sum = 0; //initializing temporary and sum variables
    printf("The original integer value is: %d\n", number); //print original numbers

    for(int i = number; number != 0; number /= 10){ //start at the inputed number, go while that number does not equal 0, and take that number divide it by 10 and store in itself
         temp = number % 10; //temporary variable stores the remainder of the number modulus 10
         sum = sum * 10 + temp; //the temporary value is added to the sum multiplied by 10
    }
    printf("The reverse order of the number is: %d\n", sum);
}

/* Question 2: Implement a program that reads two numbers a and b and a character ch from input, and then:  
a. if ch equals '+', print the result of a + b,  
b. if ch equals '*', print the result of a * b,  
c. if ch equals '-', print the result of a - b.  
d. If ch is a character other than '+', '*' and '-', then print an error message */

int operators(int a, int b, char* symbol){ //takes input from function in main
    switch(*symbol){ //switch statement to test the input symbols
        case '+': //if this symbol
            printf("%d", a + b); //do the operation with the symbol input
            break;
        case '*':
            printf("%d", a * b);
            break;
        case '-':
            printf("%d", a - b);
            break;
        default: //does not pritn a proper symbol
            printf("did not put a proper symbol...");        
    }
}

/* Question 3: Implement a program that takes 5 numbers from input and prints the largest and smallest numbers */

int largeAndSmall(){ //takes no input from main, only from the function when called in main
    int numbers[5], smallest, largest, i; //initializing variables

    printf("Enter 5 numbers: \n"); 
    for(i = 0; i < 5; i++){
        scanf("%d", &numbers[i]); //receiving input for 5 numbers
    }

    printf("The 5 numbers are: \n");
    for(i = 0; i < 5; i++){
        printf("%d ", numbers[i]); //printing the inputed 5 numbers
    }

    largest = numbers[0]; //largest number equals the initial number in array
    for(i = 1; i <= 5; ++i){ //running through the 5 numbers in array
        if(largest < numbers[i]){ //if the largest variable is less than the number being compared to
            largest = numbers[i]; //then the largest variable number is now the current number
        }
    }
    printf("\nThe largest number is: %d", largest);

    smallest = numbers[0];
    for(i = 1; i <= 5; ++i){
        if(smallest > numbers[i]){ //if the smallest variable is greater than the number being compared to
            smallest = numbers[i]; //then the smallest variable number is now the current number
        }
    }
    printf("\nThe smallest number is: %d", smallest);
}

/* Question 4: Implement a function that takes an integer n as a parameter and calculates and returns the sum of all 
divisors of n. For example, if n = 6 then this function must return 12 */

int sumOfDivisors(int n){ //takes input from main 
    int i, sum = 0;

    for(i = 1; i <= n; i++){ //increments by 1 until the number inputed, starting at 1
        if(n % i == 0){ //if the current number in the loop has zero remainder when divided by n
            sum += i; //add that to the sum and update
        }
    }
    printf("The sum of the divisors of n are: %d", sum);
}

/* Question 5: Implement a function that takes an integer n as a parameter and checks whether n is a perfect number 
using the function defined in Question 4. If n is a perfect number, it returns 1, otherwise 0 (a number is 
a perfect number if it is equal to sum of its divisors excluding the number itself) */

int perfectNumber(int n){ 
    int i, sum = 0;

    for(i = 1; i <= n - 1; i++){ //increments by 1 until the number inputed minus 1, starting at 1
        if(n % i == 0){ //if the current number in the loop has zero remainder when divided by n
            sum += i; //add that to the sum and update
        }
        
    }
    if(sum == n){ //if the sum equals the number inputed
        printf("1"); //then it is a perfect number
    } else {
        printf("0"); //not a perfect number
    }
}

/* Question 6: Using the two functions defined for Question 4 and Question 5, implement a program that prints all the 
perfect numbers less than 10,000 in descending order */

int orderedPerfectNumbers(){
    int i, n, sum;

    for(i = 1; i < 10000; i++){ //increments by 1 until 9999, starting at 1
        sum = 0; //initialize variables
        n = 1;

        while(n < i){ //while n is less than i
            if(i % n == 0){ //if the current number in the loop has zero remainder when divided by n
                sum += n; //add that to the sum and update
            }
            n++; //increment n by 1
        }

        if (sum == i){ //if the sum is equivalent to i
            printf("%d\n", i); //print every iteration of i
        }  
    }
}

int main(){
    // reverseOrder(654); //Q1
    // operators(3, 4, "-"); //Q2
    // largeAndSmall(); //Q3
    // sumOfDivisors(14); //Q4
    // perfectNumber(29); //Q5
    orderedPerfectNumbers(); //Q6
}