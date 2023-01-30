#include <iostream>
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

    bool IsSorted()
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void Union(ArrayOps a)
    {
        int *temp = new int[size + a.size];
        for (int i = 0; i < size + a.size; i++)
        {
            if (i < size)
            {
                temp[i] = arr[i];
            }
            else
            {
                temp[i] = a.arr[i - size];
            }
        }
        Display(temp, size + a.size);
    }

    void Intersection(ArrayOps a)
    {
        int *temp = new int[size + a.size];
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < a.size; j++)
            {
                if (arr[i] == a.arr[j])
                {
                    temp[count] = arr[i];
                    count++;
                }
            }
        }
        if (count == 0)
        {
            cout << "No common elements" << endl;
        }
        else
        {
            Display(temp, count);
        }
    }

    void Display(int *temp, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *arr = new int[size];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    ArrayOps a(arr, size);
    int size2;
    cout << "Enter size of array: ";
    cin >> size2;
    int *arr2 = new int[size2];
    cout << "Enter elements of array: ";
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }
    ArrayOps b(arr2, size2);
    int choice;
    cout << "Choices" << endl;
    cout << "1. Union" << endl;
    cout << "2. Intersection" << endl;
    cout << "3. Display" << endl;
    cout << "4. IsSorted" << endl;
    cout << "5. Exit" << endl;
    while (true)
    {
        cout << "Enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.Union(b);
            break;
        case 2:
            a.Intersection(b);
            break;
        case 3:
            a.Display();
            break;
        case 4:
            int c;
            cout << "Enter 1 for array 1 and 2 for array 2: " << endl;
            cin >> c;
            if (c == 1)
            {
                if (a.IsSorted())
                    cout << "Sorted" << endl;
                else
                    cout << "Not Sorted" << endl;
            }
            else
            {
                if (b.IsSorted())
                    cout << "Sorted" << endl;
                else
                    cout << "Not Sorted" << endl;
            }
            break;
        case 5:
            exit(0);
        }
    }
}