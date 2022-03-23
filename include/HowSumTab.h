#ifndef HOWSUMTAB_H
#define HOWSUMTAB_H

#include <iostream>
#include <vector>

using namespace std;

class HowSumTab
{
public:
    vector<int> run(int targetSum, vector<int> numbers)
    {
        vector<vector<int>> table(targetSum + 1, {-1});
        table[0] = {};
        for (int i = 0; i <= targetSum; i++)
        {
            if (table[i].size() == 0 || table[i].front() != -1)
            {
                for (auto num : numbers)
                {
                    if (i+num < table.size())
                    {
                        table[i+num] = table[i];
                        table[i+num].push_back(num);
                    }
                }
            }
        }

        return table[targetSum];
    }
};

#endif