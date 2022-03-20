#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <MergeSort.h>
#include <LIS.h>
#include <Fib.h>
#include <GridTraveller.h>
#include <CanSum.h>
#include <HowSum.h>
#include <BestSum.h>

using namespace std;

// Print the array
void printArray(vector<int> &arr, int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}



int main()
{
    // Merge Sort
    MergeSort mergeSort;
    vector<int> mergeSortArr = vector<int>({6, 5, 12, 10, 9, 1});
    mergeSort.run(mergeSortArr);
    cout << "--- Merge Sort ---\nSorted array:\n";
    printArray(mergeSortArr, mergeSortArr.size());

    // Longest Increasing Subsequence
    LIS lis;
    int max_seq = lis.run(vector<int>({5,2,8,6,3,6,9,5}));
    cout << "\n--- LIS ---\nMax Sequence: \n" << max_seq << "\n";

    // Fibonacci Sequence
    Fib fib;
    map<long long int, long long int> fib_memo;
    fib_memo.insert(pair<long long int, long long int>(1,1));
    fib_memo.insert(pair<long long int, long long int>(2,1));
    int fib_n = 50;
    long long int fib_res = fib.run(fib_n, fib_memo);
    cout << "\n--- Fibonacci ---\n" << fib_n << " levels = " << fib_res << "\n";

    // Grid Traveller
    GridTraveller gt;
    map<string, long long int> gt_memo;
    int gt_m = 15, gt_n = 15;
    long long int gt_res = gt.run(gt_m, gt_n, gt_memo);
    cout << "\n--- Grid Traveller ---\n(" << gt_m << "," << gt_n << ") = " << gt_res << "\n";

    // Can Sum
    CanSum canSum;
    map<int, bool> canSumMemo;
    int canSumTargetSum = 300;
    vector<int> canSumNums({7, 14});
    bool canSumRes = canSum.run(canSumTargetSum, canSumNums, canSumMemo);
    cout << "\n--- Can Sum ---\n" << canSumTargetSum << " with array: ";
    printArray(canSumNums, canSumNums.size());
    if (canSumRes) cout << "True\n";
    else  cout << "False\n";

    // How Sum
    HowSum howSum;
    map<int, vector<int>> howSumMemo;
    int howSumTargetSum = 100;
    vector<int> howSumNums({10, 2, 5, 25});
    vector<int> howSumResArr = howSum.run(howSumTargetSum, howSumNums, howSumMemo);
    cout << "\n--- How Sum ---\n" << howSumTargetSum << " with array: ";
    printArray(howSumNums, howSumNums.size());
    cout << "Result: ";
    printArray(howSumResArr, howSumResArr.size());

    // Best Sum
    BestSum bestSum;
    map<int, vector<int>> bestSumMemo;
    int bestSumTargetSum = 100;
    vector<int> bestSumNums({10, 2, 5, 25});
    vector<int> bestSumResArr = bestSum.run(bestSumTargetSum, bestSumNums, bestSumMemo);
    cout << "\n--- Best Sum ---\n" << bestSumTargetSum << " with array: ";
    printArray(bestSumNums, bestSumNums.size());
    cout << "Result: ";
    printArray(bestSumResArr, bestSumResArr.size());

    return 0;
}