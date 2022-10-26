#include <string>
#include <stack>
#include <cassert>
#include <iostream>

bool isValid(std::string s)
{
    std::stack<char> stackOfParentheses;
    for (auto &&i : s)
    {
        switch (i)
        {
        case '{':
        case '(':
        case '[':
            stackOfParentheses.push(i);
            break;
        case '}':
        {
            if (!stackOfParentheses.size())
            {
                return false;
            }
            char p = stackOfParentheses.top();
            stackOfParentheses.pop();
            if (p != '{')
            {
                return false;
            }
            break;
        }
        case ')':
        {
            if (!stackOfParentheses.size())
            {
                return false;
            }
            char p = stackOfParentheses.top();
            stackOfParentheses.pop();
            if (p != '(')
            {
                return false;
            }
            break;
        }
        case ']':
        {
            if (!stackOfParentheses.size())
            {
                return false;
            }
            char p = stackOfParentheses.top();
            stackOfParentheses.pop();
            if (p != '[')
            {
                return false;
            }
            break;
        }

        default:
            return false;
        }
    }
    return !stackOfParentheses.size();
}

int main()
{
    assert(isValid("()"));
    assert(!isValid("["));
    assert(!isValid("]"));
    assert(!isValid("()(()"));
    assert(isValid("()[]{}"));
    assert(!isValid("(]"));
    assert(!isValid("([)]"));
    assert(isValid("{[]}"));
}