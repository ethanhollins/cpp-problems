#include <iostream>
#include <vector>
#include <MergeSort.h>
#include <LIS.h>

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

    return 0;
}