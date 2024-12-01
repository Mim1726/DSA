#include <iostream>
#include <vector>
using namespace std;

/*You are given a sorted array of numbers and a number k as input. Write down an efficient
a C++ code for finding the largest number in the array that is smaller than k. Mention the
runtime and space complexity of your algorithm.*/

int findLargestSmallerThanKRecursive(const vector<int>& arr, int left, int right, int k, int result = -1) {
    // Base case: when the search space is empty
    if (left > right) {
        return result;
    }

    // Calculate mid-point
    int mid = left + (right - left) / 2;

    // If the current element is smaller than k, it's a candidate
    if (arr[mid] < k) {
        result = arr[mid]; // Update result
        // Search in the right half for potentially larger candidates
        return findLargestSmallerThanKRecursive(arr, mid + 1, right, k, result);
    } else {
        // Otherwise, search in the left half
        return findLargestSmallerThanKRecursive(arr, left, mid - 1, k, result);
    }
}

int main() {
    // Example input: sorted array and the number k
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Find the largest number smaller than k using recursion
    int result = findLargestSmallerThanKRecursive(arr, 0, arr.size() - 1, k);

    if (result != -1) {
        cout << "The largest number smaller than " << k << " is: " << result << endl;
    } else {
        cout << "No number smaller than " << k << " exists in the array." << endl;
    }

    return 0;
}

