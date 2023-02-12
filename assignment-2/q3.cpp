#include <bits/stdc++.h>
using namespace std;

class ArrayOps
{

private:
    int *arr;
    int size;

public:
    ArrayOps(int *arr, int size)
    {
        this->arr = arr;
        this->size = size;
    }

    void Find(int s)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == s)
            {
                cout << "Found at: " << i << endl;
            }
        }
    }

    // sorting array
    void Sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        Display();
    }

    void Duplicates()
    {
        Sort();
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                cout << arr[i] << " is a duplicate" << endl;
            }
        }
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // display elements of array

    int Max()
    {
        Sort();
        int max = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    int Min()
    {
        Sort();
        int min = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }

    void SumKU(int k)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] + arr[j] == k)
                {
                    cout << arr[i] << " + " << arr[j] << " = " << k << endl;
                }
            }
        }
    }

    void SumK(int k)
    {
        Sort();
        int i = 0;
        int j = size - 1;
        while (i < j)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << arr[i] << " + " << arr[j] << " = " << k << endl;
                i++;
                j--;
            }
            else if (arr[i] + arr[j] < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    ArrayOps myArr(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element: ";
        int x;
        cin >> x;
        arr[i] = x;
    }
    myArr.Display();
    // menu driven for class ArrayOps
    int choice;
    cout << "Enter your choice: " << endl;
    cout << "1. Find" << endl;
    // cout << "2. Find All" << endl;
    cout << "2. Sort" << endl;
    cout << "3. Duplicates" << endl;
    cout << "4. Max" << endl;
    cout << "5. Min" << endl;
    cout << "6. Sum K" << endl;
    cout << "7. Sum KU" << endl;
    cout << "8. Display" << endl;
    cout << "9. Exit" << endl;

    while (true)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            int s;
            cout << "Enter the element to be searched: ";
            cin >> s;
            myArr.Find(s);
            break;

        case 2:
            myArr.Sort();
            break;

        case 3:
            myArr.Duplicates();
            break;

        case 4:
            cout << "Max: " << myArr.Max() << endl;
            break;

        case 5:
            cout << "Min: " << myArr.Min() << endl;
            break;

        case 6:
            int k;
            cout << "Enter the value of k: ";
            cin >> k;
            myArr.SumK(k);
            break;

        case 7:
            int ku;
            cout << "Enter the value of k: ";
            cin >> ku;
            myArr.SumKU(ku);
            break;

        case 8:
            myArr.Display();
            break;

        case 9:
            exit(0);
            break;

        default:
            cout << "Invalid choice";
            break;
        }
    }
}