#include <iostream>
#include <stack>
#include <cassert>
#include <vector>

int poisonousPlants(std::vector<int> p)
{
    // create stacks
    std::vector<std::stack<int>> stacks;
    std::stack<int> temp;
    for (int j = p.size() - 1; j >= 0; j--)
    {
        temp.push(p[j]);
        if (j == 0 || p[j] > p[j - 1])
        {
            stacks.push_back(temp);
            temp = std::stack<int>();
        }
    }

    // now, to let one day pass:
    // pop the top element from every stack (excluding the unique leftmost stack).
    // these are the plants that die on this day.
    int days = 0;
    while (stacks.size() != 1)
    {
        days++;
        for (int i = 0; i < stacks.size() - 1; i++)
        {
            stacks[i].pop();
            if (stacks[i].empty())
            {
                stacks.erase(stacks.begin() + i);
                i--;
            }
        }
        for (int i = stacks.size() - 1; i > 0; i--)
        {
            int first = stacks[i - 1].top(), last;
            std::stack<int> temp = stacks[i];
            while (!temp.empty())
            {
                last = temp.top();
                temp.pop();
            }
            if (last >= first)
            {
                std::stack<int> reverse;
                while (!stacks[i].empty())
                {
                    reverse.push(stacks[i].top());
                    stacks[i].pop();
                }
                while (!reverse.empty())
                {
                    stacks[i - 1].push(reverse.top());
                    reverse.pop();
                }
                stacks.erase(stacks.begin() + i);
                i--;
            }
        }
    }
    return days;
}
int main()
{
    assert(poisonousPlants({3, 6, 2, 7, 5}) == 2);
    assert(poisonousPlants({6, 5, 8, 4, 7, 10, 9}) == 2);
}