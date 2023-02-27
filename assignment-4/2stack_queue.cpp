#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int *arr;
    int elementCount;

    Stack()
    {
        size = 10;
        arr = new int[size];
        elementCount = 0;
    }

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        elementCount = 0;
    }

    void Push(int val)
    {
        if (IsFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[elementCount] = val;
        elementCount++;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        arr[elementCount] = 0;
        elementCount--;
    }

    bool IsFull()
    {
        return elementCount == size;
    }

    bool IsEmpty()
    {
        return elementCount == 0;
    }

    int Peek()
    {
        return arr[0];
    }

    int Top()
    {
        return arr[elementCount - 1];
    }

    void Display()
    {
        for (int i = 0; i < elementCount; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int Capacity()
    {
        return size;
    }

    int Size()
    {
        return elementCount;
    }
};

class Queue
{
public:
    int size;
    Stack forward;
    Stack backward;

    Queue()
    {
        this->size = 10;
    }

    void Enqueue(int data)
    {
        if (forward.IsFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        forward.Push(data);
    }

    void Dequeue()
    {
        if (forward.IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        while (!forward.IsEmpty())
        {
            backward.Push(forward.Top());
            forward.Pop();
        }
        backward.Pop();
        while (!backward.IsEmpty())
        {
            forward.Push(backward.Top());
            backward.Pop();
        }
    }

    bool IsFull()
    {
        return forward.IsFull();
    }

    bool IsEmpty()
    {
        return forward.IsEmpty();
    }

    void Display()
    {
        forward.Display();
    }
};

int main()
{
    Queue myQueue;
    int t;
    cout << "Enter test cases: " << endl;
    cin >> t;
    while (t--)
    {
        int num;
        cout << "Enter a number: " << endl;
        cin >> num;
        myQueue.Enqueue(num);
    }

    int choice;
    cout << "Enter choice: " << endl;
    cout << "1. Dequeue" << endl;
    cout << "2. IsFull" << endl;
    cout << "3. IsEmpty" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            myQueue.Dequeue();
            myQueue.Display();
            break;
        case 2:
            cout << myQueue.IsFull() << endl;
            break;
        case 3:
            cout << myQueue.IsEmpty() << endl;
            break;
        case 4:
            myQueue.Display();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}