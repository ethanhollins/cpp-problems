#ifndef GRIDTRAVELLER_H
#define GRIDTRAVELLER_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class GridTraveller
{
public:
    long long int run(int m, int n, map<string, long long int> &memo)
    {
        if (m == 0 || n == 0) return 0;
        if (m == 1 && n == 1) return 1;

        string key = to_string(m) + "," + to_string(n);
        if (memo.count(key) > 0)
            return memo[key];

        memo.insert(pair<string, int>(key, run(m-1, n, memo) + run(m, n-1, memo)));
        return memo[key];
    }
};

#endif