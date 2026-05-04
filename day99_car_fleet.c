#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compare(const void *a, const void *b) {
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c2->position - c1->position; 
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    return fleets;
}

int main() {
    int target, n;

    printf("Enter target distance: ");
    scanf("%d", &target);

    printf("Enter number of cars: ");
    scanf("%d", &n);

    int position[n], speed[n];

    printf("Enter positions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }

    printf("Enter speeds:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}