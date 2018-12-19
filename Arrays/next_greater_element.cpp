/*
Next Greater Element
Given an array, print the Next Greater Element (NGE) for every element. The Next greater Element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1.

Examples:
a) For any array, rightmost element always has next greater element as -1.
b) For an array which is sorted in decreasing order, all elements have next greater element as -1.
c) For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1

*/



// A Stack based C++ program to find next 
// greater element for all array elements 
// in same order as input. 
#include <bits/stdc++.h> 

using namespace std; 

/* prints element and NGE pair for all 
elements of arr[] of size n */
void printNGE(int arr[], int n) 
{ 
	stack<int> s; 
	unordered_map<int, int> mp; 

	/* push the first element to stack */
	s.push(arr[0]); 
	

	// iterate for rest of the elements 
	for (int i = 1; i < n; i++) { 

		if (s.empty()) { 
			s.push(arr[i]); 
			continue; 
		} 

		/* if stack is not empty, then 
	pop an element from stack. 
	If the popped element is smaller 
	than next, then 
	a) print the pair 
	b) keep popping while elements are 
	smaller and stack is not empty */
		while (s.empty() == false && s.top() < arr[i]) { 
			mp[s.top()] = arr[i]; 
			s.pop(); 
		} 

		/* push next to stack so that we can find 
	next smaller for it */
		s.push(arr[i]); 
	} 

	/* After iterating over the loop, the remaining 
elements in stack do not have the next smaller 
element, so print -1 for them */
	while (s.empty() == false) { 
		mp[s.top()] = -1; 
		s.pop(); 
	} 

	for (int i=0; i<n; i++) 
	cout << arr[i] << " ---> " << mp[arr[i]] << endl; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = { 11, 13, 21, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printNGE(arr, n); 
	return 0; 
} 
