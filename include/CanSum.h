#ifndef CANSUM_H
#define CANSUM_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class CanSum
{
public:
    bool run(int n, vector<int> nums, map<int, bool> &memo)
    {
        if (n == 0) return true;
        if (n < 0) return false;

        if (memo.count(n) > 0)
            return memo[n];
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (run(n - nums[i], nums, memo))
                return true;
        }

        memo.insert(pair<int, bool>(n, false));
        return memo[n];
    }
};

#endif