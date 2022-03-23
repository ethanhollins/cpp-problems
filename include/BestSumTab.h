#ifndef BESTSUMTAB_H
#define BESTSUMTAB_H

#include <iostream>
#include <vector>

using namespace std;

class BestSumTab
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
                    vector<int> item_cpy = table[i];
                    item_cpy.push_back(num);
                    if (i+num < table.size())
                    {
                        if ((table[i+num].size() > 0 && table[i+num].front() == -1)
                            || table[i+num].size() > item_cpy.size())
                        {
                            table[i+num] = item_cpy;
                        }
                    }
                }
            }
        }

        return table[targetSum];
    }
};

#endif