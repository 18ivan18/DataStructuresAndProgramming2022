#include <string>
#include <stack>
#include <cassert>

int calculate(std::string s)
{
    std::stack<int> sum, op;
    char c;
    int number = 0, sign = 1, currSum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
        if (c == '(')
        {
            sum.push(currSum);
            op.push(sign);
            currSum = 0;
            sign = 1;
        }
        if (c == ')')
        {
            currSum = currSum * op.top() + sum.top();
            sum.pop();
            op.pop();
        }
        if (isdigit(c))
        {
            number = 0;
            while (i < s.size() && isdigit(s[i]))
            {
                number = number * 10 + (s[i] - '0');
                i++;
            }
            i--;
            currSum += number * sign;
            sign = 1;
        }
        if (c == '-')
        {
            sign *= -1;
        }
    }
    return currSum;
}

int main()
{
    assert(calculate("1 + 1") == 2);
    assert(calculate(" 2-1 + 2 ") == 3);
    assert(calculate("(1+(4+5+2)-3)+(6+8)") == 23);
}