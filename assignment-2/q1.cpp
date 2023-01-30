#include <iostream>

using namespace std;

class CustomArray
{
    int *arr;
    int size;

public:
    CustomArray(int *arr, int size)
    {
        this->size = size;
        this->arr = arr;
    }

    void Insert(int index, int value)
    {
        if (index < size)
        {
            arr[index] = value;
        }
    }

    int Get(int index)
    {
        if (index < size)
        {
            return arr[index];
        }
        return -1;
    }

    void Sort()
    {
        for (int i = 0; i < size; i++)
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
    }

    int LinearSearch(int s)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == s)
            {
                return i;
            }
        }
        return -1;
    }

    int BinarySearch(int b)
    {
        int low = 0;
        int high = size - 1;
        this->Sort();
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == b)
            {
                return mid;
            }
            else if (arr[mid] < b)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }

    int Delete(int index)
    {
        if (index < size)
        {
            arr[index] = 0;
            return 0;
        }
        else
            return -1;
    }

    int GetSize()
    {
        return size;
    }

    int Max()
    {
        int max = arr[0];
        for (int i = 0; i < size; i++)
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
        int min = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }

    void Reverse()
    {
        int temp;
        for (int i = 0; i < size / 2; i++) // size/2 because middle element will stay same
        {
            temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    void Shift()
    { // left shift
        int temp = arr[0];
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = temp;
    }

    void Rotate()
    { // right shift
        int temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }

    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~CustomArray()
    {
        delete[] arr;
    }
};

int main()
{
    cout << "Welcome to custom array" << endl;
    cout << "Enter size of array" << endl;
    int size;
    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at position " << i << endl;
        cin >> arr[i];
    }
    cout << "Various opertions are: " << endl;
    cout << "1. Insert(position,element)" << endl;
    cout << "2. Get(position,element)" << endl;
    cout << "3. Sort" << endl;
    cout << "4. Linear Search(element)" << endl;
    cout << "5. Binary Search(element)" << endl;
    cout << "6. Delete(position)" << endl;
    cout << "7. Get Size" << endl;
    cout << "8. Max" << endl;
    cout << "9. Min" << endl;
    cout << "10. Reverse" << endl;
    cout << "11. Shift" << endl;
    cout << "12. Rotate" << endl;
    cout << "13. Display" << endl;
    cout << "14. Exit" << endl;
    CustomArray myArr(arr, size);
    int choice;
    while (true)
    {
        cout << "Enter choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int pos, ele;
            cout << "Enter position and element" << endl;
            cin >> pos >> ele;
            myArr.Insert(pos, ele);
            break;
        case 2:
            int pos1;
            cout << "Enter position" << endl;
            cin >> pos1;
            cout << myArr.Get(pos1) << endl;
            break;
        case 3:
            myArr.Sort();
            myArr.Display();
            break;
        case 4:
            int ele1;
            cout << "Enter element" << endl;
            cin >> ele1;
            cout << myArr.LinearSearch(ele1) << endl;
            break;
        case 5:
            int ele2;
            cout << "Enter element" << endl;
            cin >> ele2;
            cout << myArr.BinarySearch(ele2) << endl;
            break;
        case 6:
            int pos2;
            cout << "Enter position" << endl;
            cin >> pos2;
            myArr.Delete(pos2);
            break;
        case 7:
            cout << myArr.GetSize() << endl;
            break;
        case 8:
            cout << myArr.Max() << endl;
            break;
        case 9:
            cout << myArr.Min() << endl;
            break;
        case 10:
            myArr.Reverse();
            myArr.Display();
            break;
        case 11:
            myArr.Shift();
            myArr.Display();
            break;
        case 12:
            myArr.Rotate();
            myArr.Display();
            break;
        case 13:
            myArr.Display();
            break;
        case 14:
            exit(0);
        }
    }
    return 0;
}