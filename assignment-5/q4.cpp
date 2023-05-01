#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isMatchingPair(char char1, char char2)
{
    if (char1 == '(' && char2 == ')')
    {
        return true;
    }
    else if (char1 == '{' && char2 == '}')
    {
        return true;
    }
    else if (char1 == '[' && char2 == ']')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool areParenthesesBalanced(string expression)
{
    stack<char> st;
    for (char &c : expression)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.empty() || !isMatchingPair(st.top(), c))
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main()
{
    string expression = "((()))";
    if (areParenthesesBalanced(expression))
    {
        cout << "Parentheses are balanced" << endl;
    }
    else
    {
        cout << "Parentheses are not balanced" << endl;
    }
    return 0;
}
