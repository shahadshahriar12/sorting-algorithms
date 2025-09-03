#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, int low, int mid, int high)
{
	int nL = mid - low + 1;
	int nR = high - mid;
	vector<int> L(nL + 1);
	vector<int> R(nR + 1);
	
	for(int i = 0; i < nL; i++)
	{
		L[i] = nums[low + i];
	}
	L[nL] = INT_MAX;

	for(int j = 0; j < nR; j++)
	{
		R[j] = nums[mid + 1 + j];
	}
	R[nR] = INT_MAX;

	int i = 0, j = 0;
	for(int k = low; k <= high; k++)
	{
		if(L[i] <= R[j])
		{
			nums[k] = L[i];
			i++;
		}
		else
		{
			nums[k] = R[j];
			j++;
		}
	}


}

void sort(vector<int>& nums, int low, int high)
{
	if(low < high)
	{
		int mid = low + (high - low) / 2;  // avoids overflow of (low + high) / 2;
		sort(nums, low, mid);
		sort(nums, mid + 1, high);
		merge(nums, low, mid, high);
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
Divide the array into two halves.
Recursively sort each half.
Merge the two sorted halves back into a single sorted array.
Uses sentinels (INT_MAX) in temporary arrays to simplify merging logic.

Pseudocode (CLRS style):
MERGE(A, p, q, r)
1  n1 = q - p + 1
2  n2 = r - q
3  let L[1..n1+1], R[1..n2+1] be new arrays
4  for i = 1 to n1
5      L[i] = A[p + i - 1]
6  for j = 1 to n2
7      R[j] = A[q + j]
8  L[n1 + 1] = ∞
9  R[n2 + 1] = ∞
10 i = 1; j = 1
11 for k = p to r
12     if L[i] ≤ R[j]
13         A[k] = L[i]; i = i + 1
14     else
15         A[k] = R[j]; j = j + 1


MERGE-SORT(A, p, r)
1  if p < r
2      q = ⌊(p + r)/2⌋
3      MERGE-SORT(A, p, q)
4      MERGE-SORT(A, q+1, r)
5      MERGE(A, p, q, r)


Complexity & Properties:
Best case: Θ(n log n) — merge step dominates, independent of input order
Worst case: Θ(n log n) — all elements need to be merged at every level
Average case: Θ(n log n)
Space: O(n) — temporary arrays L & R
Stable: ✅ Yes — equal elements retain relative order
In-place: ❌ No — requires extra memory for L & R
*/