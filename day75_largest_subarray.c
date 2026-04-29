#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0, maxLen = 0;

    // Simple hash map using array (since constraints are small enough)
    // Range of sum assumed manageable
    int map[10000];
    for (int i = 0; i < 10000; i++) map[i] = -2;

    int offset = 5000; // to handle negative sums

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // Case 2: seen before
        if (map[prefixSum + offset] != -2) {
            int len = i - map[prefixSum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            map[prefixSum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}