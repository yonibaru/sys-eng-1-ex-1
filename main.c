#include "NumClass.h"
#include <stdio.h>
#include <limits.h>

int main(){
        int number1,number2;
        printf("Enter the first number: ");

        while(TRUE){
            scanf("%d", &number1);
            if(number1 > 0 && number1 < INT_MAX){
                break;
            }
        }

        printf("Enter the second number: ");

        while(TRUE){
            scanf("%d", &number2);
            if(number2 > 0 && number2 < INT_MAX){
                break;
            }
        }    

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