#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    Node *Insert(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            temp->prev = NULL;
            return temp;
        }

        Node *nHead = head;
        while (nHead->next != NULL)
        {
            nHead = nHead->next;
        }

        nHead->next = temp;
        temp->prev = nHead;
        return temp;
    }
    void Display()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    bool Delete(int data)
    {
        Node *itr = head;
        while (itr != NULL)
        {
            if (itr->data == data)
            {
                // if our find is the head node
                if (itr->prev == NULL)
                {
                    itr->next->prev = NULL;
                    head = itr->next;
                    delete itr;
                    return true;
                }
                else if (itr->next == NULL)
                {
                    itr->prev->next = NULL;
                    delete itr;
                    return true;
                }
                else
                {
                    // any other node in the list
                    itr->prev->next = itr->next;
                    itr->next->prev = itr->prev;
                    delete itr;
                    return true;
                }
            }
            itr = itr->next;
        }
        return false;
    }
};

void removeDuplicates(LinkedList *list)
{
    std::unordered_set<int> visited;
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (visited.count(temp->data) > 0)
        {
            list->Delete(temp->data);
            temp = temp->next;
        }
        else
        {
            visited.insert(temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    LinkedList *list = new LinkedList();
    int t;
    cout << "Enter number of elements you want to enter in the linked list" << endl;
    cin >> t;
    while (t--)
    {
        cout << "Enter element: \t";
        int data;
        cin >> data;
        list->Insert(data);
        cout << endl;
    }
    cout << "Removing duplicates ..." << endl;
    removeDuplicates(list);
    list->Display();
    return 0;
}