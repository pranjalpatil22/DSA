#include <iostream>
#include<queue>
#include <stack>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node* right;
    node(int val)
    {
        data = val;
        left =  NULL;
        right = NULL;
    }


}*root = NULL;


struct node* create_node(int v)
{
    struct node* new1 = new node(v);
    new1 -> data = v;
    new1 -> left = NULL;
    new1 -> right = NULL;
    return new1;
}


void insertLevelOrder(int data)
{
        if (root == NULL) {
            root = new node(data);
            return;
        }

        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
            node* current = q.front();
            q.pop();

            if (current->left == NULL) {
                current->left = new node(data);
                break;
            } else {
                q.push(current->left);
            }

            if (current -> right == NULL) {
                current -> right = new node(data);
                break;
            }
            else{
                q.push(current->right);
            }
        }
    }

void deleteRight(node* root)
{

if (root == NULL)
    return;

    queue<node*> q;
    q.push(root);

    node* temp;
    node* parent = NULL;


    while (!q.empty()) {
        temp = q.front();
        q.pop();


        if (temp->right) {
            parent = temp;
            q.push(temp->right);
        }

        else if (temp->left) {
            parent = temp;
            q.push(temp->left);
        }
    }


    if (parent != NULL) {
        if (parent->right) {
            delete parent->right;
            parent->right = NULL;
        } else if (parent->left) {
            delete parent->left;
            parent->left = NULL;
        }
    }
}

void inorderTraversal(node* root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root)
 {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(node* root)
{
    if (root == NULL) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current -> left != NULL)
            q.push(current -> left);
        if (current -> right != NULL)
            q.push(current -> right);
    }
}

int main()
{
    cout << "Preparedby 23ce114 pranjal patil" << endl;

    while (true) {

        cout << "1.insert 2.delete 3.inorder traversal 4.preorder traversal 5.postorder traversal 6.level Order traversal 7.exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            insertLevelOrder(data);
        }
        else if (choice == 2) {
            deleteRight(root);
        }
        else if (choice == 3) {
            cout << "Inorder Traversal: ";
            inorderTraversal(root);
            cout << endl;
        }
         else if (choice == 4) {
            cout << "Preorder Traversal: ";
            preorderTraversal(root);
            cout << endl;
        }
         else if (choice == 5) {
            cout << "Postorder Traversal: ";
            postorderTraversal(root);
            cout << endl;
        } else if (choice == 6) {
            cout << "Level Order Traversal: ";
            levelOrderTraversal(root);
            cout << endl;
        } else if (choice == 7) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
