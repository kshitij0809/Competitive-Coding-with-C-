/*

Maximum difference between two elements such that larger element appears after the smaller number
Given an array arr[] of integers, find out the maximum difference between any two elements such that larger element appears after the smaller number.
Examples :

Input : arr = {2, 3, 10, 6, 4, 8, 1}
Output : 8
Explanation : The maximum difference is between 10 and 2.

Input : arr = {7, 9, 5, 6, 3, 2}
Output : 2
Explanation : The maximum difference is between 9 and 7.


*/

// C++ program to find Maximum difference 
// between two elements such that larger 
// element appears after the smaller number 
#include <bits/stdc++.h> 
using namespace std; 

/* The function assumes that there are 
at least two elements in array. The 
function returns a negative value if the 
array is sorted in decreasing order and 
returns 0 if elements are equal */
int maxDiff(int arr[], int arr_size) 
{	 
int max_diff = arr[1] - arr[0]; 
for (int i = 0; i < arr_size; i++) 
{ 
	for (int j = i+1; j < arr_size; j++) 
	{	 
	if (arr[j] - arr[i] > max_diff) 
		max_diff = arr[j] - arr[i]; 
	} 
}		 
return max_diff; 
} 

/* Driver program to test above function */
int main() 
{ 
int arr[] = {1, 2, 90, 10, 110}; 
int n = sizeof(arr) / sizeof(arr[0]); 
	
// Function calling 
cout << "Maximum difference is " << maxDiff(arr, n); 

return 0; 
} 
