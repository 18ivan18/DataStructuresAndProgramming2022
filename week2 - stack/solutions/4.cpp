#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <cassert>

int evalRPN(const std::vector<std::string> &tokens)
{
    std::stack<int> stk;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        {
            stk.push(stoi(tokens[i]));
            continue;
        }
        int num1 = stk.top();
        stk.pop();
        int num2 = stk.top();
        stk.pop();
        if (tokens[i] == "+")
        {
            stk.push(num1 + num2);
        }
        else if (tokens[i] == "-")
        {
            stk.push(num2 - num1);
        }
        else if (tokens[i] == "*")
        {
            stk.push(num1 * num2);
        }
        else
        {
            stk.push(num2 / num1);
        }
    }

    return stk.top();
}

int main()
{
    assert(evalRPN({"2", "1", "+", "3", "*"}) == 9);
    assert(evalRPN({"4", "13", "5", "/", "+"}) == 6);
    assert(evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}) == 22);
}