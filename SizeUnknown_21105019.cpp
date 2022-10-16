#include <iostream>
using namespace std;

// CREATING THE FUNCTION SUCH THAT WE ARE NOT PASSING THE SIZE OF THE ARRAY TO THE FUNCTION.

// LINEAR SEARCH

// in linear search we are traversing the array, and not keeping any limitation on the traversing index(i).
int linear_search(int arr[], int x)
{
    for (int i = 0;; i++) // no condition to stop the loop until the element not found.
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
}

// BINARY SEARCH

//this function is a simple binary search function where left and right indexes are being provided.

int binary_search_code(int arr[], int x, int low, int high) {
  
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

//we need to reduce our work done to O(log(N)) time complexity. Initially in Binary search, we apply the search considering the entire length of the array. So , in order to decrease the time complexity by increasing the range of our search exponentially by 2 . This way if we get the desired element initially  we won't have to check the elements aheaad of it.

int binary_search(int arr[], int x)
{
    int low = 0;
    int high = 1;

    while (arr[high] < x)//if element to be found is still high the value at high index .
    {
        low = high;//update the low value
        high = 2 * high;//double the range of search, when the condition is satisfied then we call BINARY SEARCH on that range(low to high).
    }

    return binary_search_code(arr,low,high,x);
}


/*
NOTE - We are creating an array, but the size of the array is not passed to the function.
*/
int main()
{
    // you are given the starting index of the array.
    int *arr = new int[10000];
    int n;
    cout << "Number of elements in an array: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "ENTER THE ELEMENT TO SEARCH FOR: ";
    cin >> x;
    cout << endl;

    cout << "Index of " << x << " from LINEAR SEARCH is : " << linear_search(arr, x) << endl;
    cout << "Index of " << x << " from BINARY SEARCH is : " << binary_search(arr, x) << endl;
}