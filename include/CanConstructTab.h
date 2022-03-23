#ifndef CANCONSTRUCTTAB_H
#define CANCONSTRUCTTAB_H

#include <iostream>
#include <vector>

using namespace std;

class CanConstructTab
{
public:
    bool run(string target, vector<string> wordBank)
    {
        vector<bool> table(target.size()+1, false);
        table[0] = true;

        for (int i = 0; i <= target.size(); i++)
        {
            if (table[i])
            {
                for (auto word : wordBank)
                {
                    if (i + word.size() <= target.size() && target.substr(i, word.size()).compare(word) == 0)
                    {
                        table[i + word.size()] = true;
                    }
                }
            }
        }

        return table[target.size()];
    }
};

#endif