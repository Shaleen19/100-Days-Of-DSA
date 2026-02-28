#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node* next;
}Node;

int main(){

    Node* head = NULL;
    Node*temp;
    int choice = 1;

    while(choice){
        Node* new = (Node*)malloc(sizeof(Node));
        printf("Enter element in new node: ");
        scanf("%d",&new->info);
        Node* ptr = head;

        if(head==NULL){
            head = new;
            new->next = head;
        }
        else{
            while(ptr->next!=head)
                ptr = ptr->next;

            ptr->next = new;
            new ->next = head;
        }
        printf("Do you want to continue(0/1): ");
        scanf("%d",&choice);
    }

    temp = head;
    printf("%d ",temp->info);
    temp = temp->next;
    while(temp !=head){
        printf("%d ",temp->info);
        temp = temp->next;
    }

}