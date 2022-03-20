#ifndef HOWSUM_H
#define HOWSUM_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class HowSum
{
public:
    vector<int> run(int n, vector<int> nums, map<int, vector<int>> &memo)
    {
        if (n == 0) return {};
        if (n < 0) return {-1};

        if (memo.count(n) > 0)
            return memo[n];
        
        for (auto num : nums)
        {
            vector<int> res = run(n - num, nums, memo);
            if (res.size() == 0 || res.front() != -1)
            {
                res.push_back(num);
                return res;
            }
        }

        memo.insert(pair<int, vector<int>>(n, {-1}));
        return memo[n];
    }
};

#endif