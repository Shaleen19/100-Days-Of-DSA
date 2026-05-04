#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    return i1->start - i2->start;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    Interval intervals[n];

    printf("Enter start and end of each interval:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    qsort(intervals, n, sizeof(Interval), compare);

    Interval merged[n];
    int k = 0;

    merged[k] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= merged[k].end) {
            if (intervals[i].end > merged[k].end) {
                merged[k].end = intervals[i].end;
            }
        } else {
            k++;
            merged[k] = intervals[i];
        }
    }

    printf("Merged intervals:\n");
    for (int i = 0; i <= k; i++) {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    return 0;
}