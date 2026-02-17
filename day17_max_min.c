#include <stdio.h>

int main(){

    int n,max ,min;
   
    printf("Enter size of an array: ");
    scanf("%d",&n);
     int arr[n];

    printf("Enter %d element in an array: ",n);
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(int i = 1; i<n ;i++){
        for(int j = 1; j<n; j++){
            if(arr[j]>max)
                max = arr[j];
            if(arr[j]<min)
                min = arr[j];
        }
    }

    printf("Max: %d\nMin: %d\n",max,min);

    return 0;
}