#include <iostream>

using namespace std;

// 1 1 2 3 5 8 13 ...

int Fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main()
{

    int num;
    cout << "Enter the number of terms you want: " << endl;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << Fibonacci(i) << " ";
    }
    return 0;
}