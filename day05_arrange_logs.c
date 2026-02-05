#include <stdio.h>  

int main(){
    int p,q,k = 0;
    printf("Enter number of entries in log 1: ");
    scanf("%d",&p);

    int log1[p];
    printf("Enter entries for log 1 in ascending order:\n");
    for(int i=0;i<p;i++){
        scanf("%d",&log1[i]);
    }   


    printf("Enter number of entries in log 2: ");
    scanf("%d",&q);

    
    int log2[q];
    printf("Enter entries for log 2 in ascending order:\n");
    for(int i=0;i<q;i++){   
        scanf("%d",&log2[i]);
    }

    int new = p + q;
    int mergLog[new];

    int x = 0, y = 0;
    for(int i =0; i<new; i++){

        if(log1[x]<log2[y]){
            mergLog[k++] = log1[x++];
        }
        else if(log1[x] > log2[y]){
            mergLog[k++] = log2[y++];
        }
        else{
            mergLog[k++] = log1[x++];
            mergLog[k++] = log2[y++];
        }
        
    }

    // Handle remaining elements in log1
    while(x < p){
        mergLog[k++] = log1[x++];
    }
    // Handle remaining elements in log2
    while(y < q){
        mergLog[k++] = log2[y++];
    }

    printf("Merged log in chronological order:\n");
    for(int i=0;i<new;i++){
        printf("%d ",mergLog[i]);
    }
    printf("\n");

    return 0;
}