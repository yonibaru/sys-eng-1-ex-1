#include "NumClass.h"
#include <stdio.h>
#include <limits.h>
#include "advancedClassificationRecursion.c"
#include "advancedClassificationLoop.c"
#include "basicClassification.c"

int main(){
        int number1,number2;

        // We check if the user enters valid positive integers - 0 is not positive.
        // This is to avoid errors within my functions.
        while(TRUE){
            scanf("%d", &number1);
            if(number1 > 0 && number1 < INT_MAX){
                break;
            }
        }
        while(TRUE){
            scanf("%d", &number2);
            if(number2 > 0 && number2 < INT_MAX){
                break;
            }
        } 

        // I'm aware the following is ineffective: Looping over the same thing 4 times.
        // Unfortunately, we don't have Strings or ArrayLists to store the numbers.
        // As per the text output examples, there could be massive numbers and creating an array of size 1-2 billion is just isn't feasible and will probably just cause our program to crash.

        printf("The Armstrong numbers are:");

        for(int i = number1; i<=number2; i++){
            if(isArmstrong(i)){
                printf(" %d",i);
            }
        }
        printf("\nThe Palindromes are:");

        for(int i = number1; i<=number2; i++){
            if(isPalindrome(i)){
                printf(" %d",i);
            }
        }
        printf("\nThe Prime numbers are:");

        //This is incredibily slow but I think we're supposed to use our required functions here and since they only need to recieve one arugment (int n) so I can't do anything to speed it up.
    
        for(int i = number1; i<=number2; i++){
            if(isPrime(i)){
                printf(" %d",i);
            }
        }
        printf("\nThe Strong numbers are:");

        for(int i = number1; i<=number2; i++){
            if(isStrong(i)){
                printf(" %d",i);
            }
        }
        
        printf("\n");

}