#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <chrono>
#include <algorithm>

using namespace std;

class Timer {
public:
	Timer() :
		moment_begin(chrono::steady_clock::now()), moment_rest(0) {}
	void pause() {
		auto end = chrono::steady_clock::now();
		moment_rest = chrono::duration_cast <chrono::microseconds> (end - moment_begin);
	}

	void restart() {
		moment_begin = chrono::steady_clock::now();
	}
	~Timer() {
		auto end = chrono::steady_clock::now();
		no_pause_before_end = true;
		if (no_pause_before_end) {
			moment_rest = moment_rest + chrono::duration_cast <chrono::microseconds> (end - moment_begin);

		}
		cout << "      " << moment_rest.count() <<  "      ";
	}


private:
	chrono::steady_clock::time_point moment_begin;
	chrono::microseconds moment_rest;
	bool no_pause_before_end = false;
};


int main() {
	vector<int> v1(10, 6);
	array<int, 10> arr1 = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
	deque<int> d1(10, 6);
	list<int> list1 = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };
	forward_list<int> f_list1 = { 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 };


	vector<int> v2 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	array<int, 10> arr2 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	deque<int> d2 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	list<int> list2 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	forward_list<int> f_list2 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };

	vector<int> v3 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67,  9, 8, 5, 4, 3, 60987, -123, 0, 0, 67, 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67};
	array<int, 30> arr3 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67, 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67, 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	deque<int> d3 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67,  9, 8, 5, 4, 3, 60987, -123, 0, 0, 67, 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	list<int> list3 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67,  9, 8, 5, 4, 3, 60987, -123, 0, 0, 67, 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	forward_list<int> f_list3 = { 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67,  9, 8, 5, 4, 3, 60987, -123, 0, 0, 67, 9, 8, 5, 4, 3, 60987, -123, 0, 0, 67 };
	
	cout << "vector sort || array sort || deque sort || list self-sort || forward list self-sort" << endl;;
	{Timer time;
	sort(begin(v1), end(v1), greater<int>());	}
	{Timer time;
	sort(begin(arr1), end(arr1), greater<int>()); }
	{Timer time;
	sort(begin(d1), end(d1), greater<int>()); }
	{Timer time;
	list1.sort(); }
	{Timer time;
	f_list1.sort(); }
	cout << endl;

	{Timer time;
	sort(begin(v2), end(v2), greater<int>());
	}
	{Timer time;
	sort(begin(arr2), end(arr2), greater<int>());; }
	{Timer time;
	sort(begin(d2), end(d2), greater<int>());}
	{Timer time;
	list2.sort(); }
	{Timer time;
	f_list2.sort(); }
	cout << endl;

	{Timer time;
	sort(begin(v3), end(v3), greater<int>());
	}
	{Timer time;
	sort(begin(arr3), end(arr3), greater<int>()); }
	{Timer time;
	sort(begin(d3), end(d3), greater<int>());}
	{Timer time;
	list3.sort(); }
	{Timer time;
	f_list3.sort(); }
	cout << endl;
	cout << endl;

	{Timer time;
	sort(begin(v1), end(v1), greater<int>());	}
	{Timer time;
	sort(begin(arr1), end(arr1), greater<int>()); }
	{Timer time;
	sort(begin(d1), end(d1), greater<int>()); }
	{Timer time;
	list1.sort(); }
	{Timer time;
	f_list1.sort(); }
	cout << endl;

	{Timer time;
	sort(begin(v2), end(v2), greater<int>());
	}
	{Timer time;
	sort(begin(arr2), end(arr2), greater<int>());; }
	{Timer time;
	sort(begin(d2), end(d2), greater<int>()); }
	{Timer time;
	list2.sort(); }
	{Timer time;
	f_list2.sort(); }
	cout << endl;

	{Timer time;
	sort(begin(v3), end(v3), greater<int>());
	}
	{Timer time;
	sort(begin(arr3), end(arr3), greater<int>()); }
	{Timer time;
	sort(begin(d3), end(d3), greater<int>()); }
	{Timer time;
	list3.sort(); }
	{Timer time;
	f_list3.sort(); }
	cout << endl;
	
	return 0;
}