#ifndef GRIDTRAVELLERTAB_H
#define GRIDTRAVELLERTAB_H

#include <iostream>
#include <vector>

using namespace std;

class GridTravellerTab
{
public:
    int run(int m, int n)
    {
        vector<vector<int>> table = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        table[1][1] = 1;

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                int current = table[i][j];
                if (j+1 <= n) table[i][j+1] += current;
                if (i+1 <= m) table[i+1][j] += current;
            }
        }

        return table[m][n];
    }
};

#endif