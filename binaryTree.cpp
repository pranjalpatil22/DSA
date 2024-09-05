#include <iostream>

using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;

}*head = NULL;

struct node* insert()
{
    int v;
    struct node* temp = new node;
    cout << "ENter data. (-1) for no node" << endl;
    cin >> v;

    if(v == -1)
        return NULL;

    temp -> data = v;
    cout << "ENter left child of "<< v << endl;
    temp -> prev = insert();

    cout << "ENter right child of "<< v << endl;
    temp -> next = insert();

    return temp;
};

void preorder(struct node* root)
{
    if(root == NULL)
        return;

    cout << root -> data << " ";
    preorder(root -> prev);
    preorder(root -> next);
}

void postorder(struct node* root)
{
    if(root == NULL)
        return;


    postorder(root -> prev);
    postorder(root -> next);
    cout << root -> data << " ";
}

void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root -> prev);
    cout << root -> data << " ";
    inorder(root -> next);

}
int main()
{
    struct node* root = insert();

    cout << "pre order is : " ;
    preorder(root);

    cout << endl<<"post order is : " ;
    postorder(root);

    cout << endl<<"in order is : " ;
    inorder(root);
    return 0;
}
