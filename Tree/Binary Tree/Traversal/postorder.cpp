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

    void insertion(int x){
        node* a=new node();
        a->val=x;
        a->left=NULL;
        a->right=NULL;
        a->parent=NULL;

        if(!root){
            root=a;
            return;
        }

        queue<node*> q;
        q.push(root);

        while(!q.empty()){
            node* curr=q.front();
            q.pop();

            if(!curr->left){
                curr->left=a;
                a->parent=curr;
                return;
            }
            else{
                q.push(curr->left);
            }

            if(!curr->right){
                curr->right=a;
                a->parent=curr;
                return;
            }
            else{
                q.push(curr->right);
            }
        }
    }
    void postorder(node* p){
        if(!p) return;
        postorder(p->left);
        postorder(p->right);
        cout << p->val << " ";
    }
};
int main(){
    tree my_tree;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        my_tree.insertion(x);
    }
    my_tree.postorder(my_tree.root);
    return 0;
}
