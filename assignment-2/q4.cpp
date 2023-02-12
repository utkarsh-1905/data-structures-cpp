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

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
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

    void Add(int data)
    {
        Node *temp = new Node(data);

        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node *itr = head;
        while (itr->next != NULL)
        {
            itr = itr->next;
        }

        itr->next = temp;
        itr = temp;
    }

    void Display()
    {

        Node *itr = head;

        if (itr == NULL)
        {
            return;
        }

        while (itr != NULL)
        {
            cout << itr->data << endl;
            itr = itr->next;
        }
    }

    void CountAndSum()
    {
        int count = 0, sum = 0;
        Node *itr = head;

        while (itr != NULL)
        {
            count++;
            sum += itr->data;
            itr = itr->next;
        }

        cout << "Sum = " << sum << endl
             << "Count = " << count << endl;
    }

    void Search(int key)
    {
        Node *itr = head;
        while (itr != NULL)
        {
            if (key == itr->data)
            {
                cout << "Found" << endl;
                return;
            }
            itr = itr->next;
        }
        cout << "Not Found" << endl;
        return;
    }

    void Delete(int key)
    {
        Node *itr = head;
        Node *temp = NULL;

        while (itr != NULL)
        {
            if (itr->data == key)
            {
                if (temp == NULL)
                {
                    head = itr->next;
                    delete itr;
                    return;
                }

                temp->next = itr->next;
                delete itr;
                return;
            }
            temp = itr;
            itr = itr->next;
        }
    }

    void IsSorted()
    {
        Node *itr = head;
        while (itr != NULL)
        {
            if (itr->next != NULL && itr->data > itr->next->data)
            {
                cout << "Not Sorted" << endl;
                return;
            }
            itr = itr->next;
        }
        cout << "Sorted" << endl;
        return;
    }

    void Reverse()
    {
        Node *itr = head;
        Node *prev = NULL, *next = NULL;

        while (itr != NULL)
        {
            next = itr->next;
            itr->next = prev;
            prev = itr;
            itr = next;
        }

        head = prev;
    }

    // merge two linked list
    void Merge(LinkedList l1, LinkedList l2)
    {
        Node *itr1 = l1.head;
        Node *itr2 = l2.head;

        while (itr1 != NULL && itr2 != NULL)
        {
            if (itr1->data < itr2->data)
            {
                Add(itr1->data);
                itr1 = itr1->next;
            }
            else
            {
                Add(itr2->data);
                itr2 = itr2->next;
            }
        }

        while (itr1 != NULL)
        {
            Add(itr1->data);
            itr1 = itr1->next;
        }

        while (itr2 != NULL)
        {
            Add(itr2->data);
            itr2 = itr2->next;
        }
    }
};

int main()
{
    LinkedList myList;
    cout << "Enter the numbers you want to add to the list: " << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number: " << endl;
        int data;
        cin >> data;
        myList.Add(data);
    }
    cout << "Operations on Linked List" << endl;
    cout << "1. Display" << endl;
    cout << "2. Count and Sum" << endl;
    cout << "3. Search" << endl;
    cout << "4. Delete" << endl;
    cout << "5. Is Sorted" << endl;
    cout << "6. Reverse" << endl;
    cout << "7. Merge" << endl;
    cout << "8. Exit" << endl;
    int choice;
    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            myList.Display();
            break;
        case 2:
            myList.CountAndSum();
            break;

        case 3:
            cout << "Enter the number you want to search: " << endl;
            int key;
            cin >> key;
            myList.Search(key);
            break;

        case 4:
            cout << "Enter the number you want to delete: " << endl;
            int key1;
            cin >> key1;
            myList.Delete(key1);
            break;

        case 5:
            myList.IsSorted();
            break;

        case 6:
            myList.Reverse();
            break;

        case 7:
            cout << "Merge" << endl;
            // pending
            break;

        case 8:
            exit(0);
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}