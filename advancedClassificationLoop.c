#include "NumClass.h"
#include <stdio.h>
#include <stdlib.h>

//Non-recursive versions of isArmstrong and isPalindrome.

int getNumLength(int n){
    int digits = 0;
    int temp = n;
    while(temp > 0){
        temp = temp / 10;
        digits++;
    }
    return digits;
}
int toPower(int n,int power){
    int result = n;
    for (int i = 0; i < power - 1; ++i) {
      result *= n;
    }
    return result;
}
int isArmstrong(int n){
    int sum = 0;

    int numLength = getNumLength(n);
    int num = n;
    //Iterate through the number and calculate
    while(num > 0 ){
        int rightMostDigit = num % 10;
        sum += toPower(rightMostDigit,numLength);
        num = num / 10;
    }

    if(sum == n){
        return TRUE;
    }else{
        return FALSE;
    }
}

//The idea: create an array, each index i holds the digits at the i'th position of the number. 
//this makes it very easy to iterate upon every digit. 

int isPalindrome(int n){
    int numLength = getNumLength(n) - 1;

    int *arr;
    arr = (int *)malloc(numLength * sizeof(int)); 
    if(arr == NULL){return -1;} //Memory allocation failed.

    // Fill the empty array with the correct values.
    int temp = n;
    for(int i=numLength;i>=0;i--){
        int tempNum = temp % 10;
        arr[i] = tempNum; 
        temp = temp / 10;
    }

    int start = 0;
    int end = numLength;

    while(start<end){
        if(arr[start] != arr[end]){
            free(arr);
            return FALSE;
        }
        start++;
        end--;
    }

    free(arr);
    return TRUE;
}
