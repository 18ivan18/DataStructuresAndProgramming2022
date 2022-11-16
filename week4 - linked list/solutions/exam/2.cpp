#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <cassert>

class OYAML
{
private:
    const int tabIndentation = 4;

    struct Dict;

    struct Value
    {
        std::string *str;
        Dict *dict;
    };

    struct Pair
    {
        std::string key;
        Value value;
    };

    struct Dict
    {
        std::string dictName;
        std::vector<Pair *> v;
    };

    Dict *root;

    bool insertUtil(Dict *root, std::string locatorKey, Pair *p)
    {
        if (root->dictName == locatorKey)
        {
            root->v.push_back(p);
            return true;
        }
        for (auto &&pair : root->v)
        {
            if (pair->value.dict && insertUtil(pair->value.dict, locatorKey, p))
            {
                return true;
            }
        }
        return false;
    }

    void deleteDict(Dict *dict)
    {
        if (!dict)
        {
            return;
        }
        for (auto &&pair : dict->v)
        {
            if (pair->value.str)
            {
                delete pair->value.str;
            }
            else
            {
                deleteDict(pair->value.dict);
            }
            delete pair;
        }
        delete dict;
    }

    void indent(int level)
    {
        for (size_t i = 0; i < level * tabIndentation; i++)
        {
            std::cout << " ";
        }
    }

    void print(Dict *d, int level)
    {
        if (!d)
        {
            return;
        }
        indent(level);
        std::cout << "dictName: " << d->dictName << std::endl;
        for (auto &&pair : d->v)
        {
            indent(level);
            std::cout << pair->key << ": ";
            if (pair->value.str)
            {
                std::cout << *pair->value.str << std::endl;
            }
            else
            {
                std::cout << std::endl;
                print(pair->value.dict, level + 1);
            }
        }
    }

    std::string find(std::deque<std::string> &pathTokens, Dict *dict)
    {
        if (pathTokens.empty())
        {
            return "";
        }

        for (auto &&pair : dict->v)
        {
            if (pathTokens.size() == 1 && pair->value.str && pair->key == pathTokens.front())
            {
                return *pair->value.str;
            }
            if (pair->value.dict && pair->key == pathTokens.front())
            {
                pathTokens.pop_front();
                return find(pathTokens, pair->value.dict);
            }
        }
        return "";
    }

public:
    OYAML(std::string name) : root{new Dict{name}}
    {
    }

    void insert(std::string locatorKey, std::string newKey, std::string newValue)
    {
        Value val{new std::string(newValue), nullptr};
        Pair *pair = new Pair{newKey, val};
        if (!insertUtil(root, locatorKey, pair))
        {
            root->v.push_back(pair);
        }
    }

    void insertDict(std::string locatorKey, std::string newKey, std::string dictName)
    {
        Value val{nullptr, new Dict{dictName}};
        Pair *pair = new Pair{newKey, val};
        if (!insertUtil(root, locatorKey, pair))
        {
            root->v.push_back(pair);
        }
    }

    std::string find(const std::string &path)
    {
        std::stringstream ss(path);
        std::deque<std::string> p;
        std::string item;
        while (getline(ss, item, '/'))
        {
            p.push_back(item);
        }

        return find(p, root);
    }

    void print()
    {
        print(root, 0);
    }

    ~OYAML() { deleteDict(root); }
};

int main()
{
    OYAML oyaml("main dictionary");
    oyaml.insert("", "value", "5");
    oyaml.insertDict("", "innerDict1", "first inner dictionary");
    oyaml.insert("first inner dictionary", "value", "10");
    oyaml.insert("first inner dictionary", "anotherValue", "100");
    oyaml.insertDict("", "innerDict2", "second inner dictionary");
    oyaml.insert("second inner dictionary", "value", "15");
    oyaml.insert("second inner dictionary", "purpose", "show more levels of nesting");
    oyaml.insertDict("second inner dictionary", "innerDict3", "innermost dictionary");
    oyaml.insert("innermost dictionary", "value", "20");
    oyaml.insert("innermost dictionary", "someOtherKey", "anything here");
    oyaml.print();

    assert(oyaml.find("innerDict2/innerDict3/value") == "20");
    assert(oyaml.find("value") == "5");
    assert(oyaml.find("hjdfauk") == "");
}