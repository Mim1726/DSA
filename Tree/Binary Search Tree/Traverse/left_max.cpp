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
    if(root == nullptr)
        return new node(x);
    if(x < root->val){
        root->left=insert(root->left,x);
    }
    else if(x > root->val){
        root->right=insert(root->right,x);
    }
}
void inorder(node* p){
    if(p == nullptr) return;
    inorder(p->left);
    cout << p->val << " ";
    inorder(p->right);
}
bool find(node* p,int x){
    if(p == nullptr) return false;

    if(p->val == x) return true;

    if(x < p->val){
        return find(p->left,x);
    }
    else{
        return find(p->right,x);
    }
}
node* findmax(node* root){
    while(root->right != nullptr){
        root=root->right;
    }
    return root;
}
node* delete_node(node* root,int x){
    if(root == nullptr) return root;

    if(x < root->val){
        root->left=delete_node(root->left,x);
    }

    else if(x > root->val){
        root->right=delete_node(root->right,x);
    }

    else{
        if(root->left == nullptr){
            node* tmp=root->right;
            delete root;
            return tmp;
        }
        else if(root->right == nullptr){
            node* tmp=root->left;
            delete root;
            return tmp;
        }
        node* tmp=findmax(root->left);
        root->val=tmp->val;
        root->left=delete_node(root->left,tmp->val);
    }
    return root;
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
    int v,q;
    cin >> v >> q;
    cout << find(root,v) << endl;
    cout << find(root,q) << endl;

    root=delete_node(root,v);
    cout << find(root,v) << endl;

    return 0;
}
