#include <iostream>
#include <vector>
using namespace std;

void sort(vector<int>& nums)
{
	for(int i = 1; i < nums.size(); i++)
	{
		int key = nums[i];

		int j = i - 1;
		while(j >= 0 && key < nums[j])
		{
			nums[j+1] = nums[j];
			j--;
		}
		nums[j+1] = key;
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
Start with the second element (since a single element is trivially sorted).
Take this element (call it key) and compare it with the elements before it.
Shift all larger elements one position to the right.
Insert the key into its correct position.
Repeat for all elements in the array.

Pseudocode:
INSERTION-SORT(A)
1  for j = 2 to A.length
2      key = A[j]
3      // Insert A[j] into the sorted sequence A[1..j-1]
4      i = j - 1
5      while i > 0 and A[i] > key
6          A[i + 1] = A[i]
7          i = i - 1
8      A[i + 1] = key

Complexity & Properties:
Best case: Θ(n) (already sorted input).
Worst case: Θ(n²) (reverse sorted).
Average case: Θ(n²).
Space: O(1).
Stable: ✅ Yes. (Stability means if two elements are equal, they stay in the same relative order)
In-place: ✅ Yes. (No extra arrays, just swapping/shifting within the original array)
*/
