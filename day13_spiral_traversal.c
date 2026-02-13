#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int top = 0;
    int bottom = r - 1;
    int left = 0;
    int right = c - 1;

    while(top <= bottom && left <= right) {

        // 1️⃣ Traverse Top Row
        for(int i = left; i <= right; i++) {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // 2️⃣ Traverse Right Column
        for(int i = top; i <= bottom; i++) {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // 3️⃣ Traverse Bottom Row (if exists)
        if(top <= bottom) {
            for(int i = right; i >= left; i--) {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // 4️⃣ Traverse Left Column (if exists)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    return 0;
}
