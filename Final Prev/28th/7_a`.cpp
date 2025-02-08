#include <bits/stdc++.h>
using namespace std;

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

// Insert into BST
node* insert(node* root, int x) {
    if (root == nullptr) {
        return new node(x);
    }
    if (x < root->val) {
        root->left = insert(root->left, x);
    } else if (x > root->val) {
        root->right = insert(root->right, x);
    }
    return root;
}

// Inorder traversal (stores elements in sorted order)
void inorder(node* root, vector<int>& arr) {
    if (root == nullptr) return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

// Merge two sorted arrays
vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
        else merged.push_back(arr2[j++]);
    }
    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);
    return merged;
}

// Build balanced BST from sorted array
node* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    node* root = new node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

// Merge two BSTs
node* merge_bst(node* root1, node* root2) {
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);

    vector<int> mergedArr = mergeArrays(arr1, arr2);
    return sortedArrayToBST(mergedArr, 0, mergedArr.size() - 1);
}

// Inorder traversal (print BST in sorted order)
void inorderPrint(node* root) {
    if (root == nullptr) return;
    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {
    node* root1 = nullptr;
    int n1;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        root1 = insert(root1, x);
    }

    node* root2 = nullptr;
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        root2 = insert(root2, x);
    }

    cout << "root1: ";
    inorderPrint(root1);
    cout << endl;

    cout << "root2: ";
    inorderPrint(root2);
    cout << endl;

    node* merged_bst = merge_bst(root1, root2);
    cout << "merged bst: ";
    inorderPrint(merged_bst);
    cout << endl;
}
