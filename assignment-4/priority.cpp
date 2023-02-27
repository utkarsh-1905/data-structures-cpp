#include <iostream>
using namespace std;

// bigger element has higher priority

class PriorityQueue
{

private:
    int size;
    int *sarr;
    int *parr;
    int count;

public:
    PriorityQueue(int size)
    {
        this->size = size;
        sarr = new int[size];
        parr = new int[size];
        count = 0;
    }

    void Enqueue(int data)
    {
        if (IsFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        sarr[count] = data; // normal enqueue
        // priority enqueue in decreasing order
        int i = count - 1;
        while (i >= 0 && parr[i] < data)
        {
            parr[i + 1] = parr[i];
            i--;
        }
        parr[i + 1] = data;
        count++;
    }

    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < count - 1; i++)
        {
            sarr[i] = sarr[i + 1];
        }
        count--;
        // priority dequeue
        for (int i = 0; i < count - 1; i++)
        {
            parr[i] = parr[i + 1];
        }
    }

    void Display()
    {
        cout << "Normal Queue" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << sarr[i] << " ";
        }
        cout << endl
             << "Priority Queue" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << parr[i] << " ";
        }
        cout << endl;
    }

    inline bool IsFull() { return count == size; }

    inline bool IsEmpty() { return count == 0; }
};

int main()
{
    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    PriorityQueue q(size);
    int choice;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. IsEmpty" << endl;
    cout << "5. IsFull" << endl;
    cout << "6. Exit" << endl;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data" << endl;
            cin >> data;
            q.Enqueue(data);
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.Display();
            break;
        case 4:
            cout << q.IsEmpty() << endl;
            break;
        case 5:
            cout << q.IsFull() << endl;
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
}