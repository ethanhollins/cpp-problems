#ifndef FIB_H
#define FIB_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Fib
{
public:
    long long int run(int n, map<long long int, long long int> &memo)
    {
        if (memo.count(n) > 0)
            return memo[n];

        memo.insert(pair<long long int, long long int>(n, run(n - 1, memo) + run(n - 2, memo)));
        return memo[n];
    }
};

#endif