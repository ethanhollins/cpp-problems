#ifndef CANCONSTRUCT_H
#define CANCONSTRUCT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class CanConstruct
{
public:
    bool run(string target, vector<string> wordBank, map<string, bool> &memo)
    {
        if (target == "") return true;

        if (memo.count(target) > 0)
            return memo[target];

        for (int i = 0; i < wordBank.size(); i++)
        {
            string substr = wordBank[i];
            int substr_idx = target.find(substr);
            if (substr_idx == 0)
            {
                string new_target = target;
                new_target.erase(substr_idx, substr.size());
                if (run(new_target, wordBank, memo))
                    return true;
            }
        }

        memo.insert(pair<string, bool>(target, false));
        return false;
    }
};

#endif