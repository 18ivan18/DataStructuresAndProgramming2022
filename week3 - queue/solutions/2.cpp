#include <stack>
class MyQueue
{
    std::stack<int> st;

public:
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        st.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        std::stack<int> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        int result = temp.top();
        temp.pop();
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return result;
    }

    /** Get the front element. */
    int peek()
    {
        std::stack<int> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        int result = temp.top();
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        return result;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */