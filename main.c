#include "NumClass.h"
#include <stdio.h>

int main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int factorialNum = factorial(num);

    printf("Factorial is %d \n", factorialNum);

}