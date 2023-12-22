// C++ program to implement 
// the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Comparator 
// we can use class also but then 
// we will need to make the function 
// public as class is by default 
// private 
struct myComparator 
{ 
int operator()(const tuple<int, int, 
				string>& tuple1, 
				const tuple<int, int, 
				string>& tuple2) 
{ 
	// Second element of tuples is equal 
	if (get<1>(tuple1) == get<1>(tuple2)) 
	{ 
	if (get<0>(tuple1) == get<0>(tuple2)) 
	{ 
		if (get<2>(tuple1) >= get<2>(tuple2)) 
		return true; 
		return false; 
	} 

	return get<0>(tuple1) >= get<0>(tuple2); 
	} 

	return get<1>(tuple1) >= get<1>(tuple2); 
} 
}; 

// Function to print priority queue 
// contents. Deliberately passing it 
// call by value since we don't want 
// to remove elements from the priority 
// queue 
void print(priority_queue<tuple<int, int, 
		string>, 
		vector<tuple<int, int, 
		string> >, 
		myComparator> 
		priorityQueue) 
{ 
while (!priorityQueue.empty()) 
{ 
	// Each element of the priority 
	// queue is a tuple itself 
	tuple<int, int, string> Tuple = 
		priorityQueue.top(); 

	cout << "[ "; 

	cout << get<0>(Tuple) << ' ' << 
			get<1>(Tuple) << ' ' << 
			get<2>(Tuple); 
	cout << ']'; 
	cout << '\n'; 

	// Pop out the topmost tuple 
	priorityQueue.pop(); 
} 
} 

// Driver code 
int main() 
{ 
// Declaring a priority queue 
// of tuple 
priority_queue<tuple<int, int, string>, 
vector<tuple<int, int, string> >, 
myComparator> priorityQueue; 

// Declaring a tuple 
tuple<int, int, string> tuple1; 

// Initializing the tuple 
tuple1 = make_tuple(0, 0, 
					"Geeks"); 

// Pushing the tuple in the 
// priority queue 
priorityQueue.push(tuple1); 

// Declaring a tuple 
tuple<int, int, string> tuple2; 

// Initializing the tuple 
tuple2 = make_tuple(0, 1, 
					"Programming"); 

// Pushing the tuple in the 
// priority queue 
priorityQueue.push(tuple2); 

// Declaring a tuple 
tuple<int, int, string> tuple3; 

// Initializing the tuple 
tuple3 = make_tuple(1, 2, 
					"Geeks"); 

// Pushing the tuple in the 
// priority queue 
priorityQueue.push(tuple3); 

// Declaring a tuple 
tuple<int, int, string> tuple4; 

// Initializing the tuple 
tuple4 = make_tuple(1, 3, 
					"Programming"); 

// Pushing the tuple in the 
// priority queue 
priorityQueue.push(tuple4); 

// Calling print function 
print(priorityQueue); 

return 0; 
}
