#include <stdio.h>

// Check if boards can be painted within maxTime
int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (time + arr[i] <= maxTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

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

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            right = mid - 1;   // try smaller time
        } else {
            left = mid + 1;    // increase time
        }
    }

    printf("%d\n", ans);

    return 0;
}