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

    // We delete from the front
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

    Node *Peek()
    {
        return front->next;
    }

    bool IsEmpty()
    {
        if (front >= rear)
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
    newQueue.Enqueue(5);
    newQueue.Enqueue(6);
    newQueue.Enqueue(7);
    cout << newQueue.Peek()->data;
    return 0;
}