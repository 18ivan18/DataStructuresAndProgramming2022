#include "TwoSAT.h"

std::vector<std::string> TwoSAT::split(std::string &s, const std::string &delimiter)
{
    std::vector<std::string> list;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}

TwoSAT::TwoSAT(const std::string &string)
{
    std::string input = string;
    // std::cout << input << std::endl;
    // doesn't work for some reason
    const std::regex regex("^(\\(~?[a-z]V~?[a-z]\\)\\^?)*$");
    if (!std::regex_match(input, regex))
    {
        throw std::invalid_argument("Input is not in conjunctive normal form.");
    }
    std::vector<std::string> clauses = split(input, "^");
    std::vector<std::pair<std::string, std::string>> allClauses;
    for (auto &clause : clauses)
    {
        std::string withoutBraces = clause.substr(1, clause.size() - 2);
        std::vector<std::string> clauses = split(withoutBraces, "V");
        if (clauses.size() != 2)
        {
            throw std::invalid_argument("Something went wrong...");
        }

        allClauses.push_back({clauses[0], clauses[1]});
        for (auto &literal : clauses)
        {
            if (literal[0] == '~')
            {
                if (std::find(set.begin(), set.end(), literal[1]) == set.end())
                {
                    set.push_back(literal[1]);
                }
            }
            else
            {
                if (std::find(set.begin(), set.end(), literal[0]) == set.end())
                {
                    set.push_back(literal[0]);
                }
            }
        }
    }

    // std::cout
    //     << set.size() << std::endl;
    // for (auto &literal : set)
    // {
    //     std::cout << literal << " ";
    // }
    // std::cout << std::endl;
    Digraph *G = new Digraph(set.size() * 2);
    for (auto &literal : allClauses)
    {
        // std::cout << literal.first << " " << literal.second << "\n";
        int first, second, notFirst, notSecond;
        if (literal.first[0] == '~')
        {
            first = (std::find(set.begin(), set.end(), literal.first[1]) - set.begin()) * 2 + 1;
            notFirst = first - 1;
        }
        else
        {
            first = (std::find(set.begin(), set.end(), literal.first[0]) - set.begin()) * 2;
            notFirst = first + 1;
        }

        if (literal.second[0] == '~')
        {
            second = (std::find(set.begin(), set.end(), literal.second[1]) - set.begin()) * 2 + 1;
            notSecond = second - 1;
        }
        else
        {
            second = (std::find(set.begin(), set.end(), literal.second[0]) - set.begin()) * 2;
            notSecond = second + 1;
        }
        G->addEdge(notFirst, second);
        G->addEdge(notSecond, first);
    }

    Digraph *temp = G;
    G = G->reverse();
    delete temp;
    KosarajuSharirSCC scc(*G);
    assignment.assign(G->V() / 2, {NULL, false});
    for (int i = 0; i < G->V(); i += 2)
    {
        if (scc.stronglyConnected(i, i + 1))
        {
            satisfiable = false;
            delete G;
            return;
        }
        assignment[i / 2] = {set[i / 2], (scc.componentOf(i) > scc.componentOf(i + 1))};
    }
    satisfiable = true;

    delete G;
}

TwoSAT::~TwoSAT()
{
}

bool TwoSAT::isSatisfiable() { return satisfiable; }

std::vector<std::pair<char, bool>> TwoSAT::getAssignment() { return assignment; }