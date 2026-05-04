#include <stdio.h>

#define MAX 100000

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);
        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX], temp[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSort(arr, temp, 0, n - 1);

    printf("%lld\n", result);

    return 0;
}