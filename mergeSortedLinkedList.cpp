#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
}*head = NULL,*head1 = NULL,*head2 = NULL;

struct node* create_node(int v)
{
    struct node* new1;
    new1 = (struct node*)malloc(sizeof(struct node));
    new1->data = v;
    new1->next = NULL;
    return new1;
}

void insert_node_end1(int v)
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

void insert_node_end2(int v)
{
    struct node* new1,*prev;
    struct node* t = head1;
    new1 = create_node(v);
    if (head1 == NULL)
    {
        head1 = new1;
    }
    else
    {
        while(t != NULL)
        {
            prev = t;
            t = t->next;
        }
        prev->next = new1;
    }
}

void insert(int v)
{
    struct node* prev;
    struct node* t = head1;
    struct node* new1 = create_node(v);
    if (head2 == NULL)
    {
        struct node* t = head2;
        head2 = new1;
    }
    else
    {
        while (t != NULL)
        {
            prev = t;
            t = t -> next;
        }
        prev -> next = new1;
    }
}
void display1(struct node* t)
{

    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
int length(struct node* t)
{
    int a = 0;
    while(t != NULL)
    {
        a++;
        t = t -> next;
    }

    return a;
}
void check()
{
    int a = 0,b = 0;
    struct node* t1 = head;
    struct node* t2 = head1;
    struct node* t3 = head2;

    while(head != NULL || head1 != NULL)
    {

        if(t1 -> data <= t2 -> data)
        {
            insert(t1 -> data);
            t1 = t1 -> next;
            a++;
        }
        else if(t2 -> data <= t1 -> data)
        {
            insert(t2 -> data);
            t2 = t2 -> next;
            b++;
        }
    }

    if(length(head) == a && length(head1) == b)
        display1(head2);
    else if(length(head) <= a)
    {
        while(t1 != NULL)
        {
            insert(t1 -> data);
        }
    }
    else if(t2 != NULL)
    {
        while(t2 != NULL)
        {
            insert(t2 -> data);
        }
    }

    display1(head2);
}

int main()
{
    int n;
    for(int i = 0; i < 3; i++)
    {
        cout << "Enter a value: ";
        cin >> n;
        insert_node_end1(n);

    }
    display1(head);
    for(int i = 0; i < 3; i++)
    {
        cout << "Enter a value: ";
        cin >> n;
        insert_node_end2(n);

    }
    display1(head1);

    check();
    return 0;
}
