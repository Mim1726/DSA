#include<bits/stdc++.h>
using namespace std;
struct tree{
    struct node{
        int val;
        node* left;
        node* right;
        node* parent;
    };
    node* root=NULL;
    void insert_1(int x){
        node* a=new node();
        a->val=x;
        a->left=NULL;
        a->right=NULL;
        a->parent=NULL;
        if(root){
            insert_2(root,a);
        }
        else{
            root=a;
        }
    }

    void insert_2(node* p,node* a){
        if(p->val >= a->val && p->left == NULL){
            p->left=a;
            a->parent=p;
        }
        else if(p->val < a->val && p->right == NULL){
            p->right=a;
            a->parent=p;
        }
        else if(p->val >= a->val){
            insert_2(p->left,a);
        }
        else{
            insert_2(p->right,a);
        }
    }
    void inorder(node* p){
        if(!p) return;
        inorder(p->left);
        cout << p->val << " ";
        inorder(p->right);
    }
};
int main(){
    tree my_tree;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        my_tree.insert_1(x);
    }
    my_tree.inorder(my_tree.root);
    return 0;
}
