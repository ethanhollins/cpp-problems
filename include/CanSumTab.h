#ifndef CANSUMTAB_H
#define CANSUMTAB_H

#include <iostream>
#include <vector>

using namespace std;

class CanSumTab
{
public:
    bool run(int targetSum, vector<int> numbers)
    {
        vector<bool> table(targetSum + 1, false);
        table[0] = true;
        for (int i = 0; i <= targetSum; i++)
        {
            if (table[i])
            {
                for (auto num : numbers)
                {
                    table[i + num] = true;
                }
            }
        }

        return table[targetSum];
    }
};

#endif