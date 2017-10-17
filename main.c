#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct Node* link;
}Node;

Node *stackPtr = NULL;

void push(int);
void pop();
void print();

int main()
{
    push(7);
    push(8);
    push(3);

    print();

    pop();

    print();

    return 0;
}

void push (int num)
{
    Node *current = (Node*) malloc(sizeof(Node));

    if (stackPtr == NULL)
    {
        stackPtr = current;
        current->data = num;
        current->link = NULL;
    }

    else
    {
        current->data = num;
        current->link = stackPtr;
        stackPtr = current;
    }
}

void pop ()
{
    Node *temp = NULL;
    temp = stackPtr;
    stackPtr = stackPtr->link;
    free(temp);
}

void print()
{
    Node *temp = stackPtr;

    while (temp != NULL)
    {
        printf("%i\n", temp->data);
        temp = temp->link;
    }
}
