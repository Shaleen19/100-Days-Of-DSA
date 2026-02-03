#include<stdio.h>
#define N 10

int main(){
    int arr[N], x,pos;
    printf("Enter %d elements: ", N-1);
    for(int i=0; i<N-1; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d",&x);
    printf("Enter the position: ");
    scanf("%d",&pos);

    for(int i = N-2; i>=pos; i--){
        arr[i+1] = arr[i];
    }
    arr[pos] = x;

    printf("Array after insertion:\n");
    for(int i = 0; i<N; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}