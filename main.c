#include "NumClass.h"
#include <stdio.h>
#include <limits.h>

int main(){
    int num;

    printf("Enter an integer number (no bigger than %d): ",INT_MAX);
    scanf("%d", &num);


    int temp1 = isPalindromeRecursive(num);
    int temp2 = isPalindrome(num);

    printf("isPalindromeRecursive: %d \n", temp1);
    printf("isPalindrome: %d \n", temp2);

}