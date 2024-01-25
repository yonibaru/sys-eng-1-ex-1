#include "NumClass.h"
#include <stdio.h>

int main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int temp = isPalindrome(num);

    printf("RESULT: %d \n", temp);
}