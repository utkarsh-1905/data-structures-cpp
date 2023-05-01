#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int index = 0, pivotElement = arr[end], pivotIndex;
    int *temp = new int[end - start + 1]; // making an array whose size is equal to current partition range...
    for (int i = start; i <= end; i++)    // pushing all the elements in temp which are smaller than pivotElement
    {
        if (arr[i] < pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    temp[index] = pivotElement; // pushing pivotElement in temp
    index++;

    for (int i = start; i < end; i++) // pushing all the elements in temp which are greater than pivotElement
    {
        if (arr[i] > pivotElement)
        {
            temp[index] = arr[i];
            index++;
        }
    }

    index = 0;
    for (int i = start; i <= end; i++) // copying all the elements to original array i.e arr
    {
        if (arr[i] == pivotElement)
        {
            pivotIndex = i;
        }
        arr[i] = temp[index];
        index++;
    }
    return pivotIndex; // returning pivotIndex
}
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end); // for getting partition
        quickSort(arr, start, partitionIndex - 1);       // sorting left side array
        quickSort(arr, partitionIndex + 1, end);         // sorting right side array
    }
    return;
}
int main()
{
    int *arr, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    // printing the array
    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
