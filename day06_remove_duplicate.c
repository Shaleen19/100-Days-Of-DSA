#include <stdio.h>

int main(){
    int l,count;

    printf("Enter number of elements in an array: ");
    scanf("%d",&l);

    int arr[l];
    printf("Enter elements in ascending order:\n");
    for(int i=0;i<l;i++){
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i< l; i++){
        count = 0;

        for(int j = i;j<l-1; j++){
            if(arr[j] == arr[j+1]){
                count++;
            }
        }

        if(count >=1){
            printf("%d ",arr[i]);
            i++; // Skip the next element since it's a duplicate
        }
    }
}