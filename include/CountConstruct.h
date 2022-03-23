#ifndef COUNTCONSTRUCT_H
#define COUNTCONSTRUCT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class CountConstruct
{
public:
    int run(string target, vector<string> wordBank, map<string, int> &memo)
    {
        if (target == "") return 1;

        if (memo.count(target) > 0)
            return memo[target];

        int count = 0;
        for (int i = 0; i < wordBank.size(); i++)
        {
            string substr = wordBank[i];
            int substr_idx = target.find(substr);
            if (substr_idx == 0)
            {
                string new_target = target;
                new_target.erase(substr_idx, substr.size());

                count += run(new_target, wordBank, memo);
            }
        }

        memo.insert(pair<string, int>(target, count));
        return count;
    }
};

#endif