#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// Data structure to represent an interval
struct Interval
{
    int begin, end;

    bool operator<(Interval const &i)
    {
        return (begin < i.begin);
    }

    friend std::ostream &operator<<(std::ostream &os, const Interval &i)
    {
        os << "{" << i.begin << ", " << i.end << "}\n";
        return os;
    }
};

// Function to merge overlapping intervals
void mergeIntervals(std::vector<Interval> intervals) // no-ref, no-const
{
    // sort the intervals in increasing order of their starting time
    sort(intervals.begin(), intervals.end());

    // create an empty stack
    std::stack<Interval> st;

    // do for each interval
    for (const Interval &curr : intervals)
    {
        // if the stack is empty or the top interval in the stack does not overlap
        // with the current interval, push it into the stack
        if (st.empty() || curr.begin > st.top().end)
        {
            st.push(curr);
        }

        // if the top interval of the stack overlaps with the current interval,
        // merge two intervals by updating the end of the top interval
        // to the current interval
        if (st.top().end < curr.end)
        {
            st.top().end = curr.end;
        }
    }

    // print all non-overlapping intervals
    while (!st.empty())
    {
        std::cout << st.top();
        st.pop();
    }
}

int main()
{
    std::vector<Interval> intervals = {{1, 5}, {2, 3}, {4, 6}, {7, 8}, {8, 10}, {12, 15}};

    mergeIntervals(intervals);
}