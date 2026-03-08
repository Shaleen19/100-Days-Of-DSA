#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->info = value;

    if (front == NULL)
    {
        front = rear = newnode;
        newnode->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }

    printf("Inserted: %d\n", value);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct node *temp = front;

    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    printf("Deleted: %d\n", temp->info);
    free(temp);
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct node *temp = front;

    printf("Queue Elements: ");

    do
    {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
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