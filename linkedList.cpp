#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*head = NULL;

struct node* create_node(int v)
{
    struct node* new1;
    new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = v;
    new1->next = NULL;
    return new1;
}

void insert_node_front(int v)
{
    struct node* new1;
    new1 = create_node(v);
    if (head == NULL)
    {
        head = new1;
    }
    else
    {
        new1->next = head;
        head = new1;
    }
}

void insert_node_end(int v)
{
    struct node* new1, *prev;
    struct node* t = head;
    new1 = create_node(v);
    if (head == NULL)
    {
        head = new1;
    }
    else
    {
        while (t != NULL)
        {
            prev = t;
            t = t->next;
        }
        prev->next = new1;
    }
}

void delete_front_node()
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    head = head->next;
}

void delete_end_node()
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    node* t , *prev = NULL;
    t = head;
    while(t->next != NULL)
    {
        prev = t;
        t = t->next;
    }
    prev->next = NULL;

}
void delete_nth_end_node(int v)
{
    int count = 0;
    node * t = head;
    while(t != NULL)
    {
        count++;
        t= t->next;
    }
    int dnode = count - v;
    int i = 0;
    node *temp = head ,*prev;
    while(i<dnode)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
}
void display()
{
    struct node* t = head;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main()
{
    cout << "1. insert node at front" << endl;
    cout << "2. insert node at end" << endl;
    cout << "3. delete node at front" << endl;
    cout << "4. delete node at end" << endl;
    cout << "5. delete node at nth position of the end" << endl;

    int choice, n;
    char c;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a value: ";
            cin >> n;
            insert_node_front(n);
            display();
            break;

        case 2:
            cout << "Enter a value: ";
            cin >> n;
            insert_node_end(n);
            display();
            break;

        case 3:
            delete_front_node();
            display();
            break;

        case 4:
            delete_end_node();
            display();
            break;

        case 5:
            cout << "Enter a number of node you want to delete of the end: ";
            cin >> n;
            delete_nth_end_node(n);
            display();
            break;
         // display();

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
        cout << "Enter y to go to the main menu: ";
        cin >> c;

    }
    while (c == 'y');

    return 0;
}
