#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int compare(const void* a, const void* b) {
    double x = *(double*)a;
    double y = *(double*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    double arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    double buckets[MAX][MAX];
    int bucketCount[MAX] = {0};

    // Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n;
        buckets[index][bucketCount[index]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < n; i++) {
        qsort(buckets[i], bucketCount[i], sizeof(double), compare);
    }

    // Concatenate buckets back into array
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }

    return 0;
}