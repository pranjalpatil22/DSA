#include <iostream>

using namespace std;
class circularQueue
{

public:
    int size;
    int arr[100];
    int front = -1;
    int rear = -1;

    void enqueue(int p)
    {
        if(front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = p;
        }
        else if(((rear + 1)%size) == front) //in simple queue it is equal to rear = front + 1;
            cout << "overflow!" << endl;
        else
        {
            rear = (rear + 1)%size;
            arr[rear] = p;
        }
    }

    void dequeue()
    {
        if(front == -1 && front == -1)
            cout << "queue is empty" << endl;
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            cout << "dequeued element is : " << arr[front] << endl;
            front = (front + 1) % size;

        }
    }

    void display()
    {
        int i = front;
        if(front == -1 && rear == -1)
            cout << "queue is empty" << endl;
        else
        {
            cout << "Queue is : ";
            while(i != rear)
            {
                cout << arr[i] << " ";
                i = (i + 1)%size;
            }
            cout << arr[rear];
        }
    }
};
int main()
{
    circularQueue obj;

    int choice;
    char ch;

    do
    {
cout << "1. enqueue \n2. dequeue \n3. display" << endl;
cin >> choice;
        switch(choice)
        {
        case 1 :
            int n;
            cout << "Enter a value" << endl;
            cin >> n;
            obj.enqueue(n);
            obj.display();
            break;

        case 2 :
            obj.dequeue();
            obj.display();
            break;
        case 3 :
            obj.display();
            break;
        }
        cout << endl<<"Enter y to continue" << endl;
        cin >> ch;
    }
    while(ch == 'y');
    return 0;
}
