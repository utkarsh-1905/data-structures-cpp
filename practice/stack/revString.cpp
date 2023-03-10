#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
public:
    T *arr;
    int size;
    int elemCount;

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

    inline int StackSize()
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

int main()
{
    // reversing a string using stack
    string str;
    cout << "Enter a character string" << endl;
    getline(cin, str);
    cout << "Length is " << str.length() << endl;
    Stack<char> s(str.length());
    for (int i = 0; i < str.length(); i++)
    {
        s.Push(str[i]);
    }
    s.Print();
    string rev = "";
    while (s.StackSize() > 0)
    {
        rev += s.Pop();
    }
    cout << rev << endl;
}