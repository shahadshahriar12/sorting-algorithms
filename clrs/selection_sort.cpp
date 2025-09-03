#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& nums)
{
	for(int i = 0; i < nums.size() - 1; i++)
	{
		int min_index = i;
		for(int j = i + 1; j < nums.size(); j++)
		{
			if(nums[j] < nums[min_index])
			{			
				min_index = j;
			}
		}
		swap(nums[i], nums[min_index]);
	}
}

void printArray(const vector<int>& array)
{
    cout << "[";
    for (int i = 0; i < array.size(); i++)
    {
        cout << " " << array[i];
        if (i != array.size() - 1)
            cout << ",";
    }
    cout << " ]" << endl;
}

int main()
{
	vector<int> test = {3, 7, 0, 4, 7, -8, 10};
	cout<<"Before Sorting: "<<endl;
	printArray(test);
	sort(test);
	cout<<"After Sorting: "<<endl;
	printArray(test);
}

/*
Algorithm (in words):
Divide the array into sorted prefix (left) and unsorted suffix (right).
For each position i in the array:
Find the index of the minimum element in the unsorted part (A[i..n]).
Swap it with A[i].
Repeat until the entire array is sorted.

Pseudocode:
SELECTION-SORT(A)
1  for i = 1 to A.length - 1
2      min_index = i
3      for j = i + 1 to A.length
4          if A[j] < A[min_index]
5              min_index = j
6      exchange A[i] with A[min_index]


Complexity & Properties:
Best case: Θ(n²) (always scans the entire unsorted portion to find the minimum, even if the array is already sorted).
Worst case: Θ(n²) (reverse sorted input, maximum swaps needed).
Average case: Θ(n²).
Space: O(1).
Stable: ❌ No. (swapping may change the relative order of equal elements)
In-place: ✅ Yes. (No extra arrays, just swapping within the original array.)

*/