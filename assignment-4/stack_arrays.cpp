#include <iostream>
using namespace std;

// stacks using arrays

class Stack
{
public:
    int size;
    int *arr;
    int elementCount;

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

int main()
{
    int size;
    cout << "Enter size of stack :" << endl;
    cin >> size;
    Stack s(size);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Display();
    cout << "popped" << endl;
    s.Pop();
    s.Display();
    cout << "peek " << s.Peek() << endl;
    cout << "top " << s.Top() << endl;
    return 0;
}