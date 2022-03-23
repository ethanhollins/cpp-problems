#ifndef ALLCONSTRUCT_H
#define ALLCONSTRUCT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class AllConstruct
{
public:
    vector<vector<string>> run(string target, vector<string> wordBank, map<string, vector<vector<string>>> &memo)
    {
        if (target == "") return {{}};

        if (memo.count(target) > 0)
            return memo[target];

        vector<vector<string>> res = {};
        for (int i = 0; i < wordBank.size(); i++)
        {
            string substr = wordBank[i];
            int substr_idx = target.find(substr);
            if (substr_idx == 0)
            {
                string new_target = target;
                new_target.erase(substr_idx, substr.size());

                vector<vector<string>> suffix_ways = run(new_target, wordBank, memo);
                for (int j = 0; j < suffix_ways.size(); j++)
                {
                    suffix_ways[j].push_back(substr);
                    res.push_back(suffix_ways[j]);
                }
            }
        }

        memo.insert(pair<string, vector<vector<string>>>(target, res));
        return res;
    }
};

#endif