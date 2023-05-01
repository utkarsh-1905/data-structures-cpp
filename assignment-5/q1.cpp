#include <bits/stdc++.h>
using namespace std;
void printKMax(int arr[], int N, int K)
{
    int j, max;

    for (int i = 0; i <= N - K; i++)
    {
        max = arr[i];

        for (j = 1; j < K; j++)
        {
            if (arr[i + j] > max)
                max = arr[i + j];
        }
        cout << max << " ";
    }
}
int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 3;
    printKMax(arr, N, K);
    return 0;
}