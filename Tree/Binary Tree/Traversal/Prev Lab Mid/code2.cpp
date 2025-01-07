#include <iostream>
#include <unordered_map>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Function to build the tree
TreeNode* buildTree(int rootValue, int n, vector<tuple<int, int, int>> operations) {
    unordered_map<int, TreeNode*> nodeMap;
    TreeNode* root = new TreeNode(rootValue);
    nodeMap[rootValue] = root;

    for (auto [op, key, val] : operations) {
        if (nodeMap.find(key) != nodeMap.end()) {
            TreeNode* parent = nodeMap[key];
            TreeNode* child = new TreeNode(val);
            nodeMap[val] = child;
            if (op == 0) {
                parent->left = child;
            } else if (op == 1) {
                parent->right = child;
            }
        }
    }
    return root;
}

// Function to compare two trees
bool areEqual(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;        // Both nodes are null
    if (!t1 || !t2) return false;      // One node is null, the other is not
    if (t1->val != t2->val) return false; // Values of nodes are different
    return areEqual(t1->left, t2->left) && areEqual(t1->right, t2->right); // Recursively check left and right subtrees
}

int main() {
    // Input for the first tree
    int r1, n1;
    cin >> r1 >> n1;
    vector<tuple<int, int, int>> operations1(n1);
    for (int i = 0; i < n1; ++i) {
        int op, key, val;
        cin >> op >> key >> val;
        operations1[i] = make_tuple(op, key, val);
    }

    // Input for the second tree
    int r2, n2;
    cin >> r2 >> n2;
    vector<tuple<int, int, int>> operations2(n2);
    for (int i = 0; i < n2; ++i) {
        int op, key, val;
        cin >> op >> key >> val;
        operations2[i] = make_tuple(op, key, val);
    }

    // Build the two trees
    TreeNode* tree1 = buildTree(r1, n1, operations1);
    TreeNode* tree2 = buildTree(r2, n2, operations2);

    // Compare the trees and output the result
    cout << (areEqual(tree1, tree2) ? 1 : 0) << endl;

    return 0;
}
