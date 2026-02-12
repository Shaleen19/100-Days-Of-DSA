#include <stdio.h>
int is_symmetric(int r, int c, int arr[r][c]);

int is_symmetric(int r, int c, int arr[r][c]){

    if(r != c){
        return 0;
    }

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(arr[i][j] != arr[j][i]){
                return 0;
            }
        }
    }

    return 1;

}

int main(){

    int r,c;
    printf("Enetr row and  column of matrix: ");
    scanf("%d%d",&r,&c);

    int arr[r][c];

    printf("Enter element in  matrix: ");
    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    if(is_symmetric(r,c,arr)){
        printf("Matrix is symmetric\n");
    }else{
        printf("Matrix is not symmetric\n");
    }

}