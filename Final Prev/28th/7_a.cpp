#include<bits/stdc++.h>
using namespace std;
/*
Given two binary search trees, each node containing an integer, having
no element in common, write a C++ code of an efficient algorithm that 
merges the trees into a combined binary search tree containing elememts 
from both trees.    
*/
struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};
node* insert(node* root,int x){
    if(root == nullptr){
        return new node(x);
    }
    if(x < root->val){
        root->left=insert(root->left,x);
    }
    else if(x > root->val){
        root->right=insert(root->right,x);
    }
    return root;
}
void inorder(node* curr){
    if(curr == nullptr)
        return;
    inorder(curr->left);
    cout << curr->val << " ";
    inorder(curr->right);
}
node* merge_bst(node* root1,node* root2){
    if(!root1) return root2;
    if(!root2) return root1;

    if(root2){
        root1=insert(root1,root2->val);
        root1=merge_bst(root1,root2->left);
        root1=merge_bst(root1,root2->right);
    }
    return root1;
}
int main(){
    node* root1=nullptr;
    int n1;
    cin >> n1;
    for(int i=0;i<n1;i++){
        int x;
        cin >> x;
        root1=insert(root1,x);
    }

    node* root2=nullptr;
    int n2;
    cin >> n2;
    for(int i=0;i<n2;i++){
        int x;
        cin >> x;
        root2=insert(root2,x);
    }
    cout << "root1: ";
    inorder(root1);
    cout << endl;

    cout << "root2: ";
    inorder(root2);
    cout << endl;

    node* merged_bst=merge_bst(root1,root2);
    cout << "merged bst: ";
    inorder(merged_bst);
    cout << endl;
}
