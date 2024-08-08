#include <iostream>

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
void reverse1()
{

    struct node* curr = head;
    struct node* prev = NULL;
    struct node* nextptr = head -> next;
    while(nextptr != NULL)
    {

        curr -> next = prev;
        prev = curr;
        curr = nextptr;
        nextptr = nextptr -> next;
    }
    curr -> next = prev;

    head = curr;

}
int main()
{
    for(int i = 0; i < 5; i++)
    {
        int n;
        cout << "Enter a value : " << endl;
        cin >> n;
        insert_node_end(n);
    }
    cout << "Linked list is : " << endl;
    display();

    reverse1();
    display();
    return 0;
}
