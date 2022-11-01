#include <queue>

class FrontMiddleBackQueue
{
    int size;
    std::deque<int> left, right;

    // adjusts itself such that left.size() >= right.size()
    void adjust()
    {
        int diff = size & 1; // either 1 or 0
        while (left.size() > (diff + right.size()))
        {
            int val = left.back();
            left.pop_back();
            right.push_front(val);
        }
        while (left.size() < (diff + right.size()))
        {
            int val = right.front();
            right.pop_front();
            left.push_back(val);
        }
    }

public:
    FrontMiddleBackQueue() : size(0)
    {
    }

    void pushFront(int val)
    {
        adjust();
        left.push_front(val);
        size++;
        adjust();
    }

    void pushMiddle(int val)
    {
        adjust();
        if (size & 1)
        {
            int val = left.back();
            left.pop_back();
            right.push_front(val);
        }
        left.push_back(val);
        size++;
        adjust();
    }

    void pushBack(int val)
    {
        adjust();
        right.push_back(val);
        size++;
        adjust();
    }

    int popFront()
    {
        if (size == 0)
        {
            return -1;
        }
        adjust();
        int val = left.front();
        left.pop_front();
        size--;
        adjust();
        return val;
    }

    int popMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        adjust();
        int val = left.back();
        left.pop_back();
        size--;
        adjust();
        return val;
    }

    int popBack()
    {
        if (size == 0)
        {
            return -1;
        }
        if (size == 1)
        {
            adjust();
            int val = left.back();
            left.pop_back();
            size--;
            adjust();
            return val;
        }
        adjust();
        int val = right.back();
        right.pop_back();
        size--;
        adjust();
        return val;
    }
};