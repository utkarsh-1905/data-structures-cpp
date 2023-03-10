#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
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

    LinkedList(Node *head)
    {
        this->head = head;
    }

    void Insert(int data)
    {
        Node *temp = new Node(data);
        if (head == NULL)
        {
            head = temp;
            return;
        }

        Node *nHead = head;
        while (nHead->next != NULL)
        {
            nHead = nHead->next;
        }

        nHead->next = temp;
        return;
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
    void Reverse()
    {

        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

/*

    Rearrange Pattern

    Input - L0, L1, L2, L3 ... LN-1, LN
    Output - L0, LN, L1, LN-1, L2, LN-2 ... LN/2

*/

LinkedList *Rearrange(LinkedList *list)
{
    Node *half = list->head;
    Node *full = list->head->next->next;
    LinkedList *nlist = new LinkedList();

    // by traversing full at double speed, when full pointer reaches end of list
    // half pointer is at the middle of the list
    while (full->next != NULL && full->next->next != NULL)
    {
        half = half->next;
        full = full->next->next;
    }

    Node *secondHalf = half->next;
    LinkedList *nlist2 = new LinkedList(secondHalf); // new linked list with latter half

    // second half of the linked list
    half->next = NULL; // first half of the linked list

    // we need to reverse the second half and merge it with the first half alternatively
    nlist2->Reverse(); // reversing the second half by passing a pointer

    Node *head1 = list->head;
    Node *head2 = nlist2->head;
    int flag = -1; // 0 for head1 and 1 for head2
    for (int i = 0;; i++)
    {
        if (head1 == NULL)
        {
            flag = 0;
            break;
        }
        if (head1 == NULL)
        {
            flag = 1;
            break;
        }
        if (i % 2 == 0)
        {
            nlist->Insert(head1->data);
            head1 = head1->next;
        }
        else
        {
            nlist->Insert(head2->data);
            head2 = head2->next;
        }
    }
    if (flag == 0)
    {
        // head1 is empty
        while (head2 != NULL)
        {
            nlist->Insert(head2->data);
            head2 = head2->next;
        }
    }
    else if (flag == 1)
    {
        // head2 is empty
        while (head1 != NULL)
        {
            nlist->Insert(head1->data);
            head1 = head1->next;
        }
    }
    return nlist;
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
    list->Display();
    cout << "Rearranging the linked list ..." << endl;
    LinkedList *nlist = Rearrange(list);
    nlist->Display();
}