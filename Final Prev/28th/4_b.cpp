#include<bits/stdc++.h>
using namespace std;

/*
Write a C++ code to traverse a binary search tree such that the 
generated output is in descending order.
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
void traverse(node* curr){
    if(curr == nullptr)
        return;
    traverse(curr->right);
    cout << curr->val << " ";
    traverse(curr->left);
}

int main(){
    node* root=nullptr;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        root=insert(root,x);
    }
    traverse(root);
}
