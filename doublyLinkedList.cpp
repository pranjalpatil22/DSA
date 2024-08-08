#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node* next;

}*head = NULL;

struct node* create_node(int v)
{
    struct node* new1 = new node;
    new1->data = v;
    new1->prev = NULL;
    new1->next = NULL;
    return new1;
}


void insertFront(int v)
{
    struct node* new1 = create_node(v);
    if (head == NULL)
    {
        head = new1;
    }
    else
    {
        new1 -> next = head;
        head -> prev = new1;
        head = new1;
    }
}

void deleteAllNodes()
{
    while (head != NULL)
    {
        struct node* temp = head;
        head = head -> next;
        delete temp;
    }
    cout << "All nodes are deleted!" << endl;
}

void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    if (head -> next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    delete temp;
}

void display()
{
    struct node* temp = head;
    cout << "Linked list : ";
    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    int choice, v;
    char c;
    cout<<"prepared by 23CE114 pranjal patil"<<endl;
    cout << "1 for insert node at front\n";
    cout << "2 for delete node at end\n";
    cout << "3 for delete all nodes\n";
    do
    {
        cout << "Enter the choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value: ";
            cin >> v;
            insertFront(v);
            display();
            break;

        case 2:
            deleteEnd();
            display();
            break;

        case 3:
            deleteAllNodes();
            display();
            break;

        default:
            cout << "Invalid input" << endl;
        }
        cout << "Enter y to continue: ";
        cin >> c;
    } while (c == 'y');
    return 0;
}
