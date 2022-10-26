#include <stack>
class MinStack
{
public:
    // we can use only 1 stack <pair<int, int>>
    std::stack<int> st, minSt;

    MinStack()
    {
    }

    void push(int val)
    {
        st.push(val);
        if (minSt.empty())
        {
            minSt.push(val);
        }
        else
        {
            minSt.push(std::min(val, minSt.top()));
        }
    }

    void pop()
    {
        st.pop();
        minSt.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */