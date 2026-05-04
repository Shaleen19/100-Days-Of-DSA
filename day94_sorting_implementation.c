#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find maximum element
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Frequency array
    int freq[max + 1];

    for (int i = 0; i <= max; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Prefix sum
    for (int i = 1; i <= max; i++) {
        freq[i] += freq[i - 1];
    }

    // Build output array
    int output[n];

    for (int i = n - 1; i >= 0; i--) {
        output[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", output[i]);
    }

    return 0;
}