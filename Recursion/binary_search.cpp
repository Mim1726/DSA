
#include <iostream>
#include <vector>
using namespace std;

// Recursive binary search function
int binarySearchRecursive(vector<int>& arr, int start, int end, int target) {
    // Base case: element not found
    if (start > end) {
        return -1;
    }

    // Calculate the middle index
    int mid = start + (end - start) / 2;

    // Check if the middle element is the target
    if (arr[mid] == target) {
        return mid;
    }

    // If the target is smaller, search in the left half
    if (arr[mid] > target) {
        return binarySearchRecursive(arr, start, mid - 1, target);
    }

    // If the target is larger, search in the right half
    return binarySearchRecursive(arr, mid + 1, end, target);
}

int main() {
    // Input: sorted array and the target element
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target;
    cout << "Enter the target element: ";
    cin >> target;

    // Perform binary search
    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target);

    // Output the result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
