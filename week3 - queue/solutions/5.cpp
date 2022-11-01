#include <queue>

int findTheWinner(int n, int k)
{
    std::queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    while (q.size() != 1)
    {
        for (int i = 1; i < k; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
    }

    return q.front();
}