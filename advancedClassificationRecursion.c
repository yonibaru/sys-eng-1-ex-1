#include "NumClass.h"
#include <stdio.h>
#include <stdlib.h>


int calculateArmstrong(int num,int numLength){
    if (num>0){
        return (toPower(num % 10,numLength) + calculateArmstrong(num/10,numLength));
    } else{
        return 0;
    }
}
int isArmstrongRecursive(int n){
    
    int numLength = getNumLength(n);

    int result = calculateArmstrong(n,numLength);

    return(result == n);
}

int calculatePalindrome(int arr[],int start,int end){
    printf("%d, %d\n",arr[start],arr[end]);
    if(start>=end){
        return TRUE;
    } else if(arr[start] == arr[end]) {
        return (calculatePalindrome(arr,start + 1,end - 1));
    } else{
        return FALSE;
    }
}
int isPalindromeRecursive(int n){
  int numLength = getNumLength(n) - 1;

    int *arr;
    arr = (int *)malloc(numLength * sizeof(int)); 
    if(arr == NULL){return -1;} //Memory allocation failed.

    // Fill the empty array with the correct indices.
    int temp = n;
    for(int i=numLength;i>=0;i--){
        int tempNum = temp % 10;
        arr[i] = tempNum; 
        temp = temp / 10;
    }

    //arr = [1,2,3,3,2,1];
    int result = calculatePalindrome(arr,0,numLength);
    free(arr);
    return(result);
}
//isPalindromeRecursive() - returns "boolean" (0 or 1)