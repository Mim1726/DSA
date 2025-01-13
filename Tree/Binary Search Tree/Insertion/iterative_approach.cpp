#include<bits/stdc++.h>
using namespace std;

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
    node* tmp=new node(x);

    if(root == nullptr){
        return tmp;
    }
    node* parent=nullptr;
    node* curr=root;

    while(curr != nullptr){
        parent=curr;
        if(x < curr->val){
            curr=curr->left;
        }
        else if(x > curr->val){
            curr=curr->right;
        }
        else
            return root;
    }
    if(parent->val > x){
        parent->left=tmp;
    }
    else{
        parent->right=tmp;
    }
    return root;
}
void inorder(node* root){
    if(root != nullptr){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
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
}
