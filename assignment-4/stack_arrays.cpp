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
    int choice;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Display" << endl;
    cout << "5. IsEmpty" << endl;
    cout << "6. IsFull" << endl;
    cout << "7. Size" << endl;
    cout << "8. Exit" << endl;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data" << endl;
            cin >> data;
            s.Push(data);
            break;
        case 2:
            s.Pop();
            break;
        case 3:
            cout << "Peek: " << s.Peek() << endl;
            break;
        case 5:
            s.Display();
            break;
        case 6:
            cout << "Empty: " << s.IsEmpty() << endl;
            break;
        case 7:
            cout << "IsFull: " << s.IsFull() << endl;
            break;
        case 8:
            cout << "Size: " << s.Size() << endl;
            break;
        case 9:
            exit(0);
            break;
        }
    }
    return 0;
}