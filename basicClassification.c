#include "NumClass.h"
#include <stdio.h>

//This is not very efficient but will do for now.
int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    } else{
        return n * factorial(n-1);
    }
}

int isStrong(int n ){
    int sum = 0;
    int remainder = n;
    while (remainder != 0){
        int rightMostDigit = remainder % 10;
        sum += factorial(rightMostDigit);
        remainder = remainder / 10; //automatically rounds down
    }
    if(n == sum){
        return TRUE;
    }else{
        return FALSE;
    }
}

// We could've created a squareroot function and then iterated from 2 to sqrt(n) to slightly improve runtime (for smaller inputs)
// but overall, the runtime would be the same: 
// our isPrime() is O(n), while creating the suggested function would require finding the root, 
// (newtown-raphon method) which would cost O(log n)~ and then running from 2 to sqrt(n), in total:
// O(n + log n) = O(n) ---> Not worth implementing: runtime grows lineraly anyway for large inputs.

int isPrime(int n){
    if(n <= 1){
        return FALSE; //1,0 and negatives # are not primes
    }

    for(int i = 2; i<n;i++){
        if(n%i==0){
            return FALSE;
        }
    }
    return TRUE;
}

