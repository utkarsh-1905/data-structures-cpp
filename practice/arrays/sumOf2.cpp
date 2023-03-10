#include <iostream>
#include <vector>

using namespace std;

// iterative method
bool checkIsSum(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                if (arr.at(i) == arr.at(j) + arr.at(k))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// recursive method
bool checkIsSumR(vector<int> arr, int i)
{
    if (arr.size() < 2)
    {
        return false;
    }
    else if (i >= arr.size())
    {
        return false;
    }
    else
    {
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(9);
    arr.push_back(26);
    arr.push_back(92);
    arr.push_back(44);
    arr.push_back(872);

    cout << "Array Elements:\t";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr.at(i) << "\t";
    }
    cout << endl;

    bool ans = checkIsSumR(arr, 1);
    cout << boolalpha << ans << endl;
}