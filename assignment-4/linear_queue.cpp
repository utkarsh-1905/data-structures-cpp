#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Adding new node at the back of the queue
    void Enqueue(int x)
    {
        // creating a new node
        Node *temp = new Node(x);

        // if the rear is null, that is, it is equal to front and list is empty
        // we make front and rear pointer both point to this node
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        // else we point the next element of rear to this node
        // and change the rear to this node to maintain the linked list connection
        rear->next = temp;
        rear = temp;
    }

    // Delete from the front
    void Dequeue()
    {
        // if front is null, there is nothing to delete
        if (front == NULL)
        {
            return;
        }

        // storing the first node in temp variable to act as an increment counter
        // and increment the front pointer till it is null
        Node *temp = front;
        front = front->next;

        // when the front is null, this means the queue is empty and we make the rear null
        if (front == NULL)
        {
            rear = NULL;
        }

        // deleting the memory location containing the node
        delete temp;
    }

    void Display()
    {

        Node *temp = front;

        while (true)
        {
            cout << temp->data << endl;
            temp = temp->next;
            if (temp == NULL)
            {
                return;
            }
        }
    }

    int Peek()
    {
        return front->data;
    }

    bool IsEmpty()
    {
        if (front > rear || front == NULL || rear == NULL)
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    Queue newQueue;
    cout << "Choices for the Queue are: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Peek" << endl;
    cout << "5. IsEmpty" << endl;
    cout << "6. Exit" << endl;
    int choice;
    while (true)
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter the number to be enqueued: ";
            cin >> x;
            newQueue.Enqueue(x);
            break;

        case 2:
            newQueue.Dequeue();
            break;

        case 3:
            newQueue.Display();
            break;

        case 4:
            cout << newQueue.Peek() << endl;
            break;

        case 5:
            if (newQueue.IsEmpty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}