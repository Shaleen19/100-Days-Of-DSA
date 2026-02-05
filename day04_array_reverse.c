// Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

#include <stdio.h>
#define N 10

int main(){
    int arr[N];

    printf("Enter %d elements in an array: ",N);
    for(int i = 0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    // Two-pointer approach to reverse the array
    int left = 0, right = N - 1;
    while(left < right){
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }

    printf("Reversed array: ");
    for(int i = 0; i<N; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}