#include<bits/stdc++.h>
using namespace std;
/*
Let, a binary search tree B has property that all the nodes to the left
of a node have lower values than it and those to the right have higher 
values. You have to build a new tree from B where all the nodes to the
left of a node have higher values and those to the right have lower 
values. Write a C++ code to an efficient algorithm to do so.
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

void reverse_bst(node* root){
    if(!root) return;

    swap(root->left,root->right);

    reverse_bst(root->left);
    reverse_bst(root->right);
}

void inorder(node* p){
    if(p == nullptr) return;
    inorder(p->left);
    cout << p->val << " ";
    inorder(p->right);
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
    inorder(root);
    cout << endl;

    reverse_bst(root);

    inorder(root);
    cout << endl;
}
