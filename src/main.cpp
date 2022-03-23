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
#include <CanConstruct.h>
#include <CountConstruct.h>
#include <AllConstruct.h>
#include <FibTab.h>
#include <GridTravellerTab.h>
#include <CanSumTab.h>
#include <HowSumTab.h>
#include <BestSumTab.h>
#include <CanConstructTab.h>
#include <CountConstructTab.h>
#include <AllConstructTab.h>

using namespace std;

// Print the array
void printArray(vector<int> &arr, int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArray(vector<string> &arr, int size) 
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArray(vector<vector<string>> &arr, int size) 
{
    for (int i = 0; i < size; i++)
        printArray(arr[i], arr[i].size());
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

    // Can Construct
    CanConstruct canConstruct;
    map<string, bool> canConstructMemo;
    string canConstructTarget = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> canConstructWordBank({"e", "eeee", "eeeeeee", "eeee", "eee"});
    bool canConstructRes = canConstruct.run(canConstructTarget, canConstructWordBank, canConstructMemo);
    cout << "\n--- Can Construct ---\n\"" << canConstructTarget << "\" with array: ";
    printArray(canConstructWordBank, canConstructWordBank.size());
    if (canConstructRes) cout << "True\n";
    else  cout << "False\n";

    // Count Construct
    CountConstruct countConstruct;
    map<string, int> countConstructMemo;
    string countConstructTarget = "purple";
    vector<string> countConstructWordBank({"purp", "p", "ur", "le", "purpl"});
    int countConstructRes = countConstruct.run(countConstructTarget, countConstructWordBank, countConstructMemo);
    cout << "\n--- Count Construct ---\n\"" << countConstructTarget << "\" with array: ";
    printArray(countConstructWordBank, countConstructWordBank.size());
    cout << "Result: " << countConstructRes << "\n";

    // All Construct
    AllConstruct allConstruct;
    map<string, vector<vector<string>>> allConstructMemo;
    string allConstructTarget = "purple";
    vector<string> allConstructWordBank({"purp", "p", "ur", "le", "purpl"});
    vector<vector<string>> allConstructRes = allConstruct.run(allConstructTarget, allConstructWordBank, allConstructMemo);
    cout << "\n--- All Construct ---\n\"" << allConstructTarget << "\" with array: ";
    printArray(allConstructWordBank, allConstructWordBank.size());
    cout << "Result:\n";
    printArray(allConstructRes, allConstructRes.size());

    // Fibonacci Sequence using Tabulation
    FibTab fibTab;
    int fib_tab_n = 50;
    long long int fib_tab_res = fibTab.run(fib_tab_n);
    cout << "\n--- Fibonacci Tabulation ---\n" << fib_tab_n << " levels = " << fib_tab_res << "\n";

    // Grid Traveller Tabulation
    GridTravellerTab gridTravellerTab;
    int gtt_m = 3, gtt_n = 3;
    int gridTravellerTabRes = gridTravellerTab.run(gtt_m, gtt_n);
    cout << "\n--- Grid Traveller Tabulation ---\n(" << gtt_m << "," << gtt_n << ") = " << gridTravellerTabRes << "\n";

    // Can Sum Tabulation
    CanSumTab canSumTab;
    int canSumTabTargetSum = 300;
    vector<int> canSumTabNums({7, 14});
    bool canSumTabRes = canSumTab.run(canSumTabTargetSum, canSumTabNums);
    cout << "\n--- Can Sum Tabulation ---\n" << canSumTabTargetSum << " with array: ";
    printArray(canSumTabNums, canSumTabNums.size());
    if (canSumTabRes) cout << "True\n";
    else  cout << "False\n";

    // How Sum Tabulation
    HowSumTab howSumTab;
    int howSumTabTargetSum = 100;
    vector<int> howSumTabNums({10, 2, 5, 25});
    vector<int> howSumTabResArr = howSumTab.run(howSumTabTargetSum, howSumTabNums);
    cout << "\n--- How Sum Tabulation ---\n" << howSumTabTargetSum << " with array: ";
    printArray(howSumTabNums, howSumTabNums.size());
    cout << "Result: ";
    printArray(howSumTabResArr, howSumTabResArr.size());

    // Best Sum Tabulation
    BestSumTab bestSumTab;
    int bestSumTabTargetSum = 100;
    vector<int> bestSumTabNums({10, 2, 5, 25});
    vector<int> bestSumTabResArr = bestSumTab.run(bestSumTabTargetSum, bestSumTabNums);
    cout << "\n--- Best Sum ---\n" << bestSumTabTargetSum << " with array: ";
    printArray(bestSumTabNums, bestSumTabNums.size());
    cout << "Result: ";
    printArray(bestSumTabResArr, bestSumTabResArr.size());

    // Can Construct Tabulation
    CanConstructTab canConstructTab;
    string canConstructTabTarget = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
    vector<string> canConstructTabWordBank({"e", "eeee", "eeeeeee", "eeee", "eee"});
    bool canConstructTabRes = canConstructTab.run(canConstructTabTarget, canConstructTabWordBank);
    cout << "\n--- Can Construct Tabulation ---\n\"" << canConstructTabTarget << "\" with array: ";
    printArray(canConstructTabWordBank, canConstructTabWordBank.size());
    if (canConstructTabRes) cout << "True\n";
    else  cout << "False\n";

    // Count Construct Tabulation
    CountConstructTab countConstructTab;
    string countConstructTabTarget = "purple";
    vector<string> countConstructTabWordBank({"purp", "p", "ur", "le", "purpl"});
    int countConstructTabRes = countConstructTab.run(countConstructTabTarget, countConstructTabWordBank);
    cout << "\n--- Count Construct Tabulation ---\n\"" << countConstructTabTarget << "\" with array: ";
    printArray(countConstructTabWordBank, countConstructTabWordBank.size());
    cout << "Result: " << countConstructTabRes << "\n";

    // All Construct
    AllConstructTab allConstructTab;
    string allConstructTabTarget = "abcdef";
    vector<string> allConstructTabWordBank({"ab", "abc", "cd", "def", "abcd", "ef", "c"});
    vector<vector<string>> allConstructTabRes = allConstructTab.run(allConstructTabTarget, allConstructTabWordBank);
    cout << "\n--- All Construct Tabulation ---\n\"" << allConstructTabTarget << "\" with array: ";
    printArray(allConstructTabWordBank, allConstructTabWordBank.size());
    cout << "Result:\n";
    printArray(allConstructTabRes, allConstructTabRes.size());

    return 0;
}