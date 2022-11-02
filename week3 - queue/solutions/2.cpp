#include <stack>
class MyQueue
{
    std::stack<int> s1, s2;
    int front;

public:
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        // Time complexity: O(1). Аppending an element to a stack is an O(1) operation.
        // Space complexity: O(n). We need additional memory to store the queue elements
        if (s1.empty())
        {
            front = x;
        }
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        // Time complexity: Amortized O(1), Worst-case O(n). In the worst case scenario when stack s2 is empty, the algorithm pops nn elements from stack s1 and pushes nn elements to s2, where nn is the queue size. This gives 2n operations, which is O(n). But when stack s2 is not empty the algorithm has O(1) time complexity. So what does it mean by Amortized O(1)? Please see the next section on Amortized Analysis for more information.
        // Space complexity : O(1)O(1).
        // Amortized Analysis
        // Amortized analysis gives the average performance (over time) of each operation in the worst case. The basic idea is that a worst case operation can alter the state in such a way that the worst case cannot occur again for a long time, thus amortizing its cost.

        // Consider this example where we start with an empty queue with the following sequence of operations applied:

        // push_1, push_2, ..., push_n, pop_1,pop_2 ..., pop_n​

        // The worst case time complexity of a single pop operation is O(n). Since we have nn pop operations, using the worst-case per operation analysis gives us a total of O(n^2) time.

        // However, in a sequence of operations the worst case does not occur often in each operation - some operations may be cheap, some may be expensive. Therefore, a traditional worst-case per operation analysis can give overly pessimistic bound. For example, in a dynamic array only some inserts take a linear time, though others - a constant time.

        // In the example above, the number of times pop operation can be called is limited by the number of push operations before it. Although a single pop operation could be expensive, it is expensive only once per n times (queue size), when s2 is empty and there is a need for data transfer between s1 and s2. Hence the total time complexity of the sequence is : n (for push operations) + 2*n (for first pop operation) + n - 1 ( for pop operations) which is O(2∗n).This gives O(2n/2n) = O(1) average time per operation.
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int result = s2.top();
        s2.pop();
        return result;
    }

    /** Get the front element. */
    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        return front;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty() && s2.empty();
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