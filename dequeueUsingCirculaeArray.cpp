#include <iostream>

using namespace std;
class dequeue
{
public:
    int size;
    int arr[100];
    int front = -1, rear = -1;
    dequeue(int a)
    {
        size = a;
    }
    void enqueueFront(int x)
    {
        if((front == rear + 1) || (front == 0 && rear ==  size - 1))
            cout << "queue is full" << endl;
        else if(front == -1 && front == -1)
        {
            rear = front = 0;
            arr[front] = x;
        }
        else if(front == 0)
        {
            front = size - 1;
            arr[front] = x;
        }
        else
        {
            front--;
            arr[front] = x;
        }
    }

    void enqueueRear(int x)
    {
        if((front == 0 && rear == size - 1) || (front == 0 && rear ==  size - 1))
            cout << "queue is full" << endl;
        else if(front == -1 && rear == -1)
        {
            front= rear = 0;
            arr[rear] = x;
        }
        else if(rear == size - 1)
        {
            rear = 0;
            arr[rear]=x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    void display()
    {
        int i = front;
        if(rear == -1 && front == -1)
            cout << "queue is empty" << endl;
        else
        {
            cout << "queue is :";
            while(i != rear)
            {
                cout << arr[i] << " ";
                i = (i + 1)%size;
            }
            cout << arr[rear];
        }
    }

    void dequeueFront()
    {
        if(front == -1 && rear == -1)
            cout << "queue is empty" << endl;
        else if(front == rear )
        {
            front = rear = -1;
        }
        else if(front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void dequeueRear()
    {
        if(front == -1 && rear == -1)
            cout << "queue is empty" << endl;
        else if(front == rear )
        {
            front = rear = -1;
        }
        else if(rear == 0)
            rear = size - 1;
        else
            rear--;
    }
};
int main()
{
    dequeue obj(5);


    int choice;
    char ch;
    do
    {
        cout << "1. enqueue front \n2. enqueue rear \n3. dequeue front \n4. dequeue rear" << endl;
        cin >> choice;
        switch(choice)
        {
        case 1 :
            int a;
            cout << "Enter value : " << endl;
            cin >> a;
            obj.enqueueFront(a);
            obj.display();
            break;
        case 2 :
            int b;
            cout << "Enter value : " << endl;
            cin >> b;
            obj.enqueueRear(b);
            obj.display();

            break;
        case 3:
            obj.dequeueFront();
            obj.display();

            break;
        case 4 :
            obj.dequeueRear();
            obj.display();

            break;
        }
        cout << endl<<"Enter y to continue : " << endl;
        cin >> ch;
    }
    while(ch == 'y');
    return 0;
}

