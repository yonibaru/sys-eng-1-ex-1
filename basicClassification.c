#include "NumClass.h"
#include <stdio.h>

int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    } else{
        return n * factorial(n-1);
    }
}

//isPrime() - returns "boolean" (0 or 1)
//isStrong() - returns "boolean" (0 or 1)