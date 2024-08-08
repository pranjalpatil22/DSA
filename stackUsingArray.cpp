#include <iostream>
using namespace std;

int stack[5];
int top = -1;
void dispay()
{
    cout << "stack : ";
    for(int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
}
void push(int data)
{

    if(top == 5-1)
        cout << "STACK OVERFALL!" << endl;
    else
    {
        top++;
        stack[top] = data;
        dispay();
    }


}

void pop()
{
    if(top == -1)
    {
        cout << "UNDERFLOW!" << endl;
    }
    else
    {
        top--;
        dispay();
    }

}
int main()
{


    char ch = 'y';
    int choice;
    cout << "Enter 1 to push" << endl;
    cout << "Enter 2 to pop" << endl;

    cin >> choice;
    while(ch == 'y')
    {
        switch(choice)
        {
        case 1 :
            int data;
            cout << "Enter data : " << endl;
            cin >> data;
            push(data);
            break;
        case 2 :
            pop();
            break;
        default :
            cout << "Invalid input" << endl;
        }
        cout <<endl<< "Enter y to continue " << endl;
        cin >> ch;

        cout << "Enter 1 to push" << endl;
    cout << "Enter 2 to pop" << endl;
    cin >> choice;
    }
    return 0;

}



