#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    int val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    int i = 0;

    while (exp[i] != '\0') {

        if (isdigit(exp[i])) {
            int num = 0;

            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }

        else if (exp[i] == ' ') {
            i++;
            continue;
        }

        else {
            int b = pop();
            int a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
            i++;
        }
    }

    return pop();
}

int main() {

    char exp[100];

    printf("Enter postfix expression:\n");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}