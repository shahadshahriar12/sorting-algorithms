#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
		bool swapped = false;
		for(int j = 0; j < nums.size() - 1 - i; j++)
		{
			if(nums[j+1] < nums[j])
			{
				swap(nums[j+1], nums[j]);
				swapped = true;
			}
		}
		if(!swapped) break;
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
Bubble Sort repeatedly steps through the array,
compares adjacent elements, and swaps them if they are in the wrong order.
After each pass, the largest unsorted element "bubbles up"
to its correct position at the end.
The process repeats until the array is sorted.
Optimization: if no swaps happen in a pass, the algorithm stops early.

Pseudocode:
BUBBLE-SORT(A)
1  for i = 0 to A.length - 1
2      swapped = false
3      for j = 0 to A.length - i - 2
4          if A[j] > A[j+1]
5              exchange A[j] with A[j+1]
6              swapped = true
7      if swapped == false
8          break

Complexity & Properties:
Best case: Θ(n) (already sorted, only one pass needed with no swaps).
Worst case: Θ(n²) (reverse sorted, maximum swaps).
Average case: Θ(n²).
Space: O(1).
Stable: ✅ Yes (equal elements retain relative order, only adjacent swaps).
In-place: ✅ Yes (works inside the original array).
*/