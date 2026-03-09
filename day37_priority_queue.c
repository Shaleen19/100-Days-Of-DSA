#include <stdio.h>

#define MAX 100

int pq[MAX];
int n = 0;

// Insert element
void insert(int value)
{
    if (n == MAX)
    {
        printf("Queue Overflow\n");
        return;
    }

    pq[n] = value;
    n++;

    printf("Element inserted\n");
}

// Delete element with highest priority (smallest value)
void delete()
{
    if (n == 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    int min = pq[0];
    int pos = 0;

    for (int i = 1; i < n; i++)
    {
        if (pq[i] < min)
        {
            min = pq[i];
            pos = i;
        }
    }

    printf("Deleted element: %d\n", min);

    for (int i = pos; i < n - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    n--;
}

// Display queue
void display()
{
    if (n == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            delete();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}