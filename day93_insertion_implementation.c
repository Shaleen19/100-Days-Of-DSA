#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[100];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort (Stable)
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    // Output
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}