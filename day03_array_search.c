#include <stdio.h>

int main(){
    int size,key,count = 0;

    printf("Enter size of an array: ");
    scanf("%d",&size);
    int arr[size];

    printf("Enter Elements in an array: ");
    for(int i = 0; i<size; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter key to be serached: ");
    scanf("%d",&key);

    for(int i = 0; i<size; i++){
        count++;
        if(arr[i] == key){
            printf("Key %d found at index %d\n",key,i);
            printf("Number of comparisons: %d\n",count);
            break;
        }
    }
    return 0;
}