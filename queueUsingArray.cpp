#include <iostream>

using namespace std;
class queue{
public:
    int size;
    int arr[100];
    int front = -1,rear = -1;
    queue(int t)
    {
        size = t;
    }

    void enqueue(int p)
    {
        if(rear == size - 1)
            cout << "overflow!" << endl;
        else if(front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = p;
        }
        else{
            rear++;
            arr[rear] = p;
        }
    }

    void dequeue()
    {
        if(front == -1 && rear == -1)
            cout << "underflow!"<< endl;
        else if(front == rear)
            {
                cout << "dequeued element is : " << arr[front] << endl;
            front = rear = -1;
            }
        else{
                cout << "dequeued element is : " << arr[front] << endl;
            front++;
        }
    }

    void display()
    {
        if(front == -1 && rear == -1)
            cout << "queue is empty" << endl;
        else{
            cout << "queue is : ";
            for(int i = front;i <= rear ; i++)
                cout << arr[i] << " ";
        }
    }

    void peek()
    {
        if(front == -1 && rear == -1)
            cout << "queue is empty" << endl;
        else{
            cout << "data is : "<< arr[rear] << endl;
        }
    }
};
int main()
{
    //queue obj = new queue(5);
    queue obj(5);

    char ch;
    int choice;
    do{
        cout << "1. enqueue \n2.dequeue \n3. peek \n.4.display"<< endl;
        cin >> choice;
        switch(choice)
        {
        case 1 : int p;
            cout << "Enter a value" << endl;
            cin >> p;
            obj.enqueue(p);
            obj.display();
            break;
        case 2 :
            obj.dequeue();
            obj.display();
            break;
        case 3 :
            obj.peek();
            break;
        case 4 :
            obj.display();
            break;
        }

        cout << endl<< "enter y to continue : " << endl;
        cin >> ch;
    }while(ch == 'y');
    return 0;
}
