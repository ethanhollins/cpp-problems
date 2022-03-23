#ifndef ALLCONSTRUCTTAB_H
#define ALLCONSTRUCTTAB_H

#include <iostream>
#include <vector>

using namespace std;

class AllConstructTab
{
public:
    vector<vector<string>> run(string target, vector<string> wordBank)
    {
        vector<vector<vector<string>>> table(target.size()+1, vector<vector<string>>());
        table[0].push_back({});

        for (int i = 0; i <= target.size(); i++)
        {
            for (auto word : wordBank)
            {
                if (i + word.size() <= target.size() && target.substr(i, word.size()).compare(word) == 0)
                {
                    for (int j = 0; j < table[i].size(); j++)
                    {
                        table[i + word.size()].push_back(table[i][j]);
                        table[i + word.size()].back().push_back(word);
                    }
                }
            }
        }

        return table[target.size()];
    }
};

#endif