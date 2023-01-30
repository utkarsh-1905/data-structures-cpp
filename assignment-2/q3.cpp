#include <iostream>
using namespace std;

class ArrayOps
{

private:
    int size;
    int *arr;

public:
    ArrayOps(int *arr, int size)
    {
        this->arr = arr;
        this->size = size;
    }

    int Find(int s)
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

    void Find(int *findArr, int findSize)
    {
        for (int i = 0; i < findSize; i++)
        {
            int index = Find(findArr[i]);
            if (index != -1)
            {
                cout << findArr[i] << " found at index " << index << endl;
            }
            else
            {
                cout << findArr[i] << " not found" << endl;
            }
        }
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
};

int main()
{
}