#include <bits/stdc++.h>
using namespace std;
/*
You are given a binary search tree, each node containing an integer,
in which all internal nodes have two children and all leaves are in 
the same depth. Write the pseudocode of an efficient algorithm to find 
the median of the values stored in the binary search tree. Note that 
the median is the middle value in a set of data.               
*/

struct node {
    int val;
    node* left;
    node* right;
    node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a value into the BST
node* insert(node* root, int x) {
    if (root == nullptr)
        return new node(x);
    if (x < root->val) {
        root->left = insert(root->left, x);
    } else if (x > root->val) {
        root->right = insert(root->right, x);
    }
    return root;
}

// Function to find the size of the BST
int countNodes(node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function to find the kth smallest element in the BST
void findKthElement(node* root, int& k, int& result) {
    if (root == nullptr) return;

    findKthElement(root->left, k, result); // Visit left subtree

    k--; // Decrement k for the current node
    if (k == 0) {
        result = root->val; // If k is 0, we found the kth element
        return;
    }

    findKthElement(root->right, k, result); // Visit right subtree
}

// Function to find the median
double findMedian(node* root) {
    int n = countNodes(root); // Total number of nodes in the BST

    if (n % 2 == 1) {
        // For odd number of nodes, the median is the middle element
        int k = (n + 1) / 2;
        int result = -1;
        findKthElement(root, k, result);
        return result;
    } else {
        // For even number of nodes, the median is the average of two middle elements
        int k1 = n / 2;
        int k2 = k1 + 1;
        int result1 = -1, result2 = -1;
        findKthElement(root, k1, result1);
        findKthElement(root, k2, result2);
        return (result1 + result2) / 2.0;
    }
}

int main() {
    node* root = nullptr;
    int n;
    cin >> n;

    // Insert elements into the BST
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    // Find and print the median
    cout << fixed << setprecision(1) << findMedian(root) << endl;

    return 0;
}
