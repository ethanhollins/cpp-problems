#ifndef COUNTCONSTRUCTTAB_H
#define COUNTCONSTRUCTTAB_H

#include <iostream>
#include <vector>

using namespace std;

class CountConstructTab
{
public:
    int run(string target, vector<string> wordBank)
    {
        vector<int> table(target.size()+1, 0);
        table[0] = 1;

        for (int i = 0; i <= target.size(); i++)
        {
            if (table[i] > 0)
            {
                for (auto word : wordBank)
                {
                    if (i + word.size() <= target.size() && target.substr(i, word.size()).compare(word) == 0)
                    {
                        table[i + word.size()] += table[i];
                    }
                }
            }
        }

        return table[target.size()];
    }
};

#endif