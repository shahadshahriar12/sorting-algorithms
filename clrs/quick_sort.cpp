#include <iostream>
#include <vector>
#include <random>
using namespace std;

int partition(vector<int>& nums, int low, int high)
{
	int i = low + rand() % (high - low + 1); //choose random pivot index
	swap(nums[i], nums[high]); //move pivot to end
	int x = nums[high]; //pivot
	i = low - 1; //will keep track of the last element of the partition of elements less than pivot
	for(int j = low; j < high; j++)
	{
		if(nums[j] <= x)
		{
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i+1], nums[high]); //place pivot in correct position
	return i + 1;
}

void sort(vector<int>& nums, int low, int high)
{
	if(low < high)
	{
		int pivot_idx = partition(nums, low, high);
		sort(nums, low, pivot_idx - 1);
		sort(nums, pivot_idx + 1, high);
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
	sort(test, 0, test.size() - 1);
	cout<<"After Sorting: "<<endl;
	printArray(test);
}

/*
Algorithm (in words):
If the array has more than one element:
Pick a random pivot.
Partition the array: elements ≤ pivot left, elements > pivot right.
Recursively sort the left and right subarrays.
The array becomes fully sorted.

Pseudocode (CLRS style):
RANDOMIZED-QUICKSORT(A, p, r)
1  if p < r
2      q = RANDOMIZED-PARTITION(A, p, r)
3      RANDOMIZED-QUICKSORT(A, p, q-1)
4      RANDOMIZED-QUICKSORT(A, q+1, r)

RANDOMIZED-PARTITION(A, p, r)
1  i = RANDOM(p, r)             // choose a random pivot index
2  exchange A[i] with A[r]      // move pivot to end
3  x = A[r]                      // pivot
4  i = p - 1
5  for j = p to r - 1
6      if A[j] ≤ x
7          i = i + 1
8          exchange A[i] with A[j]
9  exchange A[i + 1] with A[r]  // place pivot in correct position
10 return i + 1


Complexity & Properties:
Best case: Θ(n log n) — random pivot splits array roughly in half
Average case: Θ(n log n)
Worst case: Θ(n²) — very unlikely with random pivot
Space: O(log n) — recursion stack
Stable: ❌ No — swapping can change relative order of equal elements
In-place: ✅ Yes — sorts inside original array
*/