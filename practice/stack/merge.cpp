#include <iostream>
using namespace std;

template <typename T>
class Stack
{

private:
    T *arr;
    int size;
    int elemCount;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new T[size];
        elemCount = 0;
    }

    void Push(T data)
    {
        if (elemCount >= size)
        {
            cout << "Stack full, can't add " << data << endl;
            return;
        }
        arr[elemCount] = data;
        elemCount += 1;
    }

    T Pop()
    {
        elemCount -= 1;
        T last = arr[elemCount];
        delete &arr[elemCount];
        return last;
    }

    inline T Top()
    {
        return arr[elemCount - 1];
    }

    inline int Size()
    {
        return elemCount;
    }

    void Print()
    {
        cout << "Elements:\t";
        for (int i = 0; i < elemCount; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] arr;
    }
};

Stack<int> mergeStack(Stack<int> s1, Stack<int> s2)
{
    Stack<int> stemp(s1.Size() + s2.Size());
    Stack<int> snew(s1.Size() + s2.Size());
    while (s1.Size() > 0 && s2.Size() > 0)
    {
        if (s1.Top() < s2.Top())
        {
            stemp.Push(s1.Pop());
        }
        else
        {
            stemp.Push(s2.Pop());
        }
    }
    while (s1.Size() > 0)
    {
        stemp.Push(s1.Pop());
    }
    while (s2.Size() > 0)
    {
        stemp.Push(s2.Pop());
    }
    // reversing stack for min on top
    while (stemp.Size() > 0)
    {
        snew.Push(stemp.Pop());
    }
    return snew;
}

int main()
{
    Stack<int> s1(5);
    Stack<int> s2(5);
    s1.Push(9);
    s1.Push(6);
    s1.Push(5);
    s1.Push(2);
    s1.Push(1); // min on top
    s2.Push(15);
    s2.Push(14);
    s2.Push(8);
    s2.Push(7);
    s2.Push(3); // min on top

    Stack<int> snew = mergeStack(s1, s2);
    snew.Print();
    cout << snew.Top() << endl;
}