#include <list>
#include <string>
class BrowserHistory
{
    std::list<std::string> history;
    std::list<std::string>::iterator it;

public:
    BrowserHistory(std::string homepage)
    {
        history.push_back(homepage);
        it = history.begin();
    }

    void visit(std::string url)
    {
        auto next = it;
        next++;
        history.erase(next, history.end());
        history.push_back(url);
        it++;
    }

    std::string back(int steps)
    {
        while (it != history.begin() && steps--)
        {
            it--;
        }
        return *it;
    }

    std::string forward(int steps)
    {
        while (it != --history.end() && steps--)
        {
            it++;
        }
        return *it;
    }
};