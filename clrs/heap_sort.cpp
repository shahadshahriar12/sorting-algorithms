#include <iostream>
#include <vector>
using namespace std;

// Max Heapify
void heapify(vector<int>& nums, int n, int i)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	int largest = i;

	if(l < n && nums[l] > nums[largest]) largest = l;
	if(r < n && nums[r] > nums[largest]) largest = r;

	if(largest != i)
	{
		swap(nums[i], nums[largest]);
		heapify(nums, n, largest);
	}
}

void sort(vector<int>& nums)
{
	int n = nums.size();

	// Build Max Heap
	for(int i = n/2 - 1; i >= 0; i--)
	{
		heapify(nums, n, i);
	}

	// Extract elements from heap
	for(int i = n - 1; i >= 1; i--)
	{
		swap(nums[0], nums[i]);
		heapify(nums, i, 0);
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
Build a max-heap from the input array.
Repeatedly extract the maximum element (root of the heap) and swap it to the end.
Reduce heap size by one and heapify the root to maintain the max-heap property.
Repeat until all elements are extracted → array is sorted.

Pseudocode:
HEAPSORT(A)
1  BUILD-MAX-HEAP(A)
2  for i = A.length - 1 downto 1
3      exchange A[0] with A[i]
4      heap-size = heap-size - 1
5      MAX-HEAPIFY(A, 0)

BUILD-MAX-HEAP(A)
1  heap-size = A.length
2  for i = (A.length/2) - 1 downto 0
3      MAX-HEAPIFY(A, i)

MAX-HEAPIFY(A, i)
1  l = 2*i + 1
2  r = 2*i + 2
3  largest = i
4  if l < heap-size and A[l] > A[largest]
5      largest = l
6  if r < heap-size and A[r] > A[largest]
7      largest = r
8  if largest ≠ i
9      exchange A[i] with A[largest]
10     MAX-HEAPIFY(largest)

Complexity & Properties:

Best case: Θ(n log n) — building the heap and heapify dominate
Worst case: Θ(n log n)
Average case: Θ(n log n)
Space: O(1) — in-place
Stable: ❌ No — swapping changes relative order of equal elements
In-place: ✅ Yes — sorts inside original array
*/