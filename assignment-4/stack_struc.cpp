#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *head;
    int count;
    int size;
};

int main()
{
}