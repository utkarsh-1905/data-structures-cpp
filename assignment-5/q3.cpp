#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int performOperation(char op, int operand1, int operand2)
{
    switch (op)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}

int evaluatePostfix(string expression)
{
    stack<int> st;
    stringstream ss(expression);
    string token;
    while (ss >> token)
    {
        if (isdigit(token[0]))
        {
            int num = stoi(token);
            st.push(num);
        }
        else if (isOperator(token[0]))
        {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result = performOperation(token[0], operand1, operand2);
            st.push(result);
        }
    }
    return st.top();
}

int main()
{
    string expression = "54 6 + 7 4 - * 9 / 35 15 + +";
    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl; // Output: 28
    return 0;
}
