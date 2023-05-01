#include <iostream>
using namespace std;

void countSort(int *arr, int n, int k)
{
    int count[k + 1] = {0};
    int output[n];

    // Count the occurrences of each element
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Calculate the prefix sum
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    // Sort the elements
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
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

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // bubble sort
    countSort(arr, n, max);

    // printing the array

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}