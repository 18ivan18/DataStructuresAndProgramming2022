#include <string>
#include <stack>
#include <cassert>
#include <iostream>

std::string input1 = "/home/";
std::string input2 = "/../";
std::string input3 = "/home//foo/";
std::string input4 = "/a/./b/../../c/";
std::string input5 = "/a//b////c/d//././/..";

std::string output1 = "/home";
std::string output2 = "/";
std::string output3 = "/home/foo";
std::string output4 = "/c";
std::string output5 = "/a/b/c";

std::string simplifyPath(std::string path)
{
    std::stack<std::string> st;
    std::string res;

    for (int i = 0; i < path.size(); i++)
    {
        if (path[i] == '/')
        {
            continue;
        }
        std::string currentWord;
        // iterate till we doesn't traverse the whole string and doesn't encounter the last /
        while (i < path.size() && path[i] != '/')
        {
            // add path to temp string
            currentWord += path[i];
            i++;
        }
        if (currentWord == ".")
        {
            continue;
        }
        // pop the top element from stack if exists
        else if (currentWord == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            // push the directory file name to stack
            st.push(currentWord);
        }
    }

    // adding all the stack elements to res
    while (!st.empty())
    {
        res = "/" + st.top() + res;
        st.pop();
    }

    // if no directory or file is present
    if (res.size() == 0)
    {
        return "/";
    }

    return res;
}

int main()
{
    assert(output1 == simplifyPath(input1));
    assert(output2 == simplifyPath(input2));
    assert(output3 == simplifyPath(input3));
    assert(output4 == simplifyPath(input4));
    assert(output5 == simplifyPath(input5));
}