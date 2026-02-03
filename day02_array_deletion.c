#include <stdio.h>
#define N 10

int main(){
    int arr[N], pos,item;

    printf("Enter %d elements: ",N);
    for(int i = 0; i<N; i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the position of the elemnt to be deleted: ");
    scanf("%d",&pos);
    item = arr[pos];

    for(int i = pos; i<N-1; i++){
        arr[i] = arr[i+1];
    }
    printf("Array after deletion of %d:\n", item);
    for(int i = 0; i<N-1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Deleted item is: %d\n", item);
    return 0;
}