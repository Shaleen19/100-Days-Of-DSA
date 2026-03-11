#include<stdio.h>

int heap[100];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value)
{
    int i = size;
    heap[size] = value;
    size++;

    while(i != 0 && heap[(i-1)/2] > heap[i])
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapify(int i)
{
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i)
    {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int deleteMin()
{
    int root = heap[0];
    heap[0] = heap[size-1];
    size--;

    heapify(0);
    return root;
}

void display()
{
    for(int i=0;i<size;i++)
        printf("%d ", heap[i]);
}

int main()
{
    insert(10);
    insert(4);
    insert(15);
    insert(20);
    insert(0);

    printf("Min Heap: ");
    display();

    printf("\nDeleted Min: %d", deleteMin());

    printf("\nHeap after deletion: ");
    display();
}