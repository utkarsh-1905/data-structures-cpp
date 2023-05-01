// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void radix(vector<int> arr)
{
    int max = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        vector<int> output(arr.size());
        int i, count[10] = {0};

        for (i = 0; i < arr.size(); i++)
            count[(arr[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = arr.size() - 1; i >= 0; i--)
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < arr.size(); i++)
            arr[i] = output[i];

        print(arr);
    }
}

// Driver code
int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Given array is \n";
    print(arr);

    cout << "\nStarted sorting" << endl;
    radix(arr);

    cout << "\nSorted array is \n";
    print(arr);
    return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
