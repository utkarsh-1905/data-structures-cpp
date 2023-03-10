#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class StringOps
{
public:
    string myString;

    StringOps(string data)
    {
        myString = data;
    }

    int Length()
    {
        if (myString.empty())
        {
            return 0;
        }
        return myString.length();
    }

    string LowerCase()
    {
        if (myString.empty())
        {
            return "";
        }
        transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
        return myString;
    }

    int NumberOfWords()
    {
        if (myString.empty())
        {
            return 0;
        }
        int count = 1;
        auto it = myString.begin();
        while (it != myString.end())
        {
            if (*it == ' ')
            {
                count++;
            }
            ++it;
        }
        return count;
    }

    int NumberOfVowels()
    {
        if (myString.empty())
        {
            return 0;
        }
        int count = 0;
        string chotiString = LowerCase();
        auto it = chotiString.begin();
        while (it != chotiString.end())
        {
            if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
            {
                count++;
            }
            ++it;
        }
        return count;
    }

    string ValidString()
    {
        if (myString.empty())
        {
            return "false";
        }
        int count = 0;
        auto it = myString.begin();
        while (it != myString.end())
        {
            if ((int)*it >= 65 || (int)*it <= 91 || (int)*it >= 97 || (int)*it <= 123)
            {
                count++;
                ++it;
            }
        }
        if (count > 0)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }

    string Reverse()
    {
        if (myString.empty())
        {
            return "";
        }
        auto it = myString.rbegin();
        string revString = "";
        while (it != myString.rend())
        {
            revString += *it;
            ++it;
        }
        return revString;
    }

    string Palindrome()
    {
        if (myString.empty())
        {
            return "false";
        }
        string revString = Reverse();
        return myString == revString ? "true" : "false";
    }

    // finding duplicate characters in string
    string Duplicate()
    {
        if (myString.empty())
        {
            return "";
        }
        string dupString = "";
        auto it = myString.begin();
        while (it != myString.end())
        {
            if (dupString.find(*it) == string::npos)
            {
                dupString += *it;
            }
            ++it;
        }
        return dupString;
    }
};

int main()
{
    string temp;
    cout << "Enter a string: " << endl;
    getline(cin, temp);
    StringOps myString(temp);
    cout << "Choices :" << endl;
    cout << "1. Length of string" << endl;
    cout << "2. Lower case string" << endl;
    cout << "3. Number of words" << endl;
    cout << "4. Number of vowels" << endl;
    cout << "5. Valid string" << endl;
    cout << "6. Reverse string" << endl;
    cout << "7. Palindrome" << endl;
    cout << "8. Duplicate characters" << endl;
    cout << "9. Exit" << endl;
    int choice;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Length of string is: " << myString.Length() << endl;
            break;

        case 2:
            cout << "Lower case string is: " << myString.LowerCase() << endl;
            break;

        case 3:
            cout << "Number of words is: " << myString.NumberOfWords() << endl;
            break;

        case 4:
            cout << "Number of vowels is: " << myString.NumberOfVowels() << endl;
            break;

        case 5:
            cout << "Valid string is: " << myString.ValidString() << endl;
            break;

        case 6:
            cout << "Reverse string is: " << myString.Reverse() << endl;
            break;

        case 7:
            cout << "Palindrome is: " << myString.Palindrome() << endl;
            break;

        case 8:
            cout << "Duplicate characters are: " << myString.Duplicate() << endl;
            break;

        case 9:
            exit(0);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}