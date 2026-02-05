#include <stdio.h>
int main() {
    int k = 0,numsSize,val;
    printf("Enter size of array: ");
    scanf("%d" , &numsSize);

    int nums[numsSize];
    printf("Enter %d element in array: ",numsSize);
    for(int i = 0; i<numsSize; i++){
        scanf("%d" ,&nums[i]);
    }

    printf("Enter value to be checked: ");
    scanf("%d",&val);

    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    printf("%d\n",k);
    return 0;
}
