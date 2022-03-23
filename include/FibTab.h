#ifndef FIBTAB_H
#define FIBTAB_H

#include <iostream>
#include <vector>

using namespace std;

class FibTab
{
public:
    long long int run(int n)
    {
        vector<long long int> table(n+1, 0);
        table[1] = 1;

        for (int i = 2; i < table.size(); i++)
        {
            table[i] = table[i-1] + table[i-2];
        }

        return table[n];
    }
};

#endif