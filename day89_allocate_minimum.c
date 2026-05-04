#include <stdio.h>

// Check if we can allocate with maxPages limit
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[100];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int left = max;
    int right = sum;
    int ans = sum;

    // Binary Search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            right = mid - 1;   // try smaller
        } else {
            left = mid + 1;    // increase limit
        }
    }

    printf("%d\n", ans);

    return 0;
}