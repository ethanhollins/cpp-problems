#ifndef LIS_H
#define LIS_H

#include <iostream>
#include <vector>

using namespace std;

class LIS
{
public:
    int run(vector<int> arr)
    {
        vector<int> L(arr.size(), 1);
        int max_seq = 1;

        for (int i = 1; i < L.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && L[j]+1 > L[i])
                {
                    L[i] = L[j] + 1;
                    if (L[i] > max_seq)
                        max_seq = L[i];
                }
            }
        }
        return max_seq;
    }
};

#endif