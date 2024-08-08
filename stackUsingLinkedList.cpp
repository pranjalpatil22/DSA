#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* next;
}*top = NULL;


void display()
{
    struct node* temp = top;
    cout << endl<<"Stack is : ";
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
void push(int data1)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data1;

    newnode -> next = top;
    top = newnode;

    display();
}

void pop()
{
    struct node* temp = top;
    if(top == NULL)
        cout << "STACK UNDERFLOW!" << endl;
    else
    {
        top = top -> next;
        display();
    }
}
int main()
{
    push(2);
    pop();
    push(3);
    pop();
    push(4);

    return 0;
}
