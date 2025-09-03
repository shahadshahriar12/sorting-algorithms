#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>
using namespace std;

vector<int> result; //shared vector
mutex mtx; //mutex to protect result

void sleeper(int n)
{
	// sleep for n milliseconds
	this_thread::sleep_for(chrono::milliseconds(n * 100));
	
	lock_guard<mutex> lock(mtx);  // lock before modifying result
    result.push_back(n);          // safely insert
}

void sort(vector<int>& nums)
{
	int min = (int)*(min_element(nums.begin(), nums.end()));
	if (min < 0)
	{
		for(int &x: nums)
		{
			x -= min;
		}
	}

	vector<thread> threads;
	for(int &n: nums)
	{
		threads.emplace_back(sleeper, n);
	}

	for(auto &t: threads)
	{
		t.join();
	}
	
	if (min < 0)
	{
		for(int &x: result)
		{
			x += min;
		}
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
	printArray(result); //sorted list stored in result
}

/*
Algorithm (in words):
For each number in the input array, spawn a separate thread.
Each thread sleeps for a time proportional to its number, then appends it to a shared result list.
After all threads finish, the result list contains the numbers in sorted order.

Pseudocode:
SLEEP-SORT(A)
1  min ← minimum(A)
2  if min < 0:
3      for each x in A:
4          x ← x - min        // offset so all numbers ≥ 0
5
6  for each x in A:
7      spawn thread that:
8          sleep(x * k)       // k = scaling factor
9          append x to result
10
11 for each thread:
12     join()
13
14 if min < 0:
15     for each y in result:
16         y ← y + min        // restore original values


Complexity & Properties:
Best case: O(n) (all threads scheduled instantly, minimal sleep values).
Worst case: O(max(A)) (since one thread must sleep the longest).
Average case: O(max(A)) (dominated by largest number).
Space: O(n) (threads + result array).
Stable: ❌ No (equal numbers can appear in any order, depending on OS scheduling).
In-place: ❌ No (requires extra result vector).
Practicality: 🚫 Not practical; fun/conceptual only. Depends on OS scheduler & hardware.
*/