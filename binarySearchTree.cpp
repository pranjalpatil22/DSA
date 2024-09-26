#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
}*root = NULL;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
        return root;
    }

    if (value < root -> data) {
        root -> left = insertNode(root -> left, value);
    } else if (value > root -> data) {
        root -> right = insertNode(root -> right, value);
    }

    return root;
}

Node* searchNode(Node* root, int value) {
    if (root == NULL) {
        cout << "not found\n";
        return NULL;
    }
    if (root -> data == value) {
        cout << "found\n";
        return root;
    } else if (value < root -> data) {
        return searchNode(root -> left, value);
    } else {
        return searchNode(root -> right, value);
    }
}

void display(Node* root) {
    if (root == NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main() {

cout << "Prepared by 23ce114 pranjal patil" << endl;
    int choice, value;

    do {

        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);

                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(root, value);
                break;
            case 3:
                cout << "Inorder traversal of BST: ";
                display(root);
                cout << endl;
                break;
            case 4:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
