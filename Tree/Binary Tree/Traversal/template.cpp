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
    node* a=new node(x);
    if(root == nullptr){
        return a;
    }
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* curr=q.front();
        q.pop();

        if(curr->left == nullptr){
            curr->left=a;
            return root;
        }
        else{
            q.push(curr->left);
        }

        if(curr->right == nullptr){
            curr->right=a;
            return root;
        }
        else{
            q.push(curr->right);
        }
    }
    return root;
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
}
