#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

struct Stack
{
    int arr[MAX_SIZE];
    int top;

    Stack()
    {
        top = -1;
    }

    // function to check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // function to check if the stack is full
    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    // function to push an element onto the stack
    void push(int x)
    {
        if (isFull())
        {
            cout << "Error: Stack is full\n";
            return;
        }
        arr[++top] = x;
    }

    // function to pop the top element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        return arr[top--];
    }

    // function to get the top element of the stack
    int peek()
    {
        if (isEmpty())
        {
            cout << "Error: Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << s.pop() << "\n";  // should print 15
    cout << s.peek() << "\n"; // should print 10
    s.push(20);
    cout << s.pop() << "\n"; // should print 20
    cout << s.pop() << "\n"; // should print 10
    cout << s.pop() << "\n"; // should print 5
    cout << s.pop() << "\n"; // should print Error: Stack is empty
    return 0;
}
